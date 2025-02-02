#include "SongCollection.h"
#include<iostream>
#include<fstream>
#include<algorithm>
#include<iomanip>
#include<numeric>
#include<sstream>
namespace sdds
{
	std::string& SongCollection::trim(std::string& line)
	{
		while (line.length() > 0 && line[0] == ' ')
			line.erase(0, 1);
		while (line.length() > 0 && line[line.length() - 1] == ' ')
			line.erase(line.length() - 1, 1);

		return line;
	}
	
	SongCollection::SongCollection(const char* filename)
	{
		std::ifstream file(filename);
		if (!file)
		{
			std::cerr << "can't open file";
		}
		else {
			while (file)
			{
				Song song;
				std::string tmp;
				std::getline(file, tmp);
				std::stringstream ss(tmp);
				if (file)
				{
					
					ss >> song.m_title >> song.m_artist >> song.m_album>>song.m_year>>song.m_length>>song.m_price;
					
					m_songs.push_back(song);
				}
			}
			file.close();
		}
	}
	void SongCollection::display(std::ostream& out) const
	{
		std::for_each(m_songs.begin(), m_songs.end(), [&](const Song& song) {
			out << song << std::endl;
			});

		int total = std::accumulate(m_songs.begin(), m_songs.end(), (int)0, [](int x, const Song song) {
			return x + song.m_length;
			});

		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');

		int hour = total/3600;
		int min = (total % 3600) / 60;
		int second = total % 60;

		std::string str="Total Listening Time ";

		str += std::to_string(hour);
		str += " : ";
		str += std::to_string(min);
		str += " : ";
		str += std::to_string(second);
		std::cout << " | " << std::setw(84) << str << " | " << std::endl;
	}

	void SongCollection::sort(std::string name)
	{
		if (name == "title")
		{
			std::sort(m_songs.begin(), m_songs.end(), [](Song& a, Song& b) {

				return a.m_title < b.m_title;
				});
		}
		else if (name == "album")
		{
			std::sort(m_songs.begin(), m_songs.end(), [](Song& a, Song& b) {

				return a.m_album < b.m_album;
				});
		}
		else if (name == "length")
		{
			std::sort(m_songs.begin(), m_songs.end(), [](Song& a, Song& b) {

				return a.m_length < b.m_length;
				});
		}
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
		auto check = std::find_if(m_songs.begin(), m_songs.end(), [name](const Song song) {
			return song.m_artist == name;
			});

		return check != m_songs.end();
	}
	std::list<Song> SongCollection::getSongsForArtist(std::string name) const
	{
		int num = std::count_if(m_songs.begin(), m_songs.end(), [name](const Song song) {
			return name == song.m_artist;
			});

		std::list<Song> tmp(num);

		std::copy_if(m_songs.begin(), m_songs.end(), tmp.begin(), [name](const Song& song) {
			return name == song.m_artist;
			
			});

		return tmp;
	}


	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
		int tmp = 0;
		tmp = theSong.m_year;
		out << " | " << std::setw(20) << std::left << theSong.m_title
			<< " | " << std::setw(15) << std::left << theSong.m_artist
			<< " | " << std::setw(20) << std::left << theSong.m_album;
		out << " | " << std::setw(6) << std::right;

		if (tmp > 0)
		{
			out << theSong.m_year;
		}
		else
		{
			out << "";
		}
		int min = theSong.m_length / 60;
		int second = theSong.m_length % 60;
		out << " | " << min << ":" << second;
		if (second < 10) { out << "0"; }
		out << " | " << theSong.m_price << " | ";

		return out;
	}

}