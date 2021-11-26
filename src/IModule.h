#pragma once

#include "IInputHandler.h"

class ModuleManager;

class IModule
{
public:
    void Initialize(ModuleManager *mm, IInputHandler *ih)
    {
        moduleManager = mm;
        inputHandler = ih;
    }

protected:
    ModuleManager *moduleManager;
    IInputHandler *inputHandler;
};