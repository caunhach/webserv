#ifndef CONFIGSTRUCT_HPP
# define CONFIGSTRUCT_HPP

#include "../../includes/webserv.hpp"

#define ConfigMap std::map<std::string, void (ConfigServer::*)(FileVector)>

typedef struct s_listen {
	unsigned int	host;
	int				port;
}	t_listen;

#endif