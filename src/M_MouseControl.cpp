#include "M_MouseControl.h"

#include <mutex>
#include <iostream>
#include "Windows.h"
#include <functional>
#include <bitset>

void M_MouseControl::Loop()
{
    for (;;)
    {
        std::cout << std::bitset<8>(GetKeyState(74)) << std::endl;
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
    if (!loop_thread)
    {
        loop_thread = new std::thread(&M_MouseControl::Loop, this);
    }
}

void M_MouseControl::DisableModule()
{
    if (loop_thread)
    {
        stop_signal = true;
        loop_thread->join();
        loop_thread = nullptr;
    }
}

void M_MouseControl::ToggleModule()
{
    if (loop_thread)
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