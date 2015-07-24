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
