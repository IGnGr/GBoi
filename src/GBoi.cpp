// GBoi.cpp : Defines the entry point for the application.
//

#include "GBoi.h"

using namespace std;

int main()
{
	GBoi gboi("C:/Users/WorkUser/source/repos/GBoi/roms/tetris.gb");
	gboi.run();

	return 0;
}

GBoi::GBoi(const char* filename)
{
	m_game = make_shared<GameROM>(filename);
	m_mmu = make_shared<MMU>(m_game);
	m_cpu = make_shared<CPU>(m_mmu);
	m_cpu->initialize();

}

GBoi::~GBoi()
{
}

void GBoi::run()
{
	m_cpu->execute();
}
