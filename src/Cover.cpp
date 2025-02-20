#include "Cover.hpp"

using namespace std;

Cover::Cover(const string &filename) : TagLib::File(filename.c_str())
{
    string extension = filename.substr(filename.find_last_of('.') + 1);
    transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
    m_mimeType = "image/";

    if(extension == "png")
        m_mimeType += "png";
    else if(extension == "jpeg" || extension == "jpg")
        m_mimeType += "jpeg";
    else
        throw string(filename + ": Unknown picture type.");
}

string Cover::getMimeType() const
{
    return m_mimeType;
}
