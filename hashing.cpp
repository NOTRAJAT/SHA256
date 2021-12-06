#include <iostream>
#include <string>
#include <vector>
#include "_WRAPPER_.h"
int hashing(std::string &str) {
	
	std::vector<std::string> _CONSTANT_ =
	{ "01000010100010100010111110011000", "01110001001101110100010010010001", "10110101110000001111101111001111", "11101001101101011101101110100101", "00111001010101101100001001011011", "01011001111100010001000111110001", "10010010001111111000001010100100", "10101011000111000101111011010101", "11011000000001111010101010011000", "00010010100000110101101100000001", "00100100001100011000010110111110", "01010101000011000111110111000011", "01110010101111100101110101110100", "10000000110111101011000111111110", "10011011110111000000011010100111", "11000001100110111111000101110100", "11100100100110110110100111000001", "11101111101111100100011110000110", "00001111110000011001110111000110", "00100100000011001010000111001100", "00101101111010010010110001101111", "01001010011101001000010010101010", "01011100101100001010100111011100", "01110110111110011000100011011010", "10011000001111100101000101010010", "10101000001100011100011001101101", "10110000000000110010011111001000", "10111111010110010111111111000111", "11000110111000000000101111110011", "11010101101001111001000101000111", "00000110110010100110001101010001", "00010100001010010010100101100111",
		"00100111101101110000101010000101", "00101110000110110010000100111000", "01001101001011000110110111111100", "01010011001110000000110100010011", "01100101000010100111001101010100", "01110110011010100000101010111011", "10000001110000101100100100101110", "10010010011100100010110010000101", "10100010101111111110100010100001", "10101000000110100110011001001011", "11000010010010111000101101110000", "11000111011011000101000110100011", "11010001100100101110100000011001", "11010110100110010000011000100100", "11110100000011100011010110000101", "00010000011010101010000001110000", "00011001101001001100000100010110", "00011110001101110110110000001000", "00100111010010000111011101001100", "00110100101100001011110010110101", "00111001000111000000110010110011", "01001110110110001010101001001010", "01011011100111001100101001001111", "01101000001011100110111111110011", "01110100100011111000001011101110", "01111000101001010110001101101111", "10000100110010000111100000010100", "10001100110001110000001000001000", "10010000101111101111111111111010", "10100100010100000110110011101011", "10111110111110011010001111110111", "11000110011100010111100011110010" };
	std::vector<std::string>	_REGISTER_ =
	{ "01101010000010011110011001100111", "10111011011001111010111010000101", "00111100011011101111001101110010", "10100101010011111111010100111010",
   "01010001000011100101001001111111", "10011011000001010110100010001100", "00011111100000111101100110101011", "01011011111000001100110100011001" };
	std::vector<std::string> _msg_BLOCK_;
	std::vector<std::string> _MESSAGE_SHCEDHULE_;
	std::vector<std::string> _COPY_REGISTER_;
	std::string t1;
	std::string output;
	//std::string t2;



	/*std::vector<std::string>::iterator iter_msg_BLOCK_ = _msg_BLOCK_.begin();
	std::vector<std::string>::iterator iter_MESSAGE_SHCEDHULE_ = _MESSAGE_SHCEDHULE_.begin();
	std::vector<std::string>::iterator iter_REGISTER_ = _REGISTER_.begin();
	std::vector<std::string>::iterator iter_COPY_REGISTER_ = _COPY_REGISTER_.begin();*/

	//std::string str;
	//std::cin >> str;
	msg_block(str, _msg_BLOCK_);//coverts satring into hashing input blocks in --> _msg_BLOCK_

	//display(_msg_BLOCK_);


	// MAIN HASING IN THIS LOOP
	for (int i = 0; i < _msg_BLOCK_.size(); i += 16)
	{
		_COPY_REGISTER_.insert(_COPY_REGISTER_.begin(), _REGISTER_.begin(), _REGISTER_.begin() + 8);
		_MESSAGE_SHCEDHULE_.insert(_MESSAGE_SHCEDHULE_.begin(), _msg_BLOCK_.begin() + i, _msg_BLOCK_.begin() + i + 16);


		//display(_MESSAGE_SHCEDHULE_);
		//extending _MESSAGE_SHCEDHULE_ to 64 size with add func
		for (int j = 16; j < 64; j++) {
			_MESSAGE_SHCEDHULE_.push_back(
				add_4(
					sig_1(_MESSAGE_SHCEDHULE_[(j - 2)]),
					sig_0(_MESSAGE_SHCEDHULE_[(j - 15)]),
					_MESSAGE_SHCEDHULE_[(j - 7)],
					_MESSAGE_SHCEDHULE_[(j - 16)]));
		}
		//std::cout<<_MESSAGE_SHCEDHULE_.size()<<std::endl;
		//display(_MESSAGE_SHCEDHULE_);

		//for compression of register;

		for (int k = 0; k < 64; k++) {
			t1 = add_5(
				SIG_1(_REGISTER_[4]),
				chc(_REGISTER_[4], _REGISTER_[5], _REGISTER_[6]),
				_REGISTER_[7],
				_MESSAGE_SHCEDHULE_[k],
				_CONSTANT_[k]);

			//t2 = add_2(
			//	SIG_0(_REGISTER_[0]),
			//	majority(_REGISTER_[0], _REGISTER_[1], _REGISTER_[2]));

			_REGISTER_.pop_back();


			_REGISTER_.insert(_REGISTER_.begin(),
				add_2(
					add_2(SIG_0(_REGISTER_[0]),majority(_REGISTER_[0], _REGISTER_[1], _REGISTER_[2])),
					 t1));

			_REGISTER_[4] = add_2(t1, _REGISTER_[4]);
		}

		for (int p = 0; p < 8; p++)
			_REGISTER_[p] = add_2(_REGISTER_[p], _COPY_REGISTER_[p]);


		_COPY_REGISTER_.clear();
		_MESSAGE_SHCEDHULE_.clear();

	}

	for (int q = 0; q < 8; q++) {
		hexa(_REGISTER_[q]);
		output += _REGISTER_[q];
	}

	std::cout << output << std::endl;
	



}

	


	

	


	





	/*std::cout << str  << std::endl;
	hexa(str);
	std::cout << str;*/
	//std::cout << str1 << std::endl;
	//std::cout << str2 << std::endl;

	//std::cout << chc(str, str1, str2);
	/*std::cout << sig_0(str) << std::endl;
	std::cout << sig_1(str) << std::endl;
	std::cout << SIG_0(str) << std::endl;
	std::cout << SIG_1(str) << std::endl;*/
	//printf("\n");
	//std::cout << majority(str, str1, str2);
	//
	//

	//std::string hold;

	//std::cout<<(int(str1[0]) & int(str2[0]))<<std::endl;//b.c
	//std::cout << (int(str[0]) & int(str1[0]) & ~(int(str2[0]))) << std::endl;//str.b.~c
	//std::cout << (int(str[0]) & ~(int(str1[0])) & int(str2[0])) << std::endl;//str.~b.c
	//std::cout << (int(str[0]) & (int(str1[0]) & ~(int(str2[0])) | ~(int(str1[0])) & int(str2[0])))<<"\n";
	//std::cout << ((int(str1[0]) & int(str2[0])) | (int(str[0]) & (int(str1[0]) & ~(int(str2[0])) | ~(int(str1[0])) & int(str2[0]))))<<"\n";
//#include <vector>
//#include <string>
//#include <string_view>
////static uint32_t s_AllocCount = 0;
//static size_t total = 0;
//std::vector<std::string> msg_block(std::string& str);
//void display(std::vector<std::string>& var);
//
//
//int main()
//{
//	std::string input;
//	std::cin >> input;
//	
//	
//	
//
//	auto arr = msg_block(input);
//	std::cout << arr.size() << std::endl;
//	display(arr);
//	std::cout << s_AllocCount << " Allocation" << std::endl;
//	std::cout << "Allocation total " << total << " bytes\n";
//}static uint32_t s_AllocCount = 0;
// static size_t total = 0;
// void *operator new(size_t size)
// {
//     s_AllocCount++;
//     total += size;
//     std::cout << "Allocating " << size << " bytes\n";
//     return malloc(size);
// }


