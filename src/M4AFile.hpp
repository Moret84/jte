#ifndef M4AFILE_HPP
#define M4AFILE_HPP

#include "AudioFile.hpp"

#include <taglib/mp4file.h>

class M4AFile : public AudioFile
{
    public:
        M4AFile(const std::string &path);
        ~M4AFile();

    private:
        void clear();
        TagLib::MP4::File* m_internalFile;
};

#endif
