#include "FLACFile.hpp"

using namespace std;

FLACFile::FLACFile(const string &path)
{
	m_file = new TagLib::FLAC::File(path.c_str());
}

void FLACFile::setCover(const TagLib::String &path)
{
	try
	{
		Cover c(path.toCString());
		TagLib::Ogg::XiphComment *t = dynamic_cast<TagLib::FLAC::File*>(m_file)->xiphComment(true);

		//Remove all pictures
		dynamic_cast<TagLib::FLAC::File*>(m_file)->removePictures();

		if(path != TagLib::String::null)
		{
			//Embedding picture into file
			TagLib::FLAC::Picture* picture = new TagLib::FLAC::Picture;
			picture->setData(c.data());
			picture->setType((TagLib::FLAC::Picture::Type) 0x03); // Front Cover
			picture->setMimeType(c.getMimeType());
			picture->setDescription("Front Cover");
			dynamic_cast<TagLib::FLAC::File*>(m_file)->addPicture(picture);

			//Linking
			TagLib::List<TagLib::FLAC::Picture*> embeddedPicturesList = dynamic_cast<TagLib::FLAC::File*>(m_file)->pictureList();
			TagLib::List<TagLib::FLAC::Picture*>::Iterator it;

			for(it = embeddedPicturesList.begin(); it != embeddedPicturesList.end(); ++it)
			{
				TagLib::ByteVector block = (*it)->render();
				t->addField("METADATA_BLOCK_PICTURE", base64_encode(reinterpret_cast<unsigned char*>(block.data()), block.size()), true);
			}
		}
	}
	catch(string &s)
	{
		cerr << s << endl;
	}
}
