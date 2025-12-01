#include "../include/json_output_writer.h"
#include <fstream>

void to_json(json &j, const SField &f)
{
    j = json{
        {"name", f.name},
        {"lsb", f.lsb},
        {"width", f.width},
        {"description", f.description},
    };
}

void to_json(json &j, const SRegister &r)
{
    j = json{
        {"name", r.name},
        {"address", r.address},
        {"description", r.description},
        {"fields", r.fields}};
}

void JsonOutputWriter::writeOutput(const std::vector<SRegister> &reg, const std ::string &outpath)
{
    json j = reg;
    std::ofstream out(outpath);

    out << j.dump(4);
}