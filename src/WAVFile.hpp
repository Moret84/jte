#ifndef WAVFILE_HPP
#define WAVFILE_HPP

#include "AudioFile.hpp"

#include <taglib/wavfile.h>

class WAVFile : public AudioFile
{
    public:
        WAVFile(const std::string &path);
        ~WAVFile();

    private:
        void clear();
        TagLib::RIFF::WAV::File* m_internalFile;
};

#endif
