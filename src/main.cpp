#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <memory>
#include <unistd.h>

#include "sparser.h"
#include "output_writer.h"
#include "json_output_writer.h"

int main(int argc, char *argv[])
{
    // take arg from main

    std::string output_type = "json";
    std::string filePath = ""; //"../data/reg_spec.regspec";
    std::string outPath = "";  //"../data/output.json";

    int opt;

    while ((opt = getopt(argc, argv, "f:o:t:")) != -1)
    {
        switch (opt)
        {
        case 'f':
            filePath = optarg;
            break;

        case 'o':
            outPath = optarg;
            break;
        case 't':
            output_type = optarg;
            break;
        default:
            std::cout << "Usage: program -f <file> -o <output> [-t <type>]\n";
            return 1;
        }
    }

    if (filePath.empty() || outPath.empty())
    {
        std::cout << "Error: -f <file> and -o <output> are required!\n";
        return 1;
    }

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