#pragma once
#include <iostream>
#include <vector>
//vector display
void display(std::vector<std::string>& var);


//message.cpp
void msg_block(std::string& str, std::vector<std::string>& output_arr);
//sigma.cpp
std::string sig_0(std::string& str);
std::string sig_1(std::string& str);
std::string SIG_0(std::string& str);
std::string SIG_1(std::string& str);

//rotate.cpp
//std::string ror(std::string& str, int n);
//std::string rol(std::string& str, int n);
//std::string shr(std::string& str, int n);
//std::string shl(std::string& str, int n);

//majority
std::string majority(std::string& str, std::string& str1, std::string& str2);

//chc
std::string chc(std::string str, std::string& str1, std::string& str2);

//add.ccp
std::string add_2(std::string&& str, std::string&& str1);
std::string add_2(std::string& str, std::string& str1);
std::string add_2(std::string&& str, std::string& str1);
std::string add_4(std::string&& str, std::string&& str1, std::string& str2, std::string& str3);
std::string add_4(std::string& str, std::string& str1, std::string& str2, std::string& str3);
std::string add_5(std::string&& str, std::string&& str1, std::string& str2, std::string& str3, std::string& str4);

//hexa
void hexa(std::string& str);

