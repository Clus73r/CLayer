#include "InputHandler.h"

#include <iostream>

HHOOK InputHandler::hHook;

LRESULT CALLBACK InputHandler::LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
    // std::cout << p->vkCode << std::endl;

    // auto key = keybinds.find(p->vkCode);
    // if (key != keybinds.end())
    // {
    //     switch (wParam)
    //     {
    //     case WM_KEYDOWN:
    //     case WM_SYSKEYDOWN:
    //         (*key).second.downfunc();
    //         break;
    //     case WM_KEYUP:
    //     case WM_SYSKEYUP:
    //         (*key).second.upfunc();
    //     }
    //     return -1;
    // }
    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

InputHandler::InputHandler()
{
    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, InputHandler::LowLevelKeyboardProc, GetModuleHandle(NULL), 0);
}

InputHandler::~InputHandler()
{
}