#pragma once
#include <vector>
#include <SDL3/SDL.h>
#include <memory>
#include "MMU.h"

constexpr unsigned int GB_SCREEN_WIDTH = 256;
constexpr unsigned int GB_SCREEN_HEIGHT = 256;
constexpr unsigned int GB_VISIBLE_WIDHT = 160;
constexpr unsigned int GB_VISIBLE_HEIGHT = 144;

class Color {


public:
	Color() {}
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t alpha;

	static constexpr Color White() { return Color(255, 255, 255); };
	static constexpr Color LightGrey() { return Color(196, 196, 196); };
	static constexpr Color DarkGrey() { return Color(65, 65, 65); };
	static constexpr Color Black() { return Color(0, 0, 0); };

	constexpr Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255)
		: red(red), green(green), blue(blue), alpha(alpha) {
	}


};

class Palette {



public:
	Palette() {}
	Color zero;
	Color one;
	Color two;
	Color three;

	static constexpr Palette GB() { return Palette(Color::White(), Color::LightGrey(), Color::DarkGrey(), Color::Black()); };

	constexpr Palette(Color zero, Color one, Color two, Color three)
		:zero(zero), one(one), two(two), three(three) {
	}
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
	unsigned int m_internalWidth = GB_SCREEN_WIDTH;
	unsigned int m_internalHeight = GB_SCREEN_HEIGHT;
	unsigned int m_backgroundViewportY = 0;
	unsigned int m_backgroundViewportX = 0;

};

class Layer {

	//TileMap m_tilemap;
	enum class LayerType { BACKGROUND, WINDOW };

};





class TileMap
{
	//Tile VRAM range - 0x8000-0x97FF
	// 8000-87FF: First part of tile set #1
	//8800 - 8FFF: Second part of tile set #1 / First part of tile set #2
	//9000 - 97FF: Second part of tile set #2
	//384 tiles
	//8x8 pixels
	//16 bytes
	//Each line 2 bytes
	//2bpp
	//4 colors
	//Background/window maps
	//object sprites
	//Color 0 in objects -> trasparent


};




