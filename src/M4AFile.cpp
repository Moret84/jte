#include "M4AFile.hpp"

#include <taglib/tpropertymap.h>
#include <taglib/mp4tag.h>
#include <taglib/mp4coverart.h>
#include "Cover.hpp"

using namespace std;

const std::string COVER_KEY = "covr";

M4AFile::M4AFile(const string &path)
{
    m_internalFile = new TagLib::MP4::File(path.c_str());
    m_file = m_internalFile;
}

void M4AFile::clearCover()
{
    m_internalFile->tag()->removeItem(COVER_KEY);
    m_internalFile->tag()->save();
}

void M4AFile::setCover(const TagLib::String &path)
{
    if (path == TagLib::String::null)
    {
        cerr << "Could not set cover: path is empty" << std::endl;
        return;
    }

    Cover c(path.toCString());

    auto format = TagLib::MP4::CoverArt::Format::Unknown;

    if (c.getMimeType() == "image/png")
    {
        format = TagLib::MP4::CoverArt::Format::PNG;
    }
    else if (c.getMimeType() == "image/jpeg")
    {
        format = TagLib::MP4::CoverArt::Format::JPEG;
    }

    auto tag = m_internalFile->tag();

    TagLib::MP4::CoverArtList coverArtList;
    coverArtList.append(TagLib::MP4::CoverArt(format, c.data()));

    tag->setItem(COVER_KEY, TagLib::MP4::Item(coverArtList));
    tag->save();
}

void M4AFile::clear()
{
    clearCover();
}
