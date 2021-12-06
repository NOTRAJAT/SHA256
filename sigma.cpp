#include <iostream>
std::string ror(std::string& str, int n);
std::string rol(std::string& str, int n);
std::string shr(std::string& str, int n);
std::string shl(std::string& str, int n);

std::string x_or(std::string &&str, std::string &&str1, std::string &&str2) {
	for (int i = 0; i < 32; i++){
		str[i] = (int(str[i]) ^ int(str1[i]) ^  int(str2[i]) );
	}
	return str;
}

std::string sig_0(std::string& str){

	return x_or(ror(str, 7), ror(str, 18), shr(str, 3));
	
}std::string sig_1(std::string& str){

	return x_or(ror(str, 17), ror(str, 19), shr(str, 10));
	
}std::string SIG_0(std::string& str){

	return x_or(ror(str, 2), ror(str, 13), ror(str, 22));
	
}std::string SIG_1(std::string& str){

	return x_or(ror(str, 6), ror(str, 11), ror(str, 25));
	
}