#include "OpusFile.hpp"

#include <taglib/opusfile.h>

OpusFile::OpusFile(const std::string &path)
{
    m_internalFile = new TagLib::Ogg::Opus::File(path.c_str());
    m_file = m_internalFile;
}

OpusFile::~OpusFile()
{
    delete m_internalFile;
}

void OpusFile::clear()
{
    clearCover();
    m_internalFile->tag()->removeAllFields();
}
