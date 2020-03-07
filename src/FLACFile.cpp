#include "FLACFile.hpp"

using namespace std;

FLACFile::FLACFile(const string &path)
{
	m_internalFile = new TagLib::FLAC::File(path.c_str());
	m_file = m_internalFile;
}

void FLACFile::clearCover()
{
	m_internalFile->removePictures();
}

void FLACFile::setCover(const TagLib::String &path)
{
	TagLib::List<TagLib::FLAC::Picture*> embeddedPicturesList = m_internalFile->pictureList();
	TagLib::List<TagLib::FLAC::Picture*>::ConstIterator it;

	clearCover();

	if(path != TagLib::String::null) {
		Cover cover(path.toCString());

		//Embedding picture into file
		TagLib::FLAC::Picture* picture = new TagLib::FLAC::Picture;
		picture->setData(cover.data());
		picture->setType(TagLib::FLAC::Picture::Type::FrontCover);
		picture->setMimeType(cover.getMimeType());
		picture->setDescription("Front Cover");

		m_internalFile->addPicture(picture);
	} else {
		cerr << "Could not set cover: path is empty" << std::endl;
	}
}
