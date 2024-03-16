#ifndef CONFIGPARSER_HPP
# define CONFIGPARSER_HPP

#include "../../includes/webserv.hpp"
#include "ConfigStruct.hpp"
#include "ConfigServer.hpp"

class ConfigParser {
	public:
		ConfigParser(void);
		ConfigParser(ConfigParser const &src);
		ConfigParser &operator=(ConfigParser const &rhs);
		virtual ~ConfigParser(void);
	private:
		ConfigServer		_configserver;
};

#endif