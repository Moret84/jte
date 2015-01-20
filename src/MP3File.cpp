/* *  Copyright (C) 2014 Aurélien Rivet
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

MP3File::MP3File(const string &path)
{
	m_file = new TagLib::MPEG::File(path.c_str());
}

void MP3File::setCover(const TagLib::String &path)
{
	try
	{
		Cover c(path.toCString());
		TagLib::ID3v2::Tag *t = dynamic_cast<TagLib::MPEG::File*>(m_file)->ID3v2Tag(true);

		TagLib::ID3v2::AttachedPictureFrame *frame = new TagLib::ID3v2::AttachedPictureFrame;
		frame->setMimeType(c.getMimeType());
		frame->setPicture(c.data());

		t->addFrame(frame);
	}
	catch(string &s)
	{
		cerr << s << endl;
	}
}
