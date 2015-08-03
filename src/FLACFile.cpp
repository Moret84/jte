#include "FLACFile.hpp"

using namespace std;

FLACFile::FLACFile(const string &path)
{
	m_file = new TagLib::FLAC::File(path.c_str());
}

void FLACFile::clearCover()
{
	TagLib::List<TagLib::FLAC::Picture*> embeddedPicturesList = dynamic_cast<TagLib::FLAC::File*>(m_file)->pictureList();
	TagLib::List<TagLib::FLAC::Picture*>::ConstIterator it;

	for(it = embeddedPicturesList.begin(); it !=embeddedPicturesList.end(); ++it)
	{
		TagLib::FLAC::Picture* pic = *it;
		if(pic->type() == TagLib::FLAC::Picture::Type::FrontCover)
			dynamic_cast<TagLib::FLAC::File*>(m_file)->removePicture(pic);
	}
}

void FLACFile::setCover(const TagLib::String &path)
{
	try
	{
		TagLib::List<TagLib::FLAC::Picture*> embeddedPicturesList = dynamic_cast<TagLib::FLAC::File*>(m_file)->pictureList();
		TagLib::List<TagLib::FLAC::Picture*>::ConstIterator it;

		clearCover();

		if(path != TagLib::String::null)
		{
			Cover c(path.toCString());
			TagLib::Ogg::XiphComment *t = dynamic_cast<TagLib::FLAC::File*>(m_file)->xiphComment(true);

			//Embedding picture into file
			TagLib::FLAC::Picture* picture = new TagLib::FLAC::Picture;
			picture->setData(c.data());
			picture->setType(TagLib::FLAC::Picture::Type::FrontCover);
			picture->setMimeType(c.getMimeType());
			picture->setDescription("Front Cover");
			dynamic_cast<TagLib::FLAC::File*>(m_file)->addPicture(picture);

			//Linking
			for(it = embeddedPicturesList.begin(); it != embeddedPicturesList.end(); ++it)
			{
				if((*it)->type() == TagLib::FLAC::Picture::Type::FrontCover)
				{
					TagLib::ByteVector block = (*it)->render();
					t->addField("METADATA_BLOCK_PICTURE", base64_encode(reinterpret_cast<unsigned char*>(block.data()), block.size()), true);
				}
			}
		}
	}
	catch(string &s)
	{
		cerr << s << endl;
	}
}
