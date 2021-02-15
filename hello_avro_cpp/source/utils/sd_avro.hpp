#ifndef SD_AVRO_HPP
#define SD_AVRO_HPP

#include "Bitcoin/Trade.hpp"
#include <avro/Specific.hh>
#include <avro/Encoder.hh>
#include <avro/Decoder.hh>
#include <avro/Compiler.hh>
#include <fstream>
 
namespace avro
{
        template <>
        struct codec_traits<bitcoin::Trade>
        {
            static void encode(Encoder &e, const bitcoin::Trade &t)
            {
                avro::encode(e, t.m_tid);
                avro::encode(e, t.m_type);
                avro::encode(e, t.m_date);
                avro::encode(e, t.m_price);
                avro::encode(e, t.m_amount);
            }
            static void decode(Decoder &d, bitcoin::Trade &t)
            {
                avro::decode(d, t.m_tid);
                avro::decode(d, t.m_type);
                avro::decode(d, t.m_date);
                avro::decode(d, t.m_price);
                avro::decode(d, t.m_amount);
            }
        };

        namespace avro_utils
        {
            void load_schema(std::string path_file, avro::ValidSchema &sc)
            {
                std::ifstream file(path_file);
                avro::compileJsonSchema(file, sc);
            }

        } // namespace avro_utils
} // namespace avro

#endif