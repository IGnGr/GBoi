#pragma once
#include <vector>
#include <string>
#include <memory>

#include "GameROM.h"
#include "MBC.h"

class MMU
{
private:
	std::vector<uint8_t> m_memory;

	//Game ROM
	std::shared_ptr<GameROM> m_game;

	std::unique_ptr<MBC> m_mbc;

public:
	MMU(std::shared_ptr<GameROM> game);
	~MMU();
	void initializeMBC(uint8_t cartridgeType);
	void updateBank();
	void printMemory(int from, int until);
	std::vector<uint8_t> getMemory() const { return m_memory; }
	uint16_t readWord(uint16_t address);
	uint8_t readByte(uint16_t address);
	void setWord(uint16_t address, uint16_t value);
	void setByte(uint16_t address, uint8_t value);

};