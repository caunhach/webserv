#include "Server.hpp"

Server::Server(void) { }

Server::Server(const t_listen &listen) : _listen(listen), _fd(-1)
{
	this->setAddr();
}

Server & Server::operator=(const Server &src)
{
	_listen = src._listen;
	_fd = src._fd;
	_addr = src._addr;
	return (*this);
}

Server::~Server(void) { }

int		Server::initServer(void)
{
	_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (_fd == -1)
	{
		std::cerr << RED << "Could not create server." << RESET << std::endl;
		return (-1);
	}
	this->setAddr();
	if (bind(_fd, (struct sockaddr *)&_addr, sizeof(_addr)) == -1)
	{
		std::cerr << RED << "Could not bind port " << _listen.port << "." << RESET << std::endl;
		return (-1);
	}
	if (listen(_fd, 1000) == -1)
	{
		std::cerr << RED << "Could not listen." << RESET << std::endl;
		return (-1);
	}
	return (0);
}

long	Server::acceptConnection(void)
{
	long	socket = accept(_fd, NULL, NULL);
	if (socket == -1)
	{
		std::cerr << RED << "Could not accept connection." << RESET << std::endl;
		return (-1);
	} else {
		// This line sets the accepted socket (socket) to non-blocking mode. fcntl is a system call for performing various operations on file descriptors. F_SETFL indicates that we want to set a file descriptor flag, and O_NONBLOCK sets the non-blocking mode for the socket.
		fcntl(socket, F_SETFL, O_NONBLOCK);
		// This line inserts the accepted socket (socket) into a data structure called _requests. It likely represents a collection of active connections. The socket is inserted as a key-value pair, with the socket descriptor as the key and an empty string as the value.
		_requests.insert(std::make_pair(socket, ""));
	}
	return (socket);
}

int Server::sendResponse(long socket)
{
    static std::map<long, size_t> sent;

    // Initialize sent count if not present
    if (sent.find(socket) == sent.end())
        sent[socket] = 0;

    // Print response if OUT flag is set and no data has been sent yet
    if (OUT && sent[socket] == 0)
    {
        printResponse(_requests[socket]);
    }

    // Extract data to send
    std::string str = _requests[socket].substr(sent[socket], RECV_SIZE);
    int ret = ::send(socket, str.c_str(), str.size(), 0);

    // Handle send errors
    if (ret == -1)
    {
        this->closeSocket(socket);
        sent[socket] = 0;
        return -1;
    }

    // Update sent count
    sent[socket] += ret;

    // Check if the entire request has been sent
    if (sent[socket] >= _requests[socket].size())
    {
        _requests.erase(socket);
        sent[socket] = 0;
        return 0; // Entire request sent
    }

    return 1; // Partial send
}

// Function to print response
void Server::printResponse(const std::string& response)
{
    std::cout << "\rResponse :                \n";

    if (response.size() < 1000)
    {
        std::cout << "[" << GREEN << response << RESET << "]\n\n";
    }
    else
    {
        std::string truncated_response = response.substr(0, 1000);
        std::string tail = response.substr(response.size() - 10, 15);
        std::cout << "[" << GREEN << truncated_response << "..." << tail << RESET << "]\n\n";
    }
}

int Server::recv(long socket)
{
    char buffer[RECV_SIZE] = {0};
    int ret = ::recv(socket, buffer, RECV_SIZE - 1, 0);

    if (ret == 0 || ret == -1)
    {
        this->closeSocket(socket);
        if (!ret)
            std::cout << "\rConnection was closed by client.\n" << std::endl;
        else
            std::cout << "\rRead error, closing connection.\n" << std::endl;
        return -1;
    }

    _requests[socket] += std::string(buffer);

    size_t headerEnd = _requests[socket].find("\r\n\r\n");
    if (headerEnd != std::string::npos)
    {
        if (_requests[socket].find("Content-Length: ") == std::string::npos)
        {
            if (_requests[socket].find("Transfer-Encoding: chunked") != std::string::npos)
            {
                if (checkStrEnd(_requests[socket], "0\r\n\r\n") == 0)
                    return 0;
                else
                    return 1;
            }
            else
                return 0;
        }

        size_t contentLengthPos = _requests[socket].find("Content-Length: ");
        size_t len = std::atoi(_requests[socket].substr(contentLengthPos + 16, 10).c_str());
        if (_requests[socket].size() >= len + headerEnd + 4)
            return 0;
        else
            return 1;
    }

    return 1;
}


void Server::closeSocket(long socket)
{
    if (socket > 0)
        ::close(socket); // Close the socket if it's valid
    _requests.erase(socket); // Remove the socket entry from the requests map
}

void Server::closeFd()
{
    if (_fd > 0)
        ::close(_fd); // Close the file descriptor if it's valid
    _fd = -1; // Reset the file descriptor to -1
}


void	Server::setAddr(void)
{
	std::memset((char *)&_addr, 0, sizeof(_addr));
	//  indicates that this socket address is for IPv4.
	_addr.sin_family = AF_INET;
	// converts the host byte order to network byte order for a 32-bit unsigned integer
	_addr.sin_port = htons(_listen.port);
	//  converting the host byte order to network byte order for a 16-bit unsigned integer representing the port number.
	_addr.sin_addr.s_addr = htonl(_listen.host);
}

long	Server::getFD(void)
{
	return (_fd);
}