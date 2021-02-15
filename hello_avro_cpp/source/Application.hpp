#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include <iostream>
#include "Bitcoin/Trade.hpp"

class Application
{
    Application() {}
    void create_trades()
    {
    }

    void init()
    {
    }
    void run()
    {

        bitcoin::Trade trade_("8615953", "1613358560", "buy", "263249.83999", "0.03000899");
        //t.serialize();
        //t.deserialize();
    }

    void shutdown()
    {
    }
};

#endif