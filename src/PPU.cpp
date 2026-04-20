#include "PPU.h"

constexpr unsigned int BYTE_SIZE = 8;

void PPU::renderFrame()
{
	refreshTileMemory();
	calculateColorPerPixel();
	
}

void PPU::initialize()
{

}

uint16_t PPU::handleIndexing(bool isLCDCBit4Active)
{
	//TODO:
	return 0;
}

void PPU::refreshTileMemory()
{

	//Tile VRAM range - 0x8000-0x97FF
	// 8000-87FF: First part of tile set #1
	//8800 - 8FFF: Second part of tile set #1 / First part of tile set #2
	//9000 - 97FF: Second part of tile set  #2

	//std::copy(m_mmu->getMemory()[0x800], m_mmu->getMemory()[0x97FF], m_tileMap);

}


void PPU::calculateColorPerPixel()
{

	for (int i = 0; i < TOTAL_TILES_NUM;  ++i) {
		for (int j = 0; j < BYTES_PER_TILE - 1; j+=2) {

			uint8_t upperByte = m_tileMap[i].m_TileBytes[j];
			uint8_t lowerByte = m_tileMap[i].m_TileBytes[j + 1];

			for (int k = 0; k < PIXELS_PER_TILE; ++k) {

				unsigned int colorIndex = calculateColorIndex(upperByte, lowerByte, k);

				int pixelIndex = i * PIXELS_PER_TILE + k;

				m_outputPixels[pixelIndex] = (colorIndex == 0 && m_tileMap[i].m_layer == LayerType::OBJECT)
					? GBColor::Transparent() 
					: m_palette.m_colors[colorIndex];

			}
		}
	}
}

unsigned int PPU::calculateColorIndex(const uint8_t upperByte, const uint8_t lowerByte, const int currentBit)
{

	unsigned int mask = (1 << currentBit);

	unsigned int upperBit = (upperByte & mask) >> currentBit;
	unsigned int lowerBit = (lowerByte & mask) >> currentBit;

	unsigned int finalIndex = (upperBit << 1) | lowerBit;

	return finalIndex;

}

