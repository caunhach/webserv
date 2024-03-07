#include "Config.hpp"

Config::Config(std::string	defaultServerPath) {
	std::cout << "configing file " << defaultServerPath << std::endl;
	return ;
}

Config::Config(Config const &src) {
	// if (this != &src)
	// 	this->_servers = src._servers;
}

Config &Config::operator=(Config const &rhs) {
	if (this != &rhs)
		*this = rhs;
}

Config::~Config(void) {}

int	Config::parseConfig(std::string config_file) {
	std::vector<std::string> file = ConfigFileReader::readConfigFile(config_file);
	unsigned int NumberofLines = file.size();
	return NumberofLines;
}