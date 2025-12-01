#ifndef JSON_OUTPUT_WRITER_H
#define JSON_OUTPUT_WRITER_H

#include "output_writer.h"
#include "json.hpp"

using json = nlohmann::ordered_json;

class JsonOutputWriter : public OutputWriter
{
public:
    void writeOutput(const std::vector<SRegister> &reg, const std::string &outpath) override;
};

#endif