#ifndef CONFIGSTRUCT_HPP
# define CONFIGSTRUCT_HPP

#include "../../includes/webserv.hpp"

typedef struct s_listen {
	unsigned int	host;
	int				port;
}	t_listen;

#endif