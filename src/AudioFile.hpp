#ifndef AUDIOFILE_HPP
#define AUDIOFILE_HPP

#include <taglib/tag.h>
#include <taglib/tstring.h>
#include <taglib/fileref.h>
#include <map>
#include "Cover.hpp"

class AudioFile
{
    protected:
        TagLib::File* m_file;

    public:
        virtual ~AudioFile() { delete m_file; }

        void set(const std::string &tag, const TagLib::String &value);
        void get() const;
        void clear();

        void save() { m_file->save(); }

        virtual void setCover(const TagLib::String &s) = 0;
        virtual void clearCover() = 0;
};

#endif
