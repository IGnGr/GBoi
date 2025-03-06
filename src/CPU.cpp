#include "CPU.h"
#include "Utils.h"
#include <iostream>
#include "InstructionSet.h"

CPU::CPU()
{
}



CPU::CPU(std::shared_ptr<GameROM> game)
{
	m_game = std::move(game);
	m_PC = 0x100;

	if (!m_MMU)
	{
		m_MMU = std::make_shared<MMU>(m_game);
	}

	//m_instructionSet = std::make_unique<InstructionSet>(shared_from_this(), m_MMU);

}

CPU::~CPU()
{
}

void CPU::execute()
{
	while (true)
	{
		fetchNextInstruction();
		decodeNextInstruction();
		executeNextInstruction();
	}
}

void CPU::fetchNextInstruction()
{
	m_PC++;
	m_currentInstruction = m_MMU->readByte(m_PC);
}


void CPU::decodeNextInstruction()
{

}

void CPU::executeNextInstruction()
{
	m_instructionSet->executeInstruction(m_currentInstruction);
}




void CPU::initialize()
{
	setRegisterValue(A, (uint8_t)0);
	setRegisterValue(B, (uint8_t)0);
	setRegisterValue(C, (uint8_t)0);
	setRegisterValue(D, (uint8_t)0);
	setRegisterValue(E, (uint8_t)0);
	setRegisterValue(H, (uint8_t)0);
	setRegisterValue(L, (uint8_t)0);
	setRegisterValue(F, (uint8_t)0);
	m_SP = 0;
	m_PC = 0;
	m_clock = 0;
	m_zeroFlag = false;
	m_carryFlag = false;
	m_halfCarryFlag = false;
	m_subtractFlag = false;

}


void CPU::getRegister(Register reg)
{
}

template <typename T>
T CPU::getRegisterValue(RegisterType regType) const
{
	if constexpr (std::is_same_v<T, uint16_t>)
	{
		switch (regType)
		{
		case AF:
			return m_AF.value;
		case BC:
			return m_BC.value;
		case DE:
			return m_DE.value;
		case HL:
			return m_HL.value;
		default:
			throw std::invalid_argument("Invalid register type");
		}
	}
	else if constexpr (std::is_same_v<T, uint8_t>)
	{
		switch (regType)
		{
		case A:
			return m_AF.getHi();
		case F:
			return m_AF.getLo();
		case B:
			return m_BC.getHi();
		case C:
			return m_BC.getLo();
		case D:
			return m_DE.getHi();
		case E:
			return m_DE.getLo();
		case H:
			return m_HL.getHi();
		case L:
			return m_HL.getLo();
		default:
			throw std::invalid_argument("Invalid register type");
		}
	}
	else
	{
		throw std::invalid_argument("Invalid return type");
	}
}

void CPU::setRegisterValue(RegisterType regType, uint16_t value)
{
	switch (regType)
	{
	case AF:
		m_AF.value = value;
		break;
	case BC:
		m_BC.value = value;
		break;
	case DE:
		m_DE.value = value;
		break;
	case HL:
		m_HL.value = value;
		break;
	default:
		throw std::invalid_argument("Invalid register type");
	}
}

void CPU::setRegisterValue(RegisterType regType, uint8_t value)
{
	switch (regType)
	{
	case A:
		m_AF.setHi(value);
		break;
	case F:
		m_AF.setLo(value);
		break;
	case B:
		m_BC.setHi(value);
		break;
	case C:
		m_BC.setLo(value);
		break;
	case D:
		m_DE.setHi(value);
		break;
	case E:
		m_DE.setLo(value);
		break;
	case H:
		m_HL.setHi(value);
		break;
	case L:
		m_HL.setLo(value);
		break;
	default:
		throw std::invalid_argument("Invalid register type");
	}
}


void CPU::printState() const
{
	std::cout << "A				 : " << getRegisterValue<uint8_t>(A) << std::endl;
	std::cout << "B				 : " << getRegisterValue<uint8_t>(B) << std::endl;
	std::cout << "C				 : " << getRegisterValue<uint8_t>(C) << std::endl;
	std::cout << "D				 : " << getRegisterValue<uint8_t>(D) << std::endl;
	std::cout << "E				 : " << getRegisterValue<uint8_t>(E) << std::endl;
	std::cout << "H				 : " << getRegisterValue<uint8_t>(H) << std::endl;
	std::cout << "L				 : " << getRegisterValue<uint8_t>(L) << std::endl;
	std::cout << "AF			 : " << getRegisterValue<uint16_t>(AF) << std::endl;
	std::cout << "BC			 : " << getRegisterValue<uint16_t>(BC) << std::endl;
	std::cout << "DE			 : " << getRegisterValue<uint16_t>(DE) << std::endl;
	std::cout << "HL			 : " << getRegisterValue<uint16_t>(HL) << std::endl;
	std::cout << "SP			 : " << m_SP << std::endl;
	std::cout << "PC			 : " << m_PC << std::endl;
	std::cout << "Clock	  		 : " << m_clock << std::endl;
	std::cout << "Zero Flag      : " << m_zeroFlag << std::endl;
	std::cout << "Carry Flag     : " << m_carryFlag << std::endl;
	std::cout << "Half Carry Flag: " << m_halfCarryFlag << std::endl;
	std::cout << "Subtract Flag	 : " << m_subtractFlag << std::endl;

}
	
