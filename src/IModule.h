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

    virtual void EnableModule() = 0;
    virtual void DisableModule() = 0;
    virtual void ToggleModule() = 0;

protected:
    ModuleManager *moduleManager;
    IInputHandler *inputHandler;
};