#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include <string>

#pragma once

namespace bitmutation 
{ 
	namespace ogl 
	{
		class Configuration 
		{
		public:
			static Configuration &getInstance(std::string file) {
			static Configuration instance(file);
			return instance;
		}

		private:
			Configuration(std::string file);
			~Configuration();

		public:

			Configuration(Configuration const &) = delete;
			void operator=(Configuration const &) = delete;
		};
    }
}
#endif