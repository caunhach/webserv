#ifndef CONFIG_HPP

# define CONFIG_HPP

# include "../../includes/webserv.hpp"
# include "ConfigFileReader.hpp"

class Config {
	public:
		Config(std::string config_file = default_config);
		int		parseConfig(std::string config_file);
};

#endif