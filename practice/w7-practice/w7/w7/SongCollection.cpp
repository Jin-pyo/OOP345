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
			throw "Can't open file";
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
					song.m_price = std::stod(tmp.substr(85, 5));

					m_songs.push_back(song);
				}
			}
			file.close();
		}
	
	}


	void SongCollection::display(std::ostream& out)const
	{
		std::for_each(m_songs.begin(), m_songs.end(), [&out](const Song& song) {

			out << song << std::endl;
			});
		int total = std::accumulate(m_songs.begin(), m_songs.end(),0, [](int x, const Song& b) {
			return x+b.m_length;
			});

		int hour = total / 3600;
		int min = (total % 3600) / 60;
		int second = total % 60;

		out << "| " << std::setw(74) << std::right << hour << " : " << min << " : " << second << " | " << std::endl;

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

	void SongCollection::sort(std::string name)
	{
		if (name == "title")
		{
			std::sort(this->m_songs.begin(), this->m_songs.end(), [](Song& a, Song& b) {
				return a.m_title < b.m_title;
				});
		}
		else if (name == "album")
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {return a.m_album < b.m_album; });
		else if (name == "length")
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {return a.m_length < b.m_length; });

	}
	void SongCollection::cleanAlbum()
	{
		for_each(m_songs.begin(), m_songs.end(), [](Song& song) {
			if (song.m_album[0] == '[')
			{
				song.m_album = " ";
			}
			});
	}
	bool SongCollection::inCollection(std::string name) const
	{
		auto check=std::find_if(m_songs.begin(), m_songs.end(), [name](const Song& song) {
			return name == song.m_artist;
			});
		return check != m_songs.end();
	}
	std::list<Song> SongCollection::getSongForArtist(std::string name)const
	{
		int cnt = std::count_if(m_songs.begin(), m_songs.end(), [name](const Song song) {
			return song.m_artist == name;
			});

		std::list<Song> tmp(cnt);

		std::copy_if(m_songs.begin(), m_songs.end(), tmp.begin(), [&name](const Song& song) {
			return song.m_artist == name;
			});

		return tmp;
	}

}