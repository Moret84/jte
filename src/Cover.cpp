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

#include "Cover.hpp"

using namespace std;

Cover::Cover(const char *file) : TagLib::File(file)
{
	string fileName(file);
	string extension = fileName.substr(fileName.find_last_of('.') + 1);
	transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
	m_mimeType = "image/";
	if(extension == "png")
		m_mimeType += "png";
	else if(extension == "jpeg" || extension == "jpg")
		m_mimeType += "jpeg";
	else
		throw string(fileName + ": Unknown picture type.");
}

string Cover::getMimeType() const
{
	return m_mimeType;
}
