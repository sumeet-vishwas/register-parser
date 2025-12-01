#ifndef OUTPUT_WRITER_FACTORY_H
#define OUTPUT_WRITER_FACTORY_H

#include <string>
#include <memory>

#include "output_writer.h"
#include "constants.h"

class OutputWriterFactory
{
public:
    std::unique_ptr<OutputWriter> getOutputWriter(std::string type);
};

#endif