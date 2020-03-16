// common.cpp
#include "common/common.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <ios>

//https://codereview.stackexchange.com/a/22907
std::vector<char> CommonFct::ReadAllBytes(char const *filename)
{
    std::ifstream ifs(filename, std::ios::binary | std::ios::ate);
    std::ifstream::pos_type pos = ifs.tellg();

    std::vector<char> result(pos);

    ifs.seekg(0, std::ios::beg);
    ifs.read(&result[0], pos);

    return result;
}

//https://stackoverflow.com/a/15388182
bool CommonFct::WriteAllBytes(char const *filename, std::string data)
{
    std::ofstream out(filename);
    out << data;
    out.close();
    return true;
}