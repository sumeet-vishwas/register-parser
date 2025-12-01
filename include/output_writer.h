#ifndef OUTPUT_WRITER_H
#define OUTPUT_WRITER_H

#include "sregister.h"
#include <string>
#include <vector>

class OutputWriter
{
public:
    virtual ~OutputWriter() = default;

    virtual void writeOutput(const std::vector<SRegister> &reg, const std ::string &outpath) = 0;
};

#endif