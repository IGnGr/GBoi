#pragma once

class PPU
{


private:



public:


};

class Screen
{

};


class Tile
{
	//Tile VRAM range - 0x8000-0x97FF
	// 8000-87FF: First part of tile set #1
	//8800 - 8FFF: Second part of tile set #1
	//				First part of tile set #2
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

class Layer {

};

class Palette {

};