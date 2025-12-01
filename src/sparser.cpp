#include "SParser.h"
#include <iostream>
#include "constants.h"
#include "utils.h"
#include <string>

SParser::SParser(const std::string &filename)
{
    file.open(filename);

    if (!file.is_open())
    {
        std::cerr << "Error: cannot open file: " << filename << std::endl;
    }
}

std::vector<SRegister> SParser::parse()
{
    std::vector<SRegister> reglist;
    std::string line;

    std::cout << "new code 22--" << std::endl;

    SRegister *reg = nullptr;

    while (std::getline(file, line))
    {
        line = Utils::trim(line);
        std::cout << line << std::endl;

        // Initialize register here
        if (line.rfind(Constants::REG, 0) == 0)
        {

            if (reg != nullptr)
            {
                reglist.push_back(*reg);
                delete reg;
                reg = nullptr;
            }

            // 1. Split string by space seperate
            std::vector<std::string_view> reg_token = Utils::split(line, ' ');

            std::cout << "--reg_token size " << reg_token.size() << std::endl;

            std::string reg_name;
            std::string reg_address;
            std::string reg_desc;
            std::vector<std::string> fields;

            if (reg_token.size() >= 3)
            {
                reg_name = reg_token[1];
                reg_address = reg_token[2];
                reg_desc = reg_token[3];

                std::cout << "reg_name : " << reg_name << std::endl;
                std::cout << "reg_address : " << reg_address << std::endl;
                std::cout << "reg_desc : " << reg_desc << std::endl;

                reg = new SRegister(reg_name,
                                    reg_address,
                                    reg_desc);
            }

            // 5. read next line
            // 6. if it is not field the throw error "at least 1 field require in reg"
            // 7. else split string by space
            // 8. [1] = name
            // 9. [2] = lsb
            // 10. [3] = width
            // 11. [4] = description
            // 12. create a vector of field and read next line till all field coming
            // 13. create reg obj from above reg values and field list
        }
        else if (line.rfind(Constants::FIELD, 0) == 0)
        {
            if (reg != nullptr)
            {
                std::vector<std::string_view> reg_token = Utils::split(line, ' ');

                std::cout << "--field_token size " << reg_token.size() << std::endl;

                std::string field_name;
                std::string field_lsb;
                std::string field_width;
                std::string field_description;

                if (reg_token.size() >= 4)
                {
                    field_name = reg_token[1];
                    field_lsb = reg_token[2];
                    field_width = reg_token[3];
                    field_description = reg_token[4];

                    std::cout << "field_name : " << field_name << std::endl;
                    std::cout << "field_lsb : " << field_lsb << std::endl;
                    std::cout << "field_width : " << field_width << std::endl;
                    std::cout << "field_description : " << field_description << std::endl;

                    SField field(field_name,
                                 field_lsb,
                                 field_width,
                                 field_description);

                    reg->addField(field);
                }
            }
        }
    }

    if (reg != nullptr)
    {
        reglist.push_back(*reg);
        delete reg;
    }

    std::cout << "----final reglist size : " << reglist.size() << std::endl;

    std::cout << "----reglist[0].fields.size() : " << reglist[0].fields.size() << std::endl;

    file.close();
    return reglist;
}
