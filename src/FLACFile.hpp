#ifndef FLACFILE_HPP
#define FLACFILE_HPP

#include "AudioFile.hpp"

#include <taglib/flacfile.h>

class FLACFile : public AudioFile
{
    public:
        FLACFile(const std::string &path);
        ~FLACFile();

    private:
        TagLib::FLAC::File* m_internalFile;
        void clear();
};

#endif
