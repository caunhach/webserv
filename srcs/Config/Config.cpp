#include "Config.hpp"

Config::Config(std::string	defaultServerPath) {
	std::cout << "configing file " << defaultServerPath << std::endl;
	return ;
}

Config::Config(Config const &src) {
	if (this != &src)
		*this = src;
}

Config &Config::operator=(Config const &rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

Config::~Config(void) {}

int	Config::parseConfig(std::string config_file) {
	std::vector<std::string> file = ConfigFileReader::readConfigFile(config_file);
	unsigned int NumberofLines = file.size();
	ConfigParser configParser;
	return NumberofLines;
	// return 0;
}

std::vector<ConfigServer> Config::getServers() const {
	return _servers;
}

std::vector<t_listen> Config::getAllListens() const {
    std::vector<t_listen> retListens;

    for (std::vector<ConfigServer>::const_iterator server = _servers.begin(); server != _servers.end(); server++) {
        std::vector<t_listen> listenVec = server->getListen();
        for (std::vector<t_listen>::iterator listen = listenVec.begin(); listen != listenVec.end(); listen++) {
            std::vector<t_listen>::iterator i = retListens.begin();
            for (; i != retListens.end(); i++) {
                if (listen->host == i->host && listen->port == i->port) {
                    break;
                }
            }
            if (i == retListens.end()) {
                retListens.push_back(*listen);
            }
        }
    }
    return retListens;
}