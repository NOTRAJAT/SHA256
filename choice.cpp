#include <iostream>

std::string chc(std::string str, std::string& str1, std::string& str2){
	for (int i = 0; i < 32; i++) {
		if (str[i] == '1')
			str[i] = str1[i];
		else
			str[i] = str2[i];

	}
	return str;
}

