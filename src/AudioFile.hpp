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
#include <taglib/fileref.h>
#include <map>
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
		TagLib::File* m_file;

	public:
		virtual ~AudioFile() { delete m_file; }

		void set(const std::string &tag, const TagLib::String &value);
		void get() const;
		void clear();

		void save() { m_file->save(); }

		virtual void setCover(const TagLib::String &s) = 0;
};

#endif
