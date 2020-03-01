#include "AudioFile.hpp"

using namespace std;

void AudioFile::set(const std::string &tag, const TagLib::String &value)
{
	if(tag == "genre")
		m_file->tag()->setGenre(value);
	else if(tag == "year")
		m_file->tag()->setYear(value.toInt());
	else if(tag == "album")
		m_file->tag()->setAlbum(value);
	else if(tag == "artist")
		m_file->tag()->setArtist(value);
	else if(tag == "title")
		m_file->tag()->setTitle(value);
	else if(tag == "trackNumber")
		m_file->tag()->setTrack(value.toInt());
	else if(tag == "cover")
		this->setCover(value);
}

void AudioFile::get() const
{
		cout << "Track:	" << m_file->tag()->track() << endl;
		cout << "Title:	" << m_file->tag()->title().to8Bit(true) << endl;
		cout << "Artist:	" << m_file->tag()->artist().to8Bit(true) << endl;
		cout << "Album:	" << m_file->tag()->album().to8Bit(true) << endl;
		cout << "Year:	" << m_file->tag()->year() << endl;
		cout << "Genre:	" << m_file->tag()->genre().to8Bit(true) << endl;
}

void AudioFile::clear()
{
	m_file->tag()->setGenre(TagLib::String::null);
	m_file->tag()->setYear(0);
	m_file->tag()->setAlbum(TagLib::String::null);
	m_file->tag()->setArtist(TagLib::String::null);
	m_file->tag()->setTitle(TagLib::String::null);
	m_file->tag()->setTrack(0);
	m_file->tag()->setComment(TagLib::String::null);
	this->setCover(TagLib::String::null);
}
