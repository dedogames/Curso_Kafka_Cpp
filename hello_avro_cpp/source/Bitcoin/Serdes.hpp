//
// Serdes.hpp
// ~~~~~~~~~~~~~~~~~~~~~~~~
//
// Developer: Gelson Rodrigues
// geoldery@gmail.com
//
// Abstract class to serialize/desserialize
//  
//
#ifndef SERDES_HPP
#define SERDES_HPP
#include <avro/Specific.hh>
#include <avro/Encoder.hh>
#include <avro/Decoder.hh>
#include<string>
namespace bitcoin
{
    class Serdes
    {
    public:
        Serdes(const std::string& sc_name):m_my_name(sc_name){}
        virtual void serialize() = 0;
        virtual void deserialize() = 0;
    protected:
    std::string m_my_name;
    avro::ValidSchema trade_schema;
    };
} // namespace bitcoin
#endif