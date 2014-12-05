#ifndef BASE64_HPP
#define BASE64_HPP

#include <cstdint>
#include <cstring>

void encode_block(const unsigned char *block, std::string& output);
std::string base64_encode(const unsigned char *input, size_t size);

#endif
