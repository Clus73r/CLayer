#ifndef M_MOUSECONTROL_H
#define M_MOUSECONTROL_H
#pragma once

#include <atomic>
#include <thread>
#include "IModule.h"

class M_MouseControl : public IModule
{
private:
	std::atomic_bool stop_signal = false;
	std::thread *loop_thread = nullptr;

	void Loop();

public:
	void EnableModule() override;
	void DisableModule() override;
	void ToggleModule() override;

	M_MouseControl();
	~M_MouseControl();
};
#endif