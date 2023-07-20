#ifndef WAVFILE_HPP
#define WAVFILE_HPP

#include "AudioFile.hpp"
#include <taglib/rifffile.h>
#include <taglib/wavfile.h>

class WAVFile : public AudioFile
{
    public:
        WAVFile(const std::string &path);
        void setCover(const TagLib::String &path);

    private:
        void clear();
        void clearCover();
        TagLib::RIFF::WAV::File* m_internalFile;
};

#endif
