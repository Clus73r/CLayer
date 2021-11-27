#include "M_MouseControl.h"

#include <thread>
#include <mutex>
#include <iostream>
#include "Windows.h"
#include <functional>

void M_MouseControl::Loop()
{
    for (;;)
    {
        std::cout << "aa" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        if (stop_signal)
        {
            stop_signal = false;
            break;
        }
    }
}

void M_MouseControl::EnableModule()
{
    if (!isRunning)
    {
        std::thread t(&M_MouseControl::Loop, this);
        isRunning = true;
    }
}

void M_MouseControl::DisableModule()
{
    if (isRunning)
    {
        stop_signal = true;
        isRunning = false;
    }
}

void M_MouseControl::ToggleModule()
{
    if (isRunning)
    {
        DisableModule();
    }
    else
    {
        EnableModule();
    }
}

M_MouseControl::M_MouseControl()
{
}

M_MouseControl::~M_MouseControl()
{
}