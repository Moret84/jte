#include "AudioFileFactory.hpp"

using namespace std;

AudioFile* AudioFileFactory::create(const string &path)
{
	try
	{
		audioFileType type = getFileType(path);

		if(type == audioFileType::MP3)
			return new MP3File(path);
		else if(type == audioFileType::FLAC)
			return new FLACFile(path);
	}
	catch(string &s)
	{
		cerr << s <<endl;
	}
		return nullptr;
}

audioFileType AudioFileFactory::getFileType(const string &fileName)
{
	string extension = fileName.substr(fileName.find_last_of('.') + 1);
	transform(extension.begin(), extension.end(), extension.begin(), ::tolower);

	if(extension == "mp3")
		return audioFileType::MP3;
	else if(extension == "flac")
		return audioFileType::FLAC;
	else if(extension == "ogg")
		return audioFileType::OGG;
	else
		throw string(fileName + ": Unknown file type");
}

void AudioFileFactory::destroy(AudioFile* af)
{
	delete af;
}
