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

void WAVFile::setCover(const TagLib::String &path)
{
    try
    {
        TagLib::ID3v2::Tag *t = m_internalFile->ID3v2Tag();

        if (!path.isEmpty()) {
            Cover c(path.toCString());

            TagLib::ID3v2::AttachedPictureFrame *frame = new TagLib::ID3v2::AttachedPictureFrame;
            frame->setMimeType(c.getMimeType());
            frame->setPicture(c.data());
            frame->setType(TagLib::ID3v2::AttachedPictureFrame::Type::FrontCover);

            t->addFrame(frame);
        } else {
            std::cerr << "Could not set cover: path is empty" << std::endl;
        }
    }
    catch(std::string &s)
    {
        std::cerr << s << std::endl;
    }
}

void WAVFile::clearCover()
{
    if (!m_internalFile->hasID3v2Tag())
        return;

    TagLib::ID3v2::Tag *t = m_internalFile->ID3v2Tag();

    std::list<TagLib::ID3v2::Frame*> framesToDelete;

    for (auto i : t->frameList()) {
        if (i->frameID().endsWith("PIC")) {
            framesToDelete.push_back(i);
        }
    }

    for (auto i : framesToDelete) {
        t->removeFrame(i);
    }
}

void WAVFile::clear()
{
    clearCover();
    m_internalFile->strip();
}
