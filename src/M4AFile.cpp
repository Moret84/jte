#include "M4AFile.hpp"

M4AFile::M4AFile(const std::string &path)
{
    m_internalFile = new TagLib::MP4::File(path.c_str());
    m_file = m_internalFile;
}

M4AFile::~M4AFile()
{
    delete m_internalFile;
}

void M4AFile::clear()
{
    clearCover();
    m_internalFile->strip();
}
