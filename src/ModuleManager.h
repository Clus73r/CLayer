#ifndef MODULEMANAGER_H
#define MODULEMANAGER_H
#pragma once

#include <vector>

#include "IModule.h"
#include "IInputHandler.h"

class ModuleManager
{
public:
	ModuleManager(IInputHandler *inputHandler){};
	~ModuleManager() = default;

	template <class T>
	IModule *AddModule()
	{
		IModule *new_module = new T();
		new_module->Initialize(this, inputHandler);
		modules.push_back(new_module);
		return new_module;
	}

private:
	IInputHandler *inputHandler;
	std::vector<IModule *> modules;
};
#endif