#include "ConfigServer.hpp"

ConfigServer::ConfigServer(void) : _root(""), _client_max_body_size(0), _autoindex(false), _aliasSet(false) {}

ConfigServer::ConfigServer(ConfigServer const &src) {
	if (this != &src)
		*this = src;
}

ConfigServer &ConfigServer::operator=(ConfigServer const &rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

ConfigServer::~ConfigServer(void) {}

std::vector<t_listen>	ConfigServer::getListen(void) const
{
	return _listen;
}

std::string				ConfigServer::getRoot(void) const
{
	return _root;
}

std::vector<std::string>	ConfigServer::getServerName(void) const
{
	return _server_name;
}

std::map<int, std::string>	ConfigServer::getErrorPage(void) const
{
	return _error_page;
}

int						ConfigServer::getClientMaxBodySize(void) const
{
	return _client_max_body_size;
}

std::map<std::string, std::string>	ConfigServer::getCgiParam(void) const
{
	return _cgi_param;
}

std::string				ConfigServer::getCgiPass(void) const
{
	return _cgi_pass;
}

std::map<std::string, ConfigServer>	ConfigServer::getLocation(void) const
{
	return _location;
}

std::set<std::string>	ConfigServer::getAllowedMethods(void) const
{
	return _allowed_methods;
}

std::vector<std::string>	ConfigServer::getIndex(void) const
{
	return _index;
}

bool					ConfigServer::getAutoindex(void) const
{
	return _autoindex;
}

std::string				ConfigServer::getAlias(void) const
{
	return _alias;
}

bool					ConfigServer::getAliasSet(void) const
{
	return _aliasSet;
}

void					ConfigServer::setListen(std::vector<t_listen> listen)
{
	_listen = listen;
}

void					ConfigServer::setRoot(std::vector<std::string> root)
{
	if (_root != "" || root.size() != 1)
		throw InvalidArgumentException();
	_root = root[0];
}

void					ConfigServer::setServerName(std::vector<std::string> server_name)
{
	if (server_name.size() == 0)
		throw InvalidArgumentException();
	_server_name = server_name;
}

void					ConfigServer::setErrorPage(std::map<int, std::string> error_page)
{
	_error_page = error_page;
}

void					ConfigServer::setClientMaxBodySize(int client_max_body_size)
{
	_client_max_body_size = client_max_body_size;
}

void					ConfigServer::setCgiParam(std::map<std::string, std::string> cgi_param)
{
	_cgi_param = cgi_param;
}

void					ConfigServer::setCgiPass(std::string cgi_pass)
{
	_cgi_pass = cgi_pass;
}

void					ConfigServer::setLocation(std::map<std::string, ConfigServer> location)
{
	_location = location;
}

void					ConfigServer::setAllowedMethods(std::set<std::string> allowed_methods)
{
	_allowed_methods = allowed_methods;
}

void					ConfigServer::setIndex(std::vector<std::string> index)
{
	_index = index;
}

void					ConfigServer::setAutoindex(bool autoindex)
{
	_autoindex = autoindex;
}

void					ConfigServer::setAlias(std::string alias)
{
	_alias = alias;
	_aliasSet = true;
}

void					ConfigServer::setAliasSet(bool aliasSet)
{
	_aliasSet = aliasSet;
}