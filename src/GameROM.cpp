#include "GameROM.h"
#include "Utils.h"

#include <fstream>
#include <iostream>
#include <string>
#include <cctype> 


GameROM::GameROM(const char* filename)
{
	readFile(filename);
	//header is from 0x0100 to 0x014F
	m_header = std::vector<uint8_t>(m_content.begin() + 0x0100, m_content.begin() + 0x0150);
	//title is from 0x0134 to 0x0143
	m_titleName = std::string(m_content.begin() + 0x0134, m_content.begin() + 0x0143);
	m_CGBMode = m_content[0x0143] == 0x80 || m_content[0x0146] == 0xC0;
	m_SGBMode = m_content[0x0146] == 0x03;
	m_cartridgeType = m_content[0x0147];
	m_ROMSize = m_content[0x0148];
	m_RAMSize = m_content[0x0149];
}

void GameROM::readFile(const char* filename)
{
	std::vector<uint8_t> rawBuffer;
    std::ifstream input;

	input.open(filename, std::ios::binary);
	
	// Sets buffer position to the end of the file
	input.seekg(0, std::ios::end);
	// Gets the size of the file
	size_t size = input.tellg();
	// Sets buffer position to the beginning of the file
	input.seekg(0, std::ios::beg);

	//Resizes the buffer to the size of the file
	rawBuffer.resize(size / sizeof(uint8_t));

	//Reads the file into the buffer
	input.read((char*)rawBuffer.data(), size);

	//We store the ROM content into our object
	m_content = rawBuffer;

    input.close();
}

void GameROM::printContent(int from, int until)
{
	for (auto i = from; i <= from + (until - from); i++)
	{
		std::string c = Utils::ToBase(m_content[i], 16);
		if (m_content[i] < 0xF) c = "0" + c;
		if (m_content[i] == '\0') c = "00";


		
		std::cout << '[' << c << ']';
	}
}

void GameROM::printHeader()
{
	int count = 0x100;

	for (auto i : m_header)
	{
		std::string c = Utils::ToBase(i, 16);
		if (i < 0xF) c = "0" + c;
		if (i == '\0') c = "00";


		if (count % 4 == 0) std::cout << std::endl << "0x" << Utils::ToBase(count, 16) << " ";

		std::cout << '[' << c << ']';



		count++;

	}
}
