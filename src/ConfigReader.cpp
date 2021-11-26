#include "ConfigReader.h"

#include <regex>
#include <fstream>
#include <iostream>

bool ConfigReader::ReadPropertyLine(const std::string &line)
{
    std::regex rgx("^(?!#)([a-zA-Z0-9_]*):\\s*([a-zA-Z0-9_]*)\\s*=\\s*([a-zA-Z0-9_]*)");
    std::smatch matches;
    if (std::regex_search(line, matches, rgx) && matches.size() == 4)
    {
        std::string line_type = matches[1];
        std::string line_identifier = matches[2];
        std::string line_value = matches[3];
        std::cout << line_type << std::endl;
        std::cout << line_identifier << std::endl;
        std::cout << line_value << std::endl;
        return true;
    }
    return false;
}

bool ConfigReader::ReadHeaderLine(const std::string &line)
{
    return false;
}

void ConfigReader::ReadConfigFile(const std::string &path)
{
    std::ifstream f(path);
    std::string line;

    while (std::getline(f, line))
    {
        if (ReadPropertyLine(line))
            continue;
    }
}