#include "Config.hpp"

Config::Config(std::string	defaultServerPath) {
	std::cout << "configing file " << defaultServerPath << std::endl;
	return ;
}

int	Config::parseConfig(std::string config_file) {
	std::vector<std::string> file = ConfigFileReader::readConfigFile(config_file);
	unsigned int NumberofLines = file.size();
	return NumberofLines;
}