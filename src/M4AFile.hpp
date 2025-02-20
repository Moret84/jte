#ifndef M4AFILE_HPP
#define M4AFILE_HPP

#include "AudioFile.hpp"
#include <taglib/mp4file.h>
#include <taglib/id3v2tag.h>
#include <taglib/attachedpictureframe.h>
#include <taglib/apetag.h>
#include <string.h>

class M4AFile : public AudioFile
{
    public:
        M4AFile(const std::string &path);

    private:
        void clear();
        TagLib::MP4::File* m_internalFile;
};

#endif
