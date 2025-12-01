#ifndef SPARSER_H
#define SPARSER_H

#include <fstream>
#include <vector>
#include <string>
#include "sregister.h"

class SParser
{
private:
         // Parser owns the file stream

public:
    std::ifstream file;
    SParser(const std::string &filename);   // Pass only filename
    std::vector<SRegister> parse();
};

#endif
