#ifndef CLUSTER_HPP
# define CLUSTER_HPP

# include "../../includes/webserv.hpp"
# include "../Config/Config.hpp"
# include "Server.hpp"

class Cluster {
	public:
		Cluster(void);
		Cluster(const Cluster & src);
		Cluster & operator=(const Cluster &src);
		~Cluster(void);

		void	configServer(std::string config_file);
		int		initCluster(void);
	private:
		Config		_config;
		std::map<long, Server>	_servers;
		std::map<long, Server *>	_sockets;
		fd_set						_fd_set;
		unsigned int				_fd_size;
		long						_max_fd;
};

#endif