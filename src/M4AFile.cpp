#include "Cover.hpp"
#include "M4AFile.hpp"

#include <taglib/tpropertymap.h>
#include <taglib/mp4tag.h>
#include <taglib/mp4coverart.h>

#include <iostream>

using namespace std;

const std::string COVER_KEY = "covr";

M4AFile::M4AFile(const string &path)
{
    m_internalFile = new TagLib::MP4::File(path.c_str());
    m_file = m_internalFile;
}

void M4AFile::clear()
{
    clearCover();
    m_internalFile->strip();
}
