#include "MMU.h"
#include <stdexcept>

MMU::MMU(std::shared_ptr<GameROM> game)
{
	m_game = game;

	std::vector<uint8_t> romContent = m_game->getContent();

	//We copy the game content into memory
	m_memory.reserve(0xFFFF);
	m_memory.insert(m_memory.begin(), romContent.begin(), romContent.end());

	//We initialize the MBC with the ROM banks
	initializeMBC(m_game->getCartridgeType());
	updateBank();
}


//The MBC is mapped at 4000 - 7FFF
void MMU::updateBank()
{
	std::vector<uint8_t> bank = m_mbc->getCurrentBank();
	m_memory.insert(m_memory.begin() + 0x4000, bank.begin(), bank.end());
}

MMU::~MMU()
{
}

void MMU::initializeMBC(uint8_t cartridgeType)
{
	int nBanks = 1 << m_game->getROMSize();

	switch (cartridgeType)
	{
	case 0x00:
		m_mbc = std::make_unique<MBC0>(nBanks);
		break;
		/*
	case 0x01:
		m_mbc = std::make_unique<MBC1>(nBanks);
		break;
	case 0x02:
		m_mbc = std::make_unique<MBC1>(nBanks);
		break;
		
	case 0x03:
		m_mbc = std::make_unique<MBC1>(nBanks);
		break;

	case 0x05:
		m_mbc = std::make_unique<MBC2>(nBanks);
		break;
	case 0x06:
		m_mbc = std::make_unique<MBC2>(nBanks);
		break;

		

	case 0x1B:	
		m_mbc = std::make_unique<MBC5>(nBanks);
		break;
		*/

		default:
			throw std::invalid_argument("Invalid cartridge type");
		break;
	}
	

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

void MMU::setWord(uint16_t address, uint16_t value)
{

}

void MMU::setWord(uint16_t address, uint8_t value)
{
}
