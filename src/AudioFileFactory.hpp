#include "FLACFile.hpp"
#include "MP3File.hpp"
#include <functional>

template<typename T> AudioFile* createTypedAudioFile(const std::string &path) { return new T(path); }

class AudioFileFactory
{
	private:
		//Second member of a pair is a function which return an AudioFile*
		static std::map<std::string, std::function<AudioFile*(std::string)>> typeMap;
	public:
		static AudioFile* create(const std::string &path);
		static void Register(std::string key, std::function<AudioFile*(std::string)> createFunction);
};
