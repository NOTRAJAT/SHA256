#include <iostream>
#include <string>


void reverse(std::string &str)
{
    
    
    std::string temp(32,'0');
    int count = 0;
    for (int i = (str.length() - 1);i >= 0; i--)
    {
        
        temp[count++] = str[i];
    }
    str = temp;
}
std::string add_2(std::string &str, std::string &str1)
{
    
    int carry = 0;
    std::string out;
    // std::string   temp;

    for (int i = 32; i >= 0; i--)
    {

        // *values in comments are arbitarily chosen examples.

        out.append(std::to_string((int(str[i]) ^ int(str1[i]) ^ carry)));
        //(1 ^ 0 ^ 0)=int 1---> string value "1"(using std::to_string()) and appended to out

        //temp = char((int(str[i]) & int(str1[i])) | (int(carry) & int(str[i])) | (int(carry) & int(str1[i])));
        //// ^ ((1 & 0)|(0 & 1)|(0 & 0))= int 48(assci)--->char(48)='0'---> string value of temp="0"

        //carry = std::stoi(temp);

        if (49 == ((int(str[i]) & int(str1[i])) | (int(carry) & int(str[i])) | (int(carry) & int(str1[i])))) //// ^ ((1 & 0)|(0 & 1)|(0 & 0))= int 48(assci)
            carry = 1;
        else 
            carry = 0;

      

        //string value temp = "0" ---> int 0 in carry(using std::stoi() )
    }
    reverse(out);
    return out;
}
std::string add_2(std::string&& str, std::string&& str1)
{

    int carry = 0;
    std::string out;
    // std::string   temp;

    for (int i = 32; i >= 0; i--)
    {


        out.append(std::to_string((int(str[i]) ^ int(str1[i]) ^ carry)));
    

        if (49 == ((int(str[i]) & int(str1[i])) | (int(carry) & int(str[i])) | (int(carry) & int(str1[i]))))
            carry = 1;
        else
            carry = 0;


    }
    reverse(out);
    return out;
}
std::string add_2(std::string&& str, std::string& str1)
{

    int carry = 0;
    std::string out;
   

    for (int i = 32; i >= 0; i--)
    {


        out.append(std::to_string((int(str[i]) ^ int(str1[i]) ^ carry)));
        //(1 ^ 0 ^ 0)=int 1---> string value "1"(using std::to_string()) and appended to out

        //temp = char((int(str[i]) & int(str1[i])) | (int(carry) & int(str[i])) | (int(carry) & int(str1[i])));
        //// ^ ((1 & 0)|(0 & 1)|(0 & 0))= int 48(assci)--->char(48)='0'---> string value of temp="0"

        //carry = std::stoi(temp);
        if (49 == ((int(str[i]) & int(str1[i])) | (int(carry) & int(str[i])) | (int(carry) & int(str1[i]))))
            carry = 1;
        else
            carry = 0;




        //string value temp = "0" ---> int 0 in carry(using std::stoi() )
    }
    reverse(out);
    return out;
}


std::string add_4(std::string&& str, std::string&& str1, std::string& str2, std::string& str3) {

   return add_2(add_2(str, str1),add_2(str2, str3));
}
std::string add_4(std::string& str, std::string& str1, std::string& str2, std::string& str3) {

   return add_2(add_2(str, str1),add_2(str2, str3));
}


std::string add_5(std::string &&str, std::string &&str1, std::string& str2, std::string& str3, std::string& str4)
{

   
    return add_2(add_4(str, str1, str2, str3), str4);
}


/*std::string add_3(std::string& str_input, std::string& str1_input, std::string& str1)
{

    std::string str = add_2(str_input, str1_input);
    std::string out, temp;
    int carry = 0;

    for (int i = str.length() - 1; i >= 0; i--)
    {

        out.append(std::to_string((int(str[i]) ^ int(str1[i]) ^ carry)));

        temp = char((int(str[i]) & int(str1[i])) | (int(carry) & int(str[i])) | (int(carry) & int(str1[i])));

        carry = std::stoi(temp);
    }
    reverse(out);
    return out;
}*/
/*std::string add_4_test(std::string& str, std::string& str1, std::string& str2, std::string& str3) {
  
    
    auto start = std::chrono::high_resolution_clock::now();
    
    
    std::future<std::string> val_1 = std::async(std::launch::async, add_2, std::ref(str), std::ref(str1));
    std::future<std::string> val_2 = std::async(std::launch::async, add_2, std::ref(str2), std::ref(str3));
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << (duration.count())* 1000.0f << std::endl;
    
    
    std::string input = val_1.get();
    std::string input2 = val_2.get();
    
    return add_2(input, input2);
}*/ 