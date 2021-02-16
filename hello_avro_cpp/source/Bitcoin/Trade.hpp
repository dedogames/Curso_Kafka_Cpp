#ifndef TRADE_HPP
#define TRADE_HPP
#include <string>
#include "ISerdes.hpp" 
#include <avro/Specific.hh>
#include <avro/Encoder.hh>
#include <avro/Decoder.hh>
#include <avro/Compiler.hh>
#include <fstream>
#include<memory>
 
namespace bitcoin
{
    class Trade : public ISerdes  //public avro::codec_traits
    {
    public:  
        Trade(const std::string tid, const std::string date, const std::string type, const std::string price, const std::string amount) ;
        virtual ~Trade(){}
        virtual void serialize();
        virtual void deserialize();
        std::string to_string();

    public:
        std::string m_tid;
        std::string m_date;
        std::string m_type;
        std::string m_price;
        std::string m_amount;
        private:
         std::unique_ptr<avro::OutputStream> out;
    };
} // namespace bitcoin

#endif // TRADE_HPP