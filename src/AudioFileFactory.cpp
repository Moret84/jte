#include "AudioFileFactory.hpp"

using namespace std;

map<string, function<AudioFile*(const string&)>> AudioFileFactory::typeMap;

AudioFile* AudioFileFactory::create(const string &path)
{
    std::string extension = path.substr(path.find_last_of('.') + 1);
    std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);

    auto it = AudioFileFactory::typeMap.find(extension);

    if(it != AudioFileFactory::typeMap.end())
        return it->second(path);
    else
        throw string(path + ": Unknown file type");
}

void AudioFileFactory::Register(std::string key, function<AudioFile*(const std::string&)> createFunction)
{
    AudioFileFactory::typeMap.insert(make_pair(key, createFunction));
}
