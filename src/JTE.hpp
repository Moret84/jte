#ifndef JTE_HPP
#define JTE_HPP

#include <tclap/CmdLine.h>
#include <tclap/ArgException.h>

#include "AudioFileFactory.hpp"
#include <taglib/tfile.h>
#include <taglib/tstring.h>

#include <vector>
#include <map>
#include <forward_list>

enum mode
{
    READ,
    WRITE,
    CLEAR
};

class JTE
{
    private:
        std::forward_list<AudioFile*> m_fileList;
        std::map<std::string, TagLib::String> m_tagList;
        mode m_mode;

        void parseCL(int argc, char **argv);

    public:

        JTE(int argc, char **argv);
        ~JTE();

        void run();
};

#endif
