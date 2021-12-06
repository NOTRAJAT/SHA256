#include <iostream>
#include <string>

std::string ror(std::string &str, int n)
{
    std::string output;
    output.append(str.substr((32 - n), n));
    output.append(str.substr(0, (32 - n)));
    return output;
}
std::string rol(std::string &str, int n)
{
    std::string output;
    output.append(str.substr(n, (32 - n)));
    output.append(str.substr(0, n));
    return output;
}
std::string shr(std::string &str, int n)
{
    std::string output(n, '0');
    output.append(str.substr(0, (32 - n)));

    return output;
}
std::string shl(std::string &str, int n)
{
    std::string output(n, '0');
    output.insert(0, str.substr(n, (32 - n)));

    return output;
}
