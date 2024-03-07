#ifndef CONFIGFILEREADER_HPP
# define CONFIGFILEREADER_HPP

#include "../../includes/webserv.hpp"

class ConfigFileReader {
	public:
		ConfigFileReader(void);
		ConfigFileReader(ConfigFileReader const &src);
		ConfigFileReader &operator=(ConfigFileReader const &rhs);
		virtual ~ConfigFileReader(void);

		static std::vector<std::string> readConfigFile(std::string config_file);
		class FileConflictException : public std::exception{
			virtual const char* what() const throw();
		};
};

#endif