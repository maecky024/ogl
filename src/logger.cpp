#include "logger.hpp"

#include <iostream>


const std::string bitmutation::ogl::Logger::CurrentTimeStamp()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
    return buf;
}

bitmutation::ogl::Logger::Logger()
{
    std::cout << CurrentTimeStamp() << " " << "Logger::CTOR()" << std::endl;
}

bitmutation::ogl::Logger::~Logger()
{
    std::cout << CurrentTimeStamp() << " " << "Logger::DTOR()" << std::endl;
}

void bitmutation::ogl::Logger::Log(std::string message)
{
    std::cout << CurrentTimeStamp() << " " << message << std::endl;
}

