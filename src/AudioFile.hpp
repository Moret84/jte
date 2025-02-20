#ifndef AUDIOFILE_HPP
#define AUDIOFILE_HPP

#include "Cover.hpp"

#include <taglib/fileref.h>
#include <taglib/tag.h>
#include <taglib/tstring.h>

class AudioFile
{
    protected:
        TagLib::File* m_file;
        void clearCover(void);

    public:
        virtual ~AudioFile() { delete m_file; }

        void set(const std::string &tag, const std::string &value);
        void get() const;

        void save() { m_file->save(); }

        void setCover(const std::string &s);
        virtual void clear() = 0;
};

#endif
