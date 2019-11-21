#include "SongCollection.h"
#include<iostream>
#include<fstream>
#include<algorithm>
#include<iomanip>
#include<numeric>

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
	SongCollection::SongCollection(std::string filename)
	{
		std::ifstream file(filename);
		if (!file)
		{
			throw "This name is incorrect";
		}
		
			while (file)
			{
				sdds::Song song;
				std::string check;
				std::getline(file, check);
				std::string tmp;
				
				if (file)
				{
					tmp = check.substr(0, 25);
					song.m_title = trim(tmp);

					tmp = check.substr(25, 25);
					song.m_artist = trim(tmp);

					tmp = check.substr(50, 25);
					song.m_album = trim(tmp);

					try {
						tmp = check.substr(75, 5);
						song.m_year = std::stoi(tmp);
					}
					catch (...)
					{
						song.m_year = 0;
					}

					tmp = check.substr(80, 5);
					song.m_length = std::stoi(tmp);

					tmp = check.substr(85);
					song.m_price = std::stod(tmp);

					m_songs.push_back(song);

				}
			}
			file.close();
		
	}
	void SongCollection::display(std::ostream& out) const
	{
		for_each(m_songs.begin(), m_songs.end(), [&out](const Song& song) {

			out << song << std::endl;
			});
		
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ') << std::endl;

		int sum = std::accumulate(m_songs.begin(), m_songs.end(), 0, [](int x, Song song) {
			return x + song.m_length;
			});
		out << "| " << std::setw(74) << std::right << "Total Listening Time: "
			<< (sum / 60) / 60 << " : " << (sum % 3600)/60 << " : " << sum % 60<<" |"<<std::endl;


	}

	void SongCollection::sort(std::string filed)
	{
		if (filed == "title")
		{
			std::sort(m_songs.begin(), m_songs.end(), [](Song& a, Song& b) {
				return a.m_title < b.m_title;
				});
		}
		else if (filed == "album")
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {return a.m_album < b.m_album; });
		else if (filed == "length")
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {return a.m_length < b.m_length; });
	}
	void SongCollection::cleanAlbum()
	{
		for_each(m_songs.begin(), m_songs.end(), [](Song& a) {
			if (a.m_album == "[None]")
				a.m_album = " ";
			});
	}
	bool SongCollection::inCollection(std::string name) const
	{
		auto check = std::find_if(m_songs.begin(), m_songs.end(), [&name](const Song& song) {
				return name == song.m_artist;
			});
		return check!=m_songs.end();
	}
	std::list<Song> SongCollection::getSongsForArtist(std::string name) const
	{
		auto cnt = std::count_if(m_songs.begin(), m_songs.end(), [&name](const Song& song) {
			return song.m_artist == name;
			});
		std::list<Song> tmp(cnt);

		std::copy_if(m_songs.begin(), m_songs.end(), tmp.begin(), [&name](const Song& song) {
			return song.m_artist == name;
			});

		return tmp;
	}



	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
		out << "| " << std::setw(20) << std::left << theSong.m_title
			<< " | " << std::setw(15) << theSong.m_artist
			<< " | " << std::setw(20) << theSong.m_album
			<< " | " << std::setw(6) << std::right;
		if (theSong.m_year == 0){out << "";}
		else{out<<theSong.m_year;}
		int min = theSong.m_length / 60;
		int second = theSong.m_length % 60;
		out << " | " << min << ":" << second;
			if (second < 10){out << "0";}
			out << " | " << theSong.m_price << " | ";

		return out;
	}

}