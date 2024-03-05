#ifndef CLUSTER_HPP
# define CLUSTER_HPP

# include "../../includes/webserv.hpp"
# include "../Config/Config.hpp"

class Cluster {
	public:
		Cluster(void);
		void	configServer(std::string config_file);
	private:
		Config		_config;
};

#endif