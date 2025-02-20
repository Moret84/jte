#ifndef OPUSFILE_HPP
#define OPUSFILE_HPP

#include "AudioFile.hpp"
#include <taglib/opusfile.h>


class OpusFile : public AudioFile
{
    public:
        OpusFile(const std::string &path);
        ~OpusFile();

    private:
        TagLib::Ogg::Opus::File* m_internalFile;
        void clear();
};

#endif
