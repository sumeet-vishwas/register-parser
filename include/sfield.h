#ifndef SFIELD_H
#define SFIELD_H

#include <string>

struct SField
{
    std::string name;
    std::string lsb;
    std::string width;
    std::string description;

    SField(const std::string &name,
           const std::string &lsb,
           const std::string &width,
           const std::string &description) : name(name),
                                             lsb(lsb),
                                             width(width),
                                             description(description) {}

};

#endif