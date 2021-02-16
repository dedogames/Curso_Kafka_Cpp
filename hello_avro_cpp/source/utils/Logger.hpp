#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <string>
#include <iostream>
namespace utils
{
    enum class Type
    {
        Debug,
        info,
        Log
    };
    class Logger
    {
    private:
        static void debug(std::string msg, bool is_show = true)
        {
            if (is_show)
            {
                std::cout << "[DEBUG]" << msg << std::endl;
            }
        }

        static void info(std::string msg, bool is_show = true)
        {
            if (is_show)
            {
                std::cout << "[INFO]" << msg << std::endl;
            }
        }

        static void log(std::string msg, bool is_show = true)
        {
            if (is_show)
            {
                std::cout << "[LOG]" << msg << std::endl;
            }
        }

    public:
        static void Log(const std::string &msg, Type tp, bool is_show = true)
        {
            switch (tp)
            {
            case Type::Debug:
                debug(msg, is_show);
                break;
            case Type::info:
                info(msg, is_show);
                break;
            case Type::Log:
                log(msg, is_show);
                break;
            default:
                break;
            }
        }
    };
} // namespace utils
#endif