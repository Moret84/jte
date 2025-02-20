#include "MP3File.hpp"

#include <iostream>

using namespace std;

MP3File::MP3File(const string &path)
{
    m_internalFile = new TagLib::MPEG::File(path.c_str());
    m_file = m_internalFile;
}

void MP3File::clear()
{
    clearCover();
    m_internalFile->strip();
}
