#include "FLACFile.hpp"
#include "MP3File.hpp"

class AudioFileFactory
{
	public:
		static AudioFile* create(const std::string &path);
		static audioFileType getFileType(const std::string &fileName);
		static void destroy(AudioFile * af);
};
