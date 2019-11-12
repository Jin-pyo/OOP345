// Name: Jinpyo Ju
// Seneca Student ID: 134444181
// Seneca email: jju3@myseneca.ca
// Date of completion: 11/12/2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SONGCOLLECTION_H
#define SONGCOLLECTION_H

#include<string>
#include<iostream>
#include<vector>
#include<list>

namespace sdds
{
	struct Song
	{
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price;
		int m_year;
		size_t m_length;
	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong);

	class SongCollection
	{
		std::vector<sdds::Song> m_songs;
	protected:
		std::string& trim(std::string& check);
	public:
		SongCollection(std::string);
		void display(std::ostream& out) const;
		void sort(std::string filed);
		void cleanAlbum();
		bool inCollection(std::string name) const;
		std::list<Song> getSongsForArtist(std::string name) const;
		
	};

}

#endif

