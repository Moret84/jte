#include "OpusFile.hpp"

#include <iostream>
#include <taglib/flacfile.h>
#include <taglib/xiphcomment.h>
#include <taglib/flacpicture.h>
#include <taglib/tlist.h>

using namespace std;

OpusFile::OpusFile(const string &path)
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
