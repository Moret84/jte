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

TagLib::Tag* AudioFile::tag()
{
	return m_file->tag();
}

void AudioFile::setGenre(const TagLib::String &s)
{
	m_file->tag()->setGenre(s);
}

void AudioFile::setYear(const TagLib::String &s)
{
	m_file->tag()->setYear(s.toInt());
}

void AudioFile::setAlbum(const TagLib::String &s)
{
	m_file->tag()->setAlbum(s);
}

void AudioFile::setArtist(const TagLib::String &s)
{
	m_file->tag()->setArtist(s);
}

void AudioFile::setTitle(const TagLib::String &s)
{
	m_file->tag()->setTitle(s);
}

void AudioFile::setTrack(const TagLib::String &s)
{
	m_file->tag()->setTrack(s.toInt());
}

void AudioFile::save()
{
	m_file->save();
}

AudioFile::~AudioFile()
{
	delete m_file;
}
