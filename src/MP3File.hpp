#ifndef MP3FILE_HPP
#define MP3FILE_HPP

#include "AudioFile.hpp"
#include <taglib/id3v2tag.h>
#include <taglib/mpegfile.h>
#include <taglib/attachedpictureframe.h>
#include <string.h>

class MP3File : public AudioFile
{
	public:
		MP3File(const std::string &path);
		void setCover(const TagLib::String &path);
		void clearCover();

	private:
		void clearID3Cover();
		TagLib::MPEG::File* m_internalFile;
};

#endif
