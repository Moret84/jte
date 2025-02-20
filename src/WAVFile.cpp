#include "WAVFile.hpp"

#include <taglib/wavfile.h>
#include <taglib/id3v2tag.h>
#include <taglib/attachedpictureframe.h>

#include <iostream>

WAVFile::WAVFile(const std::string &path)
{
    m_internalFile = new TagLib::RIFF::WAV::File(path.c_str());
    m_file = m_internalFile;
}

void WAVFile::clear()
{
    clearCover();
    m_internalFile->strip();
}
