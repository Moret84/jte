#include "MP3File.hpp"

MP3File::MP3File(const std::string &path)
{
    m_internalFile = new TagLib::MPEG::File(path.c_str());
    m_file = m_internalFile;
}

MP3File::~MP3File()
{
    delete m_internalFile;
}

void MP3File::clear()
{
    clearCover();
    m_internalFile->strip();
}
