#include "FLACFile.hpp"
#include <iostream>

using namespace std;

FLACFile::FLACFile(const string &path)
{
    m_internalFile = new TagLib::FLAC::File(path.c_str());
    m_file = m_internalFile;
}

FLACFile::~FLACFile()
{
    delete m_internalFile;
}

void FLACFile::clear()
{
    clearCover();
    m_internalFile->strip();
}
