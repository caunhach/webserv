#include "ConfigParser.hpp"

ConfigParser::ConfigParser(void) : _configserver() 
{
	// std::cout << _configserver.getAutoindex() << std::endl;
}

ConfigParser::ConfigParser(ConfigParser const &src) {
	if (this != &src)
		*this = src;
}

ConfigParser &ConfigParser::operator=(ConfigParser const &rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

ConfigParser::~ConfigParser(void) {}