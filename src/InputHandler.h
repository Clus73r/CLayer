#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#pragma once

#include <unordered_map>
#include <functional>

#include "IInputHandler.h"

typedef std::unordered_map<int, std::function<void()>> InputLayer;

class InputHandler : public IInputHandler
{
private:
	InputLayer activeLayer;
	std::vector<InputLayer> inputLayers;

public:
	InputHandler();
	~InputHandler();
};
#endif