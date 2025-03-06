#pragma once
#include <vector>
#include <string>
#include "GameROM.h"
#include <memory>

class MMU
{
private:
	std::vector<uint8_t> m_memory;

	//Game ROM
	std::shared_ptr<GameROM> m_game;

	int nBanks;
public:
	MMU(std::shared_ptr<GameROM> game);
	~MMU();
	void printMemory(int from, int until);
	std::vector<uint8_t> getMemory() const { return m_memory; }
	uint16_t readWord(uint16_t address);
	uint8_t readByte(uint16_t address);
};