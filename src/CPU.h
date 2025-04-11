#pragma once
#include "GameROM.h"
#include <memory>
#include <unordered_map>
#include <functional>
#include <vector>
#include <cstdint> 
#include "MMU.h"


class InstructionSet;
 
class CPU : public std::enable_shared_from_this<CPU>
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
	Register m_SP;

	//Accumulator & Flags
	Register m_AF;

	//General Purpose Registers
	Register m_BC;
	Register m_DE;
	Register m_HL;

	uint8_t m_clock = 0;

	bool m_zeroFlag = false;
	bool m_carryFlag = false;
	bool m_halfCarryFlag = false;
	bool m_subtractFlag = false;
	bool m_interruptsFlag = false;

	uint8_t m_currentInstruction = 0;

	std::shared_ptr<InstructionSet> m_instructionSet;
	std::shared_ptr<MMU> m_mmu;
	std::shared_ptr<GameROM> m_game;



public:
    CPU();
    CPU(std::shared_ptr<MMU> mmu);
    ~CPU();
	void execute();
	void fetchNextInstruction();
    void executeNextInstruction();
	void decodeNextInstruction();

	enum RegisterType
	{
		A, F, B, C, D, E, H, L, AF, BC, DE, HL, SP
	};



    void printState() const;
	void initialize();
	uint16_t getPC() const { return m_PC; }
	template <typename T>
	T getRegisterValue(RegisterType regType) const;

	uint16_t getZeroFlag() const { return m_zeroFlag; }
	uint16_t getCarryFlag() const { return m_carryFlag; }
	uint16_t getHalfCarryFlag() const { return m_halfCarryFlag; }
	uint16_t getSubstractFlag() const { return m_subtractFlag; }
	uint16_t getInterruptsFlag() const { return m_interruptsFlag; }

	RegisterType getHi(RegisterType regType) const;
	RegisterType getLo(RegisterType regType) const;

	void setRegisterValue(RegisterType regType, uint16_t value);
	void setRegisterValue(RegisterType regType, uint8_t value);
	void setCarryFlag(bool value) { m_carryFlag = value; }
	void setZeroFlag(bool value) { m_zeroFlag = value; }
	void setHalfCarryFlag(bool value) { m_halfCarryFlag = value; }
	void setSubtractFlag(bool value) { m_subtractFlag = value; }
	void setInterruptsFlag(bool value) { m_interruptsFlag = value; }
	void setPC(uint16_t value) { m_PC = value; }
	void ForwardPC(uint16_t steps) { m_PC += steps; }

};