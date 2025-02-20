#include "JTE.hpp"

#include "FLACFile.hpp"
#include "M4AFile.hpp"
#include "MP3File.hpp"
#include "OpusFile.hpp"
#include "WAVFile.hpp"

#include <tclap/CmdLine.h>
#include <tclap/ValueArg.h>

using namespace std;

JTE::JTE(int argc, char **argv)
{
    AudioFileFactory::Register("mp3", function<AudioFile*(const string&)>(createTypedAudioFile<MP3File>));
    AudioFileFactory::Register("flac", function<AudioFile*(const string&)>(createTypedAudioFile<FLACFile>));
    AudioFileFactory::Register("m4a", function<AudioFile*(const string&)>(createTypedAudioFile<M4AFile>));
    AudioFileFactory::Register("wav", function<AudioFile*(const string&)>(createTypedAudioFile<WAVFile>));
    AudioFileFactory::Register("opus", function<AudioFile*(const string&)>(createTypedAudioFile<OpusFile>));

    parseCL(argc, argv);
}

JTE::~JTE()
{
}

void JTE::parseCL(int argc, char **argv)
{
    try
    {
        TCLAP::CmdLine cmd("jdid tag editor", ' ', "1.0");

        TCLAP::ValueArg<string>
            cover("c", "cover", "Define the front cover tag", false, "", "path/to/cover", cmd),
            genre("g", "genre", "Define the genre tag", false, "", "genre", cmd),
            year("y", "year", "Define the year tag", false, "", "year", cmd),
            album("A", "album", "Define the album tag", false, "", "album", cmd),
            artist("a", "artist", "Define the artist tag", false, "", "artist", cmd),
            title("t", "title", "Define the title tag", false, "", "title", cmd),
            trackNumber("n", "trackNumber", "Define the tracknumber tag", false, "", "number", cmd);

        TCLAP::SwitchArg list("l", "list", "list tag(s) instead of write them", cmd);
        TCLAP::SwitchArg clear("", "clear", "clear all tags", cmd);

        TCLAP::UnlabeledMultiArg<string> files("files", "The tag edition audio file(s) target(s)", true, "file(s)");
        cmd.add(files);

        //Run parsing
        cmd.parse(argc, argv);

        //Creating the file list
        int filesNumber = files.getValue().size();

        if(filesNumber == 0)
            throw TCLAP::ArgException("No files");

        for(vector<string>::const_iterator it = files.getValue().begin(); it != files.getValue().end(); ++it)
            m_fileList.push_front(AudioFileFactory::create((*it)));

        //What to do
        if(list.isSet())
        {
            m_mode = mode::READ;
        }
        else if(clear.isSet())
        {
            m_mode = mode::CLEAR;
        }
        else
        {
            m_mode = mode::WRITE;

            //Creating the tag map
            if(cover.isSet())
                m_tagList["cover"] = cover.getValue();
            if(genre.isSet())
                m_tagList["genre"] = genre.getValue();
            if(year.isSet())
                m_tagList["year"] = year.getValue();
            if(album.isSet())
                m_tagList["album"] = album.getValue();
            if(artist.isSet())
                m_tagList["artist"] = artist.getValue();
            if(title.isSet())
                m_tagList["title"] = title.getValue();
            if(trackNumber.isSet())
                m_tagList["trackNumber"] = trackNumber.getValue();

            if(m_tagList.empty())
                throw TCLAP::ArgException("Nothing to do");
        }
    }
    catch(TCLAP::ArgException &e)
    {
        cerr << "Error: " << e.error() << endl;
    }
    catch(string &s)
    {
        cerr << "Error: " << s << endl;
    }
}

void JTE::run()
{
    forward_list<AudioFile*>::iterator it;

    for(it = m_fileList.begin(); it != m_fileList.end(); ++it)
    {
        if((*it) == nullptr)
            continue;

        if(m_mode == mode::READ)
        {
            (*it)->get();
        }
        else
        {
            if(m_mode == mode::CLEAR)
            {
                (*it)->clear();
            }
            else if(m_mode == mode::WRITE)
            {
                map<string, string>::iterator itTag;
                for(itTag = m_tagList.begin(); itTag != m_tagList.end(); ++itTag)
                    (*it)->set((*itTag).first, (*itTag).second);
            }

            (*it)->save();
        }
    }
}
