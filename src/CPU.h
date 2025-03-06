#pragma once
#include "GameROM.h"
#include <memory>
#include <unordered_map>
#include <functional>
#include <vector>
#include <cstdint> 
#include "MMU.h"


class InstructionSet;

class CPU
{



	struct Register
	{
		uint16_t value = 0;

		uint8_t getHi() const { return (uint8_t)(value >> 8); }
		void setHi(uint8_t hi) { value = (value & 0x00FF) | (hi << 8); }

		uint8_t getLo() const { return  (uint8_t)(value & 0x00FF); }
		void setLo(uint8_t lo) { value = (value & 0xFF00) | lo; }

	};

	

private:
	//Program Counter
	uint16_t m_PC = 0;
	//Stack Pointer
	uint16_t m_SP = 0;

	//Accumulator & Flags
	Register m_AF;

	//General Purpose Registers
	Register m_BC;
	Register m_DE;
	Register m_HL;



	//Clock
	uint8_t m_clock = 0;
	//Zero Flag
	bool m_zeroFlag = false;
	//Carry Flag
	bool m_carryFlag = false;
	//Half Carry Flag
	bool m_halfCarryFlag = false;
	//Subtract Flag
	bool m_subtractFlag = false;

	uint8_t m_currentInstruction = 0;

	std::unique_ptr<InstructionSet> m_instructionSet;
	std::shared_ptr<MMU> m_MMU;
	std::shared_ptr<GameROM> m_game;



public:
    CPU();
    CPU(std::shared_ptr<GameROM> game);
    ~CPU();
	void execute();
	void fetchNextInstruction();
    void executeNextInstruction();
	void decodeNextInstruction();

	enum RegisterType
	{
		A, F, B, C, D, E, H, L, AF, BC, DE, HL
	};



    void printState() const;
	void initialize();
	void getRegister(Register reg);
	uint16_t getPC() const { return m_PC; }
	template <typename T>
	T getRegisterValue(RegisterType regType) const;
	void setRegisterValue(RegisterType regType, uint16_t value);
	void setRegisterValue(RegisterType regType, uint8_t value);
};