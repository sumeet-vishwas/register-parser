#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <memory>

#include "sparser.h"
#include "output_writer.h"
#include "json_output_writer.h"

int main()
{

    std::string output_type = "json";

    std::string filePath = "../data/reg_spec.regspec";
    std::string outPath = "../data/output.json";

    std::unique_ptr<SParser> parse = std::make_unique<SParser>(filePath);

    std::vector<SRegister> reglist = parse->parse();

    std::unique_ptr<OutputWriter> outputwriter = nullptr;

    if (output_type == "json")
    {
        outputwriter = std::make_unique<JsonOutputWriter>();
    }

    outputwriter->writeOutput(reglist, outPath);

    return 0;
}