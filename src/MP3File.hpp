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

#ifndef MP3FILE_HPP
#define MP3FILE_HPP

#include "AudioFile.hpp"
#include <taglib/id3v2tag.h>
#include <taglib/mpegfile.h>
#include <taglib/attachedpictureframe.h>

class MP3File : public AudioFile
{
	public:
		MP3File(const std::string &path);
		void setCover(const TagLib::String &path);
};

#endif
