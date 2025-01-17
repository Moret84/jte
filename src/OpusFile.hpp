#ifndef OPUSFILE_HPP
#define OPUSFILE_HPP

#include "AudioFile.hpp"
#include <taglib/opusfile.h>


class OpusFile : public AudioFile
{
    public:
        OpusFile(const std::string &path);
        ~OpusFile();
        void setCover(const TagLib::String &path);

    private:
        TagLib::Ogg::Opus::File* m_internalFile;
        void clearCover();
        void clear();
};

#endif
