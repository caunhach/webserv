#include "ConfigFileReader.hpp"

ConfigFileReader::ConfigFileReader(void) {}

ConfigFileReader::ConfigFileReader(ConfigFileReader const &src) {
	if (this != &src)
		*this = src;
}

ConfigFileReader &ConfigFileReader::operator=(ConfigFileReader const &rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

ConfigFileReader::~ConfigFileReader(void) {}

std::vector<std::string> ConfigFileReader::readConfigFile(std::string config_file)
{
	std::vector<std::string> lines;
	std::ifstream file(config_file);

	if (!file.is_open())
		throw ConfigFileReader::FileConflictException();
	
	std::string line;
	while (std::getline(file, line)) {
		lines.push_back(line);
	}

	file.close();
	return lines;
}

const char* ConfigFileReader::FileConflictException::what() const throw() {
	return ("File not found or unable to open");
}