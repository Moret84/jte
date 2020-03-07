#include "MP3File.hpp"

using namespace std;

MP3File::MP3File(const string &path)
{
	m_internalFile = new TagLib::MPEG::File(path.c_str());
	m_file = m_internalFile;
}

void MP3File::clearCover()
{
	clearID3Cover();
	clearAPECover();
}

void MP3File::setCover(const TagLib::String &path)
{
	try
	{
		TagLib::ID3v2::Tag *t = m_internalFile->ID3v2Tag(true);

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

void MP3File::clearID3Cover()
{
	if (!m_internalFile->hasID3v2Tag())
		return;
	
	TagLib::ID3v2::Tag *t = m_internalFile->ID3v2Tag(true);

	std::list<TagLib::ID3v2::Frame*> framesToDelete;

	for (auto i : t->frameList()) {
		if (i->frameID().endsWith("PIC")) {
			framesToDelete.push_back(i);
		}
	}

	for (auto i : framesToDelete) {
		t->removeFrame(i);
	}
}

void MP3File::clearAPECover()
{
	if (!m_internalFile->hasAPETag())
		return;

	TagLib::APE::Tag *t = m_internalFile->APETag(false);

	std::list<TagLib::String> itemsToDelete;

	for (auto i : t->itemListMap()) {
		if (i.second.type() == TagLib::APE::Item::ItemTypes::Binary) {
			itemsToDelete.push_back(i.first);
		}
	}

	for (auto i : itemsToDelete) {
		t->removeItem(i);
	}
}
