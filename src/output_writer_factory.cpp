#include "output_writer_factory.h"
#include "json_output_writer.h"
#include <string>
#include <iostream>

std::unique_ptr<OutputWriter> OutputWriterFactory::getOutputWriter(std::string type)
{
    
    if (type == Constants::OUT_JSON)
    {
        return std::make_unique<JsonOutputWriter>();
    }

    return nullptr;
}