#ifndef TRADE_HPP
#define TRADE_HPP
#include <string>
#include "ISerdes.hpp"
#include "utils/sd_avro.hpp"
#include <avro/Specific.hh>
#include <avro/Encoder.hh>
#include <avro/Decoder.hh>
#include <avro/Compiler.hh>
#include "utils/sd_avro.hpp"
namespace bitcoin
{
    class Trade : public ISerdes , public avro::codec_traits
    {
    public:
  
        Trade(std::string tid, std::string date, std::string type, std::string price, std::string amount) :ISerdes("schemaTrade.json"), m_tid(tid), m_date(date), m_type(type), m_price(price), m_amount(amount) 
        {                
            avro::avro_utils::load_schema(m_my_name,trade_schema);

        }
        void serialize()
        {
            out = avro::memoryOutputStream();            
            avro::EncoderPtr encod = avro::validatingEncoder(trade_schema, avro::binaryEncoder());
            encod->init(*out);
            encode(*encod, this);
        }
        void deserialize()
        {
            std::auto_ptr<avro::InputStream> in = avro::memoryInputStream(*out);            
            avro::DecoderPtr decode = avro::validatingDecoder(trade_schema, avro::binaryDecoder());
            decode->init(*in);
            decode(*decode, this);
        }
        std::string to_string()
        {
            std::string l_res;
            "tid: " + m_tid + "|"
                              "date: " +
                m_date + "|"
                         "type: " +
                m_type + "|"
                         "price: " +
                m_price + "|"
                          "amount: " +
                m_amount;
            return l_res;
        }

    public:
        std::string m_tid;
        std::string m_date;
        std::string m_type;
        std::string m_price;
        std::string m_amount;
        private:
         std::auto_ptr<avro::OutputStream> out;
    };
} // namespace bitcoin

#endif // TRADE_HPP