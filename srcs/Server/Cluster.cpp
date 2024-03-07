#include "Cluster.hpp"

Cluster::Cluster(void): _config(default_config)
{
}

void	Cluster::configServer(std::string config_file)
{
	std::cout << _config.parseConfig(config_file) << std::endl;
}