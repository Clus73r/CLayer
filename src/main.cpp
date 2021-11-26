#include <iostream>

#include "ModuleManager.h"
#include "InputHandler.h"
#include "ConfigReader.h"
#include "M_MouseControl.h"

int main()
{
    InputHandler inputHandler;
    ModuleManager moduleManager(&inputHandler);
    ConfigReader configReader(&inputHandler, &moduleManager);

    moduleManager.AddModule<M_MouseControl>();

    configReader.ReadConfigFile("Config/clayerrc.cfg");

    return 0;
}