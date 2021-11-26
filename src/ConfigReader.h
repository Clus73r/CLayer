#ifndef CONFIGREADER_H
#define CONFIGREADER_H
#pragma once

#include <string>

#include "InputHandler.h"
#include "ModuleManager.h"

class ConfigReader
{
private:
	IInputHandler *inputHandler;
	ModuleManager *moduleManager;

	bool ReadPropertyLine(const std::string &line);
	bool ReadHeaderLine(const std::string &line);

public:
	void ReadConfigFile(const std::string &path);

	ConfigReader(IInputHandler *ih, ModuleManager *mm) : inputHandler(ih), moduleManager(mm) {}
	~ConfigReader() = default;
};
#endif