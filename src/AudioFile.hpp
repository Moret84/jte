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



#ifndef AUDIOFILE_HPP
#define AUDIOFILE_HPP

#include <taglib/tag.h>
#include <taglib/tstring.h>
#include "Cover.hpp"

enum audioFileType
{
	MP3,
	OGG,
	FLAC
};

class AudioFile
{
	protected:
		TagLib::FileRef m_fr;
		AudioFile(const std::string &path);

	public:
		virtual ~AudioFile();
		inline TagLib::Tag* tag() { return m_fr.tag(); }

		inline void setGenre(const TagLib::String &s) { m_fr.tag()->setGenre(s); }
		inline void setYear(const TagLib::String &s) { m_fr.tag()->setYear(s.toInt()); }
		inline void setAlbum(const TagLib::String &s) { m_fr.tag()->setAlbum(s); }
		inline void setArtist(const TagLib::String &s) { m_fr.tag()->setArtist(s); }
		inline void setTitle(const TagLib::String &s) { m_fr.tag()->setTitle(s); }
		inline void setTrack(const TagLib::String &s) { m_fr.tag()->setTrack(s.toInt()); }
		inline void save() { m_fr.save(); }

		virtual void setCover(const TagLib::String &path) = 0;
};

#endif
