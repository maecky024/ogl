#include "configuration.hpp"
#include <iostream>
#include <fstream>
#include "logger.hpp"

std::string bitmutation::ogl::Configuration::ReadConfig(std::string key)
{
    std::ifstream infile(filename);
    std::string line;
    int linenum = 0;
    while (std::getline(infile, line))
    {
        std::size_t found = line.find(key);
        if (found!=std::string::npos)
        {
            std::size_t pos = line.find("=");
            return line.substr(pos+1);
        }
        linenum++;
    }
    return "";
}


bitmutation::ogl::Configuration::Configuration(std::string file)
{
    filename = file;
    Logger::getInstance().Log("Loading config from " + file);
}

bitmutation::ogl::Configuration::~Configuration()
{
    
}
