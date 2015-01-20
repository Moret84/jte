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

#ifndef JTE_HPP
#define JTE_HPP

#include <tclap/CmdLine.h>
#include <tclap/ArgException.h>

#include "AudioFileFactory.hpp"
#include <taglib/tfile.h>
#include <taglib/tstring.h>

#include <vector>
#include <map>
#include <forward_list>

class JTE
{
	private:
		std::forward_list<AudioFile*> m_fileList;
		std::map<std::string, TagLib::String> m_tagList;

		void parseCL(int argc, char **argv);
		void tagFiles();

	public:

		JTE(int argc, char **argv);
		~JTE();

		void run();
};

#endif
