// GBoi.cpp : Defines the entry point for the application.
//

#include "GBoi.h"

using namespace std;

int main()
{
	GameROM game("C:/Users/WorkUser/source/repos/GBoi/roms/pokemon.gb");
	CPU cpu(make_shared<GameROM>(game));
	cpu.execute();


	return 0;
}

GBoi::GBoi(const char* filename)
{
}

GBoi::~GBoi()
{
}

void GBoi::run()
{
}
