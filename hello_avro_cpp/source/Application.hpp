#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include <iostream>
#include "Bitcoin/Trade.hpp"

class Application
{
    public:
    Application() {}
    void create_trades(){}

    void init(){}
    void run()
    {
        bitcoin::Trade trade("8615953", "1613358560", "buy", "263249.83999", "0.03000899");
        trade.serialize();
        trade.deserialize();
    }

    void shutdown(){}
};

#endif