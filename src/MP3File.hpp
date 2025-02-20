#ifndef MP3FILE_HPP
#define MP3FILE_HPP

#include "AudioFile.hpp"

#include <taglib/mpegfile.h>

class MP3File : public AudioFile
{
    public:
        MP3File(const std::string &path);
        ~MP3File();

    private:
        void clear();
        TagLib::MPEG::File* m_internalFile;
};

#endif
