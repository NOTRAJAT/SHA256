#include <iostream>
//#include <string>
#include <map>
#include <string_view>

static std::map<std::string_view, char> m{
	   {"0000", '0'},
	   {"0001", '1'},
	   {"0010", '2'},
	   {"0011", '3'},
	   {"0100", '4'},
	   {"0101", '5'},
	   {"0110", '6'},
	   {"0111", '7'},
	   {"1000", '8'},
	   {"1001", '9'},
	   {"1010", 'a'},
	   {"1011", 'b'},
	   {"1100", 'c'},
	   {"1101", 'd'},
	   {"1110", 'e'},
	   {"1111", 'f'},

};
void hexa(std::string& str) {
	int counter = 0;

	for (int i = 0; i < 32; i += 4) {

		std::string_view input(str.c_str() + i, 4);
		str[counter++] = m[input];
	}
	str.erase(8, 24);
	
}

