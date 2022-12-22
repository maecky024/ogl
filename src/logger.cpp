#include "logger.hpp"

#include <iostream>

bitmutation::ogl::Logger::Logger()
{
    std::cout << "Logger::CTOR()" << std::endl;
}

bitmutation::ogl::Logger::~Logger()
{
    std::cout << "Logger::DTOR()" << std::endl;
}

void bitmutation::ogl::Logger::Log(std::string message)
{
    std::cout << message << std::endl;
}

