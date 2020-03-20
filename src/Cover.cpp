#include "Cover.hpp"

using namespace std;

Cover::Cover(const char *file) : TagLib::File(file)
{
    string fileName(file);
    string extension = fileName.substr(fileName.find_last_of('.') + 1);
    transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
    m_mimeType = "image/";
    if(extension == "png")
        m_mimeType += "png";
    else if(extension == "jpeg" || extension == "jpg")
        m_mimeType += "jpeg";
    else
        throw string(fileName + ": Unknown picture type.");
}

string Cover::getMimeType() const
{
    return m_mimeType;
}
