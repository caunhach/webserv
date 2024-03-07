#ifndef CONFIGPARSER_HPP
# define CONFIGPARSER_HPP

#include "../../includes/webserv.hpp"

class ConfigParser {
	public:
		ConfigParser(void);
		ConfigParser(ConfigParser const &src);
		ConfigParser &operator=(ConfigParser const &rhs);
		virtual ~ConfigParser(void);
};

#endif