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
}

OpusFile::~OpusFile()
{
    delete m_internalFile;
}

void OpusFile::clearCover()
{
    TagLib::Ogg::XiphComment *comment = m_internalFile->tag();
    comment->removeAllPictures();
}

void OpusFile::setCover(const TagLib::String &path)
{
    if (!path.isEmpty()) {
        Cover cover(path.toCString());

        // Embedding picture into file
        TagLib::FLAC::Picture* picture = new TagLib::FLAC::Picture;
        picture->setData(cover.data());
        picture->setType(TagLib::FLAC::Picture::Type::FrontCover);
        picture->setMimeType(cover.getMimeType());

        m_internalFile->tag()->addPicture(picture);
    } else {
        cerr << "Could not set cover: path is empty" << std::endl;
    }
}

void OpusFile::clear()
{
    clearCover();
    m_internalFile->tag()->removeAllFields();
}
