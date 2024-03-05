#ifndef CLUSTER_HPP
# define CLUSTER_HPP

# include "../../includes/webserv.hpp"
# include "../Config/Config.hpp"

class Cluster {
	public:
		Cluster(void);
	private:
		Config		_config;
};

#endif