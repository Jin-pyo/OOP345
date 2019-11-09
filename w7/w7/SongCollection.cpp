#include "SongCollection.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<algorithm>
#include<vector>
#include<list>
#include <numeric> 

namespace sdds
{
	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
		int second;
		second = theSong.m_length % 60;
		out << "| " << std::setw(20) << std::left << theSong.m_title
			<< " | " << std::setw(15) << std::left << theSong.m_artist
			<< " | " << std::setw(20) << std::left << theSong.m_album
			<< " | " << std::setw(6) << std::right;
		if (theSong.m_year != 0)
			out << theSong.m_year;
		else
			out << "";
		out << " | " << theSong.m_length / 60 << ":";

		if (second < 10)
		{
			out << "0";
		}
		out<<second
		<<" | " << theSong.m_price<<" | ";

		return out;
	}
	std::string& SongCollection::trim(std::string& check)
	{
		while (check.length() > 0 && check[0] == ' ')
			check.erase(0, 1);
		while (check.length() > 0 && check[check.length() - 1] == ' ')
			check.erase(check.length() - 1, 1);

		return check;
	}
		
	SongCollection::SongCollection(std::string filename)
	{
		std::ifstream file(filename);
		if (!file)
		{
			std::cout << "Can not open the file" << std::endl;
		}
		else
		{
			while (file)
			{
				Song song;
				std::string tmp;
				std::getline(file, tmp);
				if (file)
				{
					trim(song.m_title = tmp.substr(0, 25));
					trim(song.m_artist = tmp.substr(25, 25));
					trim(song.m_album = tmp.substr(50, 25));
					try {
						song.m_year = std::stoi(tmp.substr(75, 5));
					}
					catch (...)
					{
						song.m_year = 0;
					}
					song.m_length = std::stoi(tmp.substr(80, 5));
					song.m_price = std::stod(tmp.substr(85));
					
					m_songs.push_back(song);
				}
			}
			file.close();
		}
	}
	void SongCollection::display(std::ostream& out) const
	{
		for_each(m_songs.begin(), m_songs.end(), [&out](const Song& list)
			{
				out << list << std::endl;
			});
	
		
		auto sum = std::accumulate(m_songs.begin(), m_songs.end(), 0, [](const size_t& res, const Song& thesong) {
			return res + thesong.m_length;
			});
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');

		std::string str = "Total Listening Time: ";
		str += std::to_string(sum / 3600);
		str += ":";
		str += std::to_string((sum %= 3600) / 60);
		str += ":";
		str += std::to_string(sum % 60);
		out << "| " << std::setw(84) << str << " |" << std::endl;
	}

	void SongCollection::sort(std::string filed)
	{
		if (filed == "title")
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {return a.m_title < b.m_title; });
		else if(filed=="album")
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {return a.m_album < b.m_album; });
		else if(filed=="length")
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {return a.m_length < b.m_length; });
	}
	void SongCollection::cleanAlbum()
	{
		for_each(m_songs.begin(), m_songs.end(), [](Song& song) {
			if (song.m_album == "[None]")
			{
				song.m_album = "";
			}
			});
	}
	bool SongCollection::inCollection(std::string name) const
	{
		auto res= std::find_if(m_songs.begin(), m_songs.end(), [&name](const Song& song) {return song.m_artist == name; });
		return res != m_songs.end();
	}

	std::list<Song> SongCollection::getSongsForArtist(std::string name) const
	{
		auto cnt = std::count_if(m_songs.begin(), m_songs.end(), [&name](const Song& songs) {
			return songs.m_artist == name;
			});
		std::list<Song> song(cnt);

		std::copy_if(m_songs.begin(), m_songs.end(), song.begin(), [&name](const Song& song)
			{
				return song.m_artist == name;
			});
		return song;
	}
	
	
}
