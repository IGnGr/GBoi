#pragma once
#include <vector>
#include <SDL3/SDL.h>
#include <memory>
#include "MMU.h"

constexpr unsigned int GB_SCREEN_WIDTH = 256;
constexpr unsigned int GB_SCREEN_HEIGHT = 256;
constexpr unsigned int GB_VISIBLE_WIDHT = 160;
constexpr unsigned int GB_VISIBLE_HEIGHT = 144;

constexpr auto BYTES_PER_TILE = 16;
constexpr auto PIXELS_PER_TILE = 64;
constexpr auto TOTAL_TILES_NUM = 384;

enum class LayerType { BACKGROUND, WINDOW, OBJECT };

struct Tile {

	LayerType m_layer;
	uint8_t m_TileBytes[BYTES_PER_TILE];

};

class GBColor {
public:
	constexpr GBColor() : red(0), green(0), blue(0), alpha(255) {}
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t alpha;

	static constexpr GBColor White() { return GBColor(255, 255, 255); };
	static constexpr GBColor LightGrey() { return GBColor(196, 196, 196); };
	static constexpr GBColor DarkGrey() { return GBColor(65, 65, 65); };
	static constexpr GBColor Black() { return GBColor(0, 0, 0); };
	static constexpr GBColor Transparent() { return GBColor(0, 0, 0, 0); };

	constexpr GBColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255)
		: red(red), green(green), blue(blue), alpha(alpha) {
	}


};

class Palette {

public:
	GBColor m_colors[4];

	constexpr Palette() : m_colors{ GBColor(), GBColor(), GBColor(), GBColor() } {}

	static constexpr Palette GB() { 
		return Palette(GBColor::White(), GBColor::LightGrey(), GBColor::DarkGrey(), GBColor::Black());
	};

    constexpr Palette(GBColor zero, GBColor one, GBColor two, GBColor three)
        : m_colors{zero, one, two, three} {}

};

class PPU
{


public:
	PPU(std::shared_ptr<MMU> mmu) : m_palette(Palette::GB()), m_mmu(std::move(mmu)) {};
	~PPU() {};
	void renderFrame();
	void initialize();                                                                   



private:
	Palette m_palette;
	std::shared_ptr<MMU> m_mmu;

	//384 tiles
	//8x8 pixels
	//16 bytes
	//Each line 2 bytes
	//2bpp
	//4 colors
	//Background/window maps
	//object sprites
	//Color 0 in objects -> trasparent
	Tile m_tileMap[TOTAL_TILES_NUM] = {};
	unsigned int m_internalWidth = GB_SCREEN_WIDTH;
	unsigned int m_internalHeight = GB_SCREEN_HEIGHT;
	unsigned int m_backgroundViewportY = 0;
	unsigned int m_backgroundViewportX = 0;
	
	GBColor m_outputPixels[TOTAL_TILES_NUM * PIXELS_PER_TILE] = {};

	uint16_t handleIndexing(bool isLCDCBit4Active);
	void refreshTileMemory();
	void calculateColorPerPixel();
	unsigned int calculateColorIndex(const uint8_t upperByte, const uint8_t lowerByte, const int currentBit);

};






