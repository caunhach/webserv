#include "Cluster.hpp"

Cluster::Cluster(void): _config(default_config)
{
}

Cluster::Cluster(const Cluster &src)
{
	if (this != &src)
	{
		*this = src;
	}
}

Cluster & Cluster::operator=(const Cluster &src)
{
	_config = src._config;
	_servers = src._servers;
	_fd_set = src._fd_set;
	_fd_size = src._fd_size;
	_max_fd = src._max_fd;
	return (*this);
}

Cluster::~Cluster(void)
{
}

void	Cluster::configServer(std::string config_file)
{
	std::cout << _config.parseConfig(config_file) << std::endl;
}

int		Cluster::initCluster(void)
{
	std::vector<t_listen>	LstnVect = _config.getAllListens();

	FD_ZERO(&_fd_set);
	_fd_size = LstnVect.size();
	_max_fd = 0;

	for ( std::vector<t_listen>::const_iterator lstn = LstnVect.begin() ; lstn != LstnVect.end() ; lstn++ )
	{
		Server		serv(*lstn);
		long		fd;

		if (serv.initServer() != -1)
		{
			fd = serv.getFD();
			FD_SET(fd, &_fd_set);
			_servers.insert(std::make_pair(fd, serv));
			if (fd > _max_fd)
				_max_fd = fd;
			std::cout << "Setting up " << lstn->host << ":" << lstn->port << "..." << std::endl;
		}
	}

	if (_max_fd == 0)
	{
		std::cerr << RED << "Could not setup cluster !" << RESET << std::endl;
		return (-1);
	}
	else
		return (0);
}