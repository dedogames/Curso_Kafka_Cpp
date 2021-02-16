#include "Trade.hpp"
#include "utils/sd_avro.hpp"
#include "utils/Logger.hpp"
//https://avro.apache.org/docs/current/api/cpp/html/index.html
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

} // namespace avro

namespace bitcoin
{
    Trade::Trade(const std::string tid, const std::string date, const std::string type, const std::string price, const std::string amount) : ISerdes("/projects/hello_avro_cpp/build/Debug/hello_avro_cpp/schemaTrade.json"), m_tid(tid), m_date(date), m_type(type), m_price(price), m_amount(amount)
    {
        utils::Logger::Log("Load SchemaTrade.json",utils::Type::Debug);
        utils::avro_utils::load_schema(m_my_name, trade_schema);
    }
    void Trade::serialize()
    {
         out = avro::memoryOutputStream();
         avro::EncoderPtr encod = avro::binaryEncoder();//avro::validatingEncoder(trade_schema, avro::binaryEncoder());
         encod->init(*out);
         utils::Logger::Log("Encoding: "+this->to_string(),utils::Type::Debug);
         avro::encode(*encod, *this);
    }
    void Trade::deserialize()
    {
         std::unique_ptr <avro::InputStream> in = avro::memoryInputStream(*out);
         avro::DecoderPtr dec = avro::validatingDecoder(trade_schema, avro::binaryDecoder());
         dec->init(*in);          
         avro::decode(*dec,*this);
         utils::Logger::Log("Decode: "+this->to_string(),utils::Type::Debug);
    }

    std::string Trade::to_string()
    {
        std::string l_res = 
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
} // namespace bitcoin