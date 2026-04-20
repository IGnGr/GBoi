// GBoi.cpp : Defines the entry point for the application.
//

#include "GBoi.h"
#include <SDL3/SDL.h>

using namespace std;

int main()
{
	GBoi gboi("C:/Users/WorkUser/source/repos/GBoi/roms/tetris.gb");
	gboi.run();

	return 0;
}

GBoi::GBoi(const char* filename)
{
	m_game = std::make_shared<GameROM>(filename);
	m_mmu = std::make_shared<MMU>(m_game);
	m_cpu = std::make_shared<CPU>(m_mmu);
	m_ppu = std::make_shared<PPU>(m_mmu);
	m_cpu->initialize();
	m_ppu->initialize();
	
}

GBoi::~GBoi()
{
}

void GBoi::run()
{
	m_cpu->execute();
	m_ppu->renderFrame();
}
