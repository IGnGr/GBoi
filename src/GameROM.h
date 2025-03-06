#pragma once
#include <vector>
#include <string>

class GameROM
{
private:

	std::vector<uint8_t> m_content;
	std::vector<uint8_t> m_header;
	std::string m_titleName;
	bool m_CGBMode;
	bool m_SGBMode;
	uint8_t m_cartridgeType;
	uint8_t m_ROMSize;
	uint8_t m_RAMSize;





public:
	GameROM() {};
	GameROM(const char* filename);

	void readFile(const char* filename);
	void printContent(int from, int until);
	void printHeader();
	std::vector<uint8_t> getContent() const { return m_content; }
};