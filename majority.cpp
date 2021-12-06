#include <iostream>


std::string majority(std::string& str, std::string& str1, std::string& str2) {
	std::string output(32, '0');

	for (int i = 0; i < 32; i++) {
		if (49 == (int(str1[i]) & int(str2[i])) | (int(str[i]) & (int(str1[i]) & ~(int(str2[i])) | ~(int(str1[i])) & int(str2[i])))) {
			output[i] = '1';
		}
		else
		{
			output[i] = '0';
		}
	}
	return output;
}