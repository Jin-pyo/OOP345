// Name: Jinpyo Ju
// Seneca Student ID: 134444181
// Seneca email: jju3@myseneca.ca
// Date of completion: 11/12/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

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
			throw "Invalid filename";
		}
		while (file)
		{
			Song song;
			std::string tmp;
			std::getline(file, tmp);

			if (file)
			{
				trim(song.m_title = tmp.substr(0,25));
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

				this->m_songs.push_back(song);
			}


		}
		file.close();
	}
	void SongCollection::display(std::ostream& out)const
	{
		for_each(m_songs.begin(), m_songs.end(), [&out](const Song& list) {
			out << list << std::endl;
			});

		int total = std::accumulate(m_songs.begin(), m_songs.end(), 0, [](int x, const Song& list)->int {
			return x + list.m_length;
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
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& a , const Song& b) {
				return a.m_title < b.m_title;
				});
		}
		else if (name == "album")
		{
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {
				return a.m_album < b.m_album;
				});
		}
		else if (name == "length")
		{
			std::sort(m_songs.begin(), m_songs.end(), [](const Song& a, const Song& b) {
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
		auto check = std::find_if(m_songs.begin(), m_songs.end(), [name](const Song& list)->bool{
			if (name == list.m_artist)
			{
				return true;
			}
			

			});
		return check != m_songs.end();
	}
	std::list<Song> SongCollection::getSongsForArtist(std::string name) const
	{
		int cnt = std::count_if(m_songs.begin(), m_songs.end(), [name](const Song& list) {
			if (list.m_artist == name)
			{
				return true;
			}
			});

		std::list<Song> tmp(cnt);

		std::copy_if(m_songs.begin(), m_songs.end(), tmp.begin(), [name](const Song& list) {
				
			if (list.m_artist == name)
			{
				return true;
			}

			});

		return tmp;
	}
	
}
