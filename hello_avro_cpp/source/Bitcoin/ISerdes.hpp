#ifndef ISERDES_HPP
#define ISERDES_HPP
#include <avro/Specific.hh>
#include <avro/Encoder.hh>
#include <avro/Decoder.hh>
#include<string>
namespace bitcoin
{
    class ISerdes
    {
    public:
        ISerdes(const std::string& sc_name):m_my_name(sc_name){}
        virtual void serialize() = 0;
        virtual void descerialize() = 0;
    protected:
    const std::string &m_my_name;
    avro::ValidSchema trade_schema;
    };
} // namespace bitcoin
#endif