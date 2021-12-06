#include <iostream>
#include <cstdlib>
#include <bitset>
#include <cmath>
#include <vector>

// template <class T>
void display(std::vector<std::string> &var)
{

    for (int i = 0; i < var.size(); i++)
    {
        std::cout << var[i] << std::endl;
    }
    printf("\n");
}
void msg_block(std::string &str, std::vector<std::string> &output_arr)
{
   
    std::string assci; //= std::bitset<64>(0).to_string();
    // std::string str;

    int size_padding;
    int size_bits_txt;
    //size_bits_txt = assci.length();

    for (int i = 0; i < str.length(); i++)
    {
        assci.append(std::bitset<8>(int(str[i])).to_string());
    }
    size_bits_txt = assci.length(); //DO NOT MOVE POSITION  LINE
   // assci.erase(0, size_bits_txt);
    //std::cout << assci;

    int _512_block_product = ceil(size_bits_txt / 448.0);
    size_padding = ((512 * _512_block_product) - size_bits_txt - 64);

    // assci.append("1");
    if (size_padding > 0)
    {
        {
            std::string padding(--size_padding, '0'); //reduced by 1
            padding.insert(0, "1");
            assci.append(padding);
        }
    }
    assci.append(std::bitset<64>(size_bits_txt).to_string()); //DO NOT MOVE POSITION  LINE

    for (int i = 0; i < assci.length(); i += 32)

    {
       // std::string_view view(assci.c_str() + i, 32);
        output_arr.push_back(assci.substr(i,32));
    }
   
}

