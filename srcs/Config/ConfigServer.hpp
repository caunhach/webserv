#ifndef CONFIGSERVER_HPP
# define CONFIGSERVER_HPP

#include "../../includes/webserv.hpp"
#include "ConfigStruct.hpp"

class ConfigServer {
	public:
		ConfigServer(void);
		ConfigServer(ConfigServer const &src);
		ConfigServer &operator=(ConfigServer const &rhs);
		virtual ~ConfigServer(void);
		class InvalidArgumentException : public std::exception{
			virtual const char* what() const throw();
		};
		//Getters
		std::vector<t_listen>	getListen(void) const;
		std::string				getRoot(void) const;
		std::vector<std::string>	getServerName(void) const;
		std::map<int, std::string>	getErrorPage(void) const;
		int						getClientMaxBodySize(void) const;
		std::map<std::string, std::string>	getCgiParam(void) const;
		std::string				getCgiPass(void) const;
		std::map<std::string, ConfigServer>	getLocation(void) const;
		std::set<std::string>	getAllowedMethods(void) const;
		std::vector<std::string>	getIndex(void) const;
		bool					getAutoindex(void) const;
		std::string				getAlias(void) const;
		bool					getAliasSet(void) const;
		//Setters
		void					setListen(std::vector<t_listen> listen);
		void					setRoot(std::vector<std::string> root);
		void					setServerName(std::vector<std::string> server_name);
		void					setErrorPage(std::map<int, std::string> error_page);
		void					setClientMaxBodySize(int client_max_body_size);
		void					setCgiParam(std::map<std::string, std::string> cgi_param);
		void					setCgiPass(std::string cgi_pass);
		void					setLocation(std::map<std::string, ConfigServer> location);
		void					setAllowedMethods(std::set<std::string> allowed_methods);
		void					setIndex(std::vector<std::string> index);
		void					setAutoindex(bool autoindex);
		void					setAlias(std::string alias);
		void					setAliasSet(bool aliasSet);
	private:
		std::vector<t_listen> _listen;
		std::string _root;
		std::vector<std::string> _server_name;
		std::map<int, std::string> _error_page;
		int			_client_max_body_size;
		std::map<std::string, std::string> _cgi_param;
		std::string 	_cgi_pass;
		std::map<std::string, ConfigServer> _location;
		std::set<std::string> _allowed_methods;
		std::vector<std::string> _index;
		bool		_autoindex;
		std::string	_alias;
		bool		_aliasSet;
		static ConfigServer		_defaultConfigServer;
};

#endif