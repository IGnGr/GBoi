// GBoi.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <SDL3/SDL.h>
#include "GameROM.h"
#include "CPU.h"
#include "MMU.h"

class GBoi
{
private:
	std::shared_ptr<GameROM> m_game;
	std::shared_ptr<CPU> m_cpu;
	std::shared_ptr<MMU> m_mmu;



public:
	GBoi(const char* filename);
	~GBoi();
	void run();

};