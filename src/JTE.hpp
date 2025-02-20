#ifndef JTE_HPP
#define JTE_HPP

#include "AudioFileFactory.hpp"

#include <forward_list>
#include <map>

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
        std::map<std::string, std::string> m_tagList;
        mode m_mode;

        void parseCL(int argc, char **argv);

    public:

        JTE(int argc, char **argv);
        ~JTE();

        void run();
};

#endif
