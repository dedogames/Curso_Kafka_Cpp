#ifndef SD_AVRO_HPP
#define SD_AVRO_HPP

#include <avro/Specific.hh>
#include <avro/Encoder.hh>
#include <avro/Decoder.hh>
#include <avro/Compiler.hh>
#include <fstream>
#include "Bitcoin/Trade.hpp"
namespace utils
{
    namespace avro_utils
    {
        void load_schema(const std::string &path_file, avro::ValidSchema &sc)
        {
            std::ifstream file(path_file);
            avro::compileJsonSchema(file, sc);
        }

    } // namespace avro_utils
} // namespace avro

#endif