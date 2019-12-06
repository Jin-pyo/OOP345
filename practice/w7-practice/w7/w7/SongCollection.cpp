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
	
	SongCollection::SongCollection(std::string file)
	{
		std::ifstream f(file);
		if (!f)
		{
			throw "Invalid filename";
		}
		
			

			while (f)
			{
				std::string tmp;
				Song song;
				std::getline(f, tmp);

				if (f)
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
					song.m_price = std::stod(tmp.substr(85, 5));

					this->m_songs.push_back(song);
				}
			}
			f.close();

		


	}
	void SongCollection::display(std::ostream& out) const
	{
		for_each(m_songs.begin(), m_songs.end(), [&out](const Song& song) {
			out << song << std::endl;
			});
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