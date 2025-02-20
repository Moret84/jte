#include "AudioFile.hpp"

#include <iostream>

#include <taglib/tstring.h>

using namespace std;

const TagLib::String PICTURE_KEY = "PICTURE";

void AudioFile::setCover(const string &value)
{
    Cover c(value);

    m_file->tag()->setComplexProperties(PICTURE_KEY, {
        {
            { "data", c.data() },
            { "pictureType", "Front Cover" },
            { "mimeType", TagLib::String(c.getMimeType()) }
        }
    });
}

void AudioFile::clearCover()
{
    m_file->tag()->setComplexProperties(PICTURE_KEY, {
        {
        }
    });

}

void AudioFile::set(const string &tag, const string &value)
{
    if(tag == "genre")
        m_file->tag()->setGenre(TagLib::String(value, TagLib::String::Type::UTF8));
    else if(tag == "year")
        m_file->tag()->setYear(stoul(value));
    else if(tag == "album")
        m_file->tag()->setAlbum(TagLib::String(value, TagLib::String::Type::UTF8));
    else if(tag == "artist")
        m_file->tag()->setArtist(TagLib::String(value, TagLib::String::Type::UTF8));
    else if(tag == "title")
        m_file->tag()->setTitle(TagLib::String(value, TagLib::String::Type::UTF8));
    else if(tag == "trackNumber")
        m_file->tag()->setTrack(stoul(value));
    else if(tag == "cover")
        this->setCover(value);
}

void AudioFile::get() const
{
        cout << "Track: " << m_file->tag()->track() << endl;
        cout << "Title: " << m_file->tag()->title().to8Bit(true) << endl;
        cout << "Artist: " << m_file->tag()->artist().to8Bit(true) << endl;
        cout << "Album: " << m_file->tag()->album().to8Bit(true) << endl;
        cout << "Year:  " << m_file->tag()->year() << endl;
        cout << "Genre: " << m_file->tag()->genre().to8Bit(true) << endl;
}
