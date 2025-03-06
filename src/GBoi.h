// GBoi.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <SDL3/SDL.h>
#include "GameROM.h"
#include "CPU.h"

class GBoi
{
private:
	std::shared_ptr<GameROM> m_game;
	std::shared_ptr<CPU> m_cpu;

public:
	GBoi(const char* filename);
	~GBoi();
	void run();

};