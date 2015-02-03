#include <string>
#include "base64.hpp"

static const char table[64] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
	'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
	'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
	'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
	'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
	'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
	'w', 'x', 'y', 'z', '0', '1', '2', '3',
	'4', '5', '6', '7', '8', '9', '+', '/'
};

void encode_block(const unsigned char *block, std::string& output)
{
	int index;

	index = block[0] >> 2;
	output.push_back(table[index]);

	index = (block[1] >> 4) | ((block[0] & 0x3) << 4);
	output.push_back(table[index]);

	index = (block[2] >> 6) | ((block[1] & 0x0f) << 2);
	output.push_back(table[index]);

	index = block[2] & 0x3f;
	output.push_back(table[index]);
}

std::string base64_encode(const unsigned char *input, size_t size)
{
	std::string output;
	unsigned char block[3] = {0};
	unsigned int i;

	output.reserve(((size / 3) + 1) * 4);

	for (i = 0; i + 3 < size; i += 3)
		encode_block(input + i, output);

	if (i < size) {
		size_t s = output.size();
		size_t left = size - i;

		memcpy(block, input + i, left);
		encode_block(block, output);

		for (size_t e = s + left + 1; e < output.size(); e++)
			output[e] = '=';
	}

	return output;
}
