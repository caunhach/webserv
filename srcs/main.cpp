#include "../includes/webserv.hpp"
#include "Server/Cluster.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		Cluster cluster;
		try {
			cluster.configServer(argv[1]);
		} catch (std::exception &e) {
			// std::cout << e.what() << std::endl;
			std::cout << "Invalid config file" << std::endl;
		}
	}
	else
	{
		std::cout << "Invalid number of arguments" << std::endl;
	}
}