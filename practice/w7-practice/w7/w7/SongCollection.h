#ifndef SONG_H
#define SONG_H

#include<string>
#include<vector>
#include<list>

namespace sdds
{
	struct Song
	{
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		int m_length;
		int m_year;
		double m_price;
	};

	class SongCollection
	{
		std::vector<Song> m_songs;
	public:
		std::string& trim(std::string& line);
		SongCollection(std::string file);
		void display(std::ostream& out)const;
		void sort(std::string name);
		void cleanAlbum();
		bool inCollection(std::string name) const;
		std::list<Song> getSongForArtist(std::string name)const;
		
	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}

#endif // !SONG_H



