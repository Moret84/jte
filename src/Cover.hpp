#ifndef COVER_HPP
#define COVER_HPP

#include <taglib/fileref.h>

class Cover : public TagLib::File
{
    private:
        virtual TagLib::Tag *tag() const { return nullptr; }
        virtual TagLib::AudioProperties *audioProperties() const { return nullptr; }
        virtual bool save() { return false; }
        std::string m_mimeType;

    public:
        Cover(const std::string &file);
        TagLib::ByteVector const data() { return readBlock(length()); }
        std::string getMimeType() const;
};

#endif
