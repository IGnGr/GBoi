#include "MMU.h"

MMU::MMU(std::shared_ptr<GameROM> game)
{
	m_game = game;
	m_memory = m_game->getContent();
}

MMU::~MMU()
{
}

void MMU::printMemory(int from, int until)
{
}

uint16_t MMU::readWord(uint16_t address)
{
	return m_memory[address];
}

uint8_t MMU::readByte(uint16_t address)
{
	return m_memory[address];
}
