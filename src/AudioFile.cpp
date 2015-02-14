/*
 *  Copyright (C) 2014 Aurélien Rivet
 *
 *
 *  This file is part of jdid tag editor.
 *
 *
 *  jdid tag editor is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>
 *
 *
 */

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
	//m_file->clear();
}
