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



#include "MP3File.hpp"

using namespace std;

MP3File::MP3File(string path) : AudioFile(path)
{
}

void MP3File::setCover(const TagLib::String &path)
{
	try
	{
		Cover c(path.toCString());
		TagLib::MPEG::File currentFile(m_fr.file()->name());
		TagLib::ID3v2::Tag *t = currentFile.ID3v2Tag(true);
		TagLib::ID3v2::AttachedPictureFrame *frame = new TagLib::ID3v2::AttachedPictureFrame;
		frame->setMimeType(c.getMimeType());
		frame->setPicture(c.data());
		t->addFrame(frame);
		currentFile.save();
	}
	catch(string &s)
	{
		cerr << s << endl;
	}
}
