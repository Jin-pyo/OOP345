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
		int m_year;
		int m_length;
		double m_price;
	};

	class SongCollection
	{
		std::vector<sdds::Song> m_songs;
		std::string& trim(std::string&);
	public:
		SongCollection(std::string);
		void display(std::ostream& out) const;
		void sort(std::string filed);
		void cleanAlbum();
		bool inCollection(std::string name) const;
		std::list<Song> getSongsForArtist(std::string name) const;
	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong);

}

#endif // !SONG_H



