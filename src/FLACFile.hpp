#ifndef FLACFILE_HPP
#define FLACFILE_HPP

#include "AudioFile.hpp"
#include <taglib/vorbisfile.h>
#include <taglib/flacfile.h>
#include <taglib/xiphcomment.h>
#include <taglib/flacpicture.h>
#include <taglib/tlist.h>

class FLACFile : public AudioFile
{
	public:
		FLACFile(const std::string &path);
		void setCover(const TagLib::String &path);
		void clearCover();

	private:
		TagLib::FLAC::File* m_internalFile;
};

#endif
