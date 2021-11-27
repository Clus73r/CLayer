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

    M_MouseControl *m = static_cast<M_MouseControl *>(moduleManager.AddModule<M_MouseControl>());
    m->EnableModule();

    configReader.ReadConfigFile("Config/clayerrc.cfg");

    MSG msg;
    while (!GetMessage(&msg, NULL, NULL, NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}