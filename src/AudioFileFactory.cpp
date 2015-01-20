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

#include "AudioFileFactory.hpp"

using namespace std;

AudioFile* AudioFileFactory::create(const string &path)
{
	try
	{
		audioFileType type = getFileType(path);

		if(type == audioFileType::MP3)
			return new MP3File(path);
		else if(type == audioFileType::FLAC)
			return new FLACFile(path);
	}
	catch(string &s)
	{
		cerr << s <<endl;
	}
		return nullptr;
}

audioFileType AudioFileFactory::getFileType(const string &fileName)
{
	string extension = fileName.substr(fileName.find_last_of('.') + 1);
	transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
	if(extension == "mp3")
		return audioFileType::MP3;
	else if(extension == "flac")
		return audioFileType::FLAC;
	else if(extension == "ogg")
		return audioFileType::OGG;
	else
		throw string(fileName + ": Unknown file type");
}

void AudioFileFactory::destroy(AudioFile* af)
{
	delete af;
}
