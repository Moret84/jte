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

        void save() { m_file->save(); }

        virtual void clear() = 0;
        virtual void setCover(const TagLib::String &s) = 0;
};

#endif
