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



#include "FLACFile.hpp"

using namespace std;

FLACFile::FLACFile(string path) : AudioFile(path)
{
}

void FLACFile::setCover(const TagLib::String &path)
{
	try
	{
		Cover c(path.toCString());
		TagLib::FLAC::File currentFile(m_fr.file()->name());
		TagLib::Ogg::XiphComment *t = currentFile.xiphComment(true);

		//Remove all pictures
		currentFile.removePictures();

		//Embedding picture into file
		TagLib::FLAC::Picture* picture = new TagLib::FLAC::Picture;
		picture->setData(c.data());
		picture->setType((TagLib::FLAC::Picture::Type) 0x03); // Front Cover
		picture->setMimeType(c.getMimeType());
		picture->setDescription("FrontCover");
		currentFile.addPicture(picture);

		//Linking
		TagLib::List<TagLib::FLAC::Picture*> embeddedPicturesList = currentFile.pictureList();
		TagLib::List<TagLib::FLAC::Picture*>::Iterator it;
		for(it = embeddedPicturesList.begin(); it != embeddedPicturesList.end(); ++it)
		{
			TagLib::ByteVector block = (*it)->render();
			t->addField("METADATA_BLOCK_PICTURE", b64_encode(block.data(), block.size()), true);
		}

		currentFile.save();
	}
	catch(string &s)
	{
		cerr << s << endl;
	}
}
