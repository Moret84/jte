#include "MP3File.hpp"

using namespace std;

MP3File::MP3File(const string &path)
{
	m_file = new TagLib::MPEG::File(path.c_str());
	m_internalFile = dynamic_cast<TagLib::MPEG::File*>(m_file);
}

void MP3File::clearCover()
{
	TagLib::ID3v2::Tag *t = dynamic_cast<TagLib::MPEG::File*>(m_file)->ID3v2Tag(true);
	t->removeFrames(TagLib::ByteVector("APIC"));
}

void MP3File::setCover(const TagLib::String &path)
{
	try
	{
		TagLib::ID3v2::Tag *t = dynamic_cast<TagLib::MPEG::File*>(m_file)->ID3v2Tag(true);

		clearCover();

		if(path != TagLib::String::null)
		{

			Cover c(path.toCString());

			TagLib::ID3v2::AttachedPictureFrame *frame = new TagLib::ID3v2::AttachedPictureFrame;
			frame->setMimeType(c.getMimeType());
			frame->setPicture(c.data());

			t->addFrame(frame);
		}
	}
	catch(string &s)
	{
		cerr << s << endl;
	}
}
