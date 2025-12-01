#ifndef SREGISTER_H
#define SREGISTER_H

#include <string>
#include <vector>
#include "sfield.h"

struct SRegister
{
    std::string name;
    std::string address;
    std::string description;
    std::vector<SField> fields;

    SRegister(const std::string &name,
              const std::string &address,
              const std::string &description) : name(name),
                                                address(address),
                                                description(description)
    {
    }

    void addField(const SField &field)
    {
        fields.push_back(field);
    }

    void setFields(const std::vector<std::string> &f)
    {
        this->fields = fields;
    }
};

#endif