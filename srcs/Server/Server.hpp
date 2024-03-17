#ifndef SERVER_HPP
# define SERVER_HPP

# include "../../includes/webserv.hpp"
# include "../Config/ConfigStruct.hpp"

class Server {
	public:
		Server(void);
		Server(const t_listen &listen);
		Server & operator=(const Server &src);
		~Server(void);

		int		initServer(void);
		long	acceptConnection(void);
		int		sendResponse(long socket);
		void	printResponse(const std::string &response);
		int		recv(long socket);
		void	closeSocket(long socket);
		void	closeFd(void);
		void	setAddr(void);
		long	getFD(void);
	private:
		long		_fd;
		t_listen	_listen;
		std::map<long, std::string>	_requests;
		struct sockaddr_in		_addr;
};

#endif