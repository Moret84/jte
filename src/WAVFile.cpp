#include "WAVFile.hpp"

#include <taglib/wavfile.h>

WAVFile::WAVFile(const std::string &path)
{
    m_internalFile = new TagLib::RIFF::WAV::File(path.c_str());
    m_file = m_internalFile;
}

WAVFile::~WAVFile()
{
    delete m_internalFile;
}

void WAVFile::clear()
{
    clearCover();
    m_internalFile->strip();
}
