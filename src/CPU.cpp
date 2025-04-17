#include "CPU.h"
#include "Utils.h"
#include <iostream>
#include "InstructionSet.h"

CPU::CPU() 
{

}



CPU::CPU(std::shared_ptr<MMU> mmu) : m_mmu(mmu)
{


	//mum_instructionSet = std::make_unique<InstructionSet>(shared_from_this(), m_MMU);

}

CPU::~CPU()
{
}

void CPU::execute()
{
	while (!m_isHalted)
	{
		fetchNextInstruction();
		decodeNextInstruction();
		executeNextInstruction();
		m_clock++;
		printState();
	}
}

void CPU::fetchNextInstruction()
{
	m_PC++;
	m_currentInstruction = m_mmu->readByte(m_PC);
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
	setRegisterValue(A, (uint8_t)0xFF);
	setRegisterValue(B, (uint8_t)0xFF);
	setRegisterValue(C, (uint8_t)0xFF);
	setRegisterValue(D, (uint8_t)0xFF);
	setRegisterValue(E, (uint8_t)0xFF);
	setRegisterValue(H, (uint8_t)0xFF);
	setRegisterValue(L, (uint8_t)0xFF);
	setRegisterValue(F, (uint8_t)0xFF);
	setRegisterValue(SP, (uint16_t)0xFFFF);

	m_PC = 0x100;
	m_clock = 0;
	m_instructionSet = std::make_shared<InstructionSet>(shared_from_this(), m_mmu);

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
		case SP:
			return m_SP.value;
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

CPU::RegisterType CPU::getHi(RegisterType regType) const
{
	switch (regType)
	{
	case AF:
		return Reg::A;
	case BC:
		return Reg::B;
	case DE:
		return Reg::D;
	case HL:
		return Reg::H;

	default:
		throw std::invalid_argument("Invalid register type");
	}
}

CPU::RegisterType CPU::getLo(RegisterType regType) const
{
	switch (regType)
	{
	case AF:
		return Reg::F;
	case BC:
		return Reg::C;
	case DE:
		return Reg::D;
	case HL:
		return Reg::H;
	default:
		throw std::invalid_argument("Invalid register type");
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
	case SP:
		m_SP.value = value;
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

bool CPU::isDoubleRegister(RegisterType regType)
{
	return (regType == Reg::AF || regType == Reg::BC || regType == Reg::DE || regType == Reg::HL || regType == Reg::SP);
}


void CPU::printState() const
{
	std::cout << "-------- New Cycle ------------" << std::hex << std::endl;
	std::cout << "A				 : " << getRegisterValue<uint8_t>(A) << std::endl;
	std::cout << "AF			 : " << getRegisterValue<uint16_t>(AF) << std::endl;
	std::cout << "BC			 : " << getRegisterValue<uint16_t>(BC) << std::endl;
	std::cout << "DE			 : " << getRegisterValue<uint16_t>(DE) << std::endl;
	std::cout << "HL			 : " << getRegisterValue<uint16_t>(HL) << std::endl;
	std::cout << "SP			 : " << getRegisterValue<uint16_t>(SP) << std::endl;
	std::cout << "PC			 : " << m_PC << std::endl;
	std::cout << "Clock	  		 : " << m_clock << std::endl;
	std::cout << "Zero Flag      : " << getZeroFlag() << std::endl;
	std::cout << "Carry Flag     : " << getCarryFlag() << std::endl;
	std::cout << "Half Carry Flag: " << getHalfCarryFlag() << std::endl;
	std::cout << "Subtract Flag	 : " << getSubstractFlag() << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << "								 " << std::endl;

}


void CPU::setZeroFlag(bool value)
{
	if (value)
	{
		m_AF.setLo(m_AF.getLo() | 1 << 7);
	}
		
	else
	{
		m_AF.setLo(m_AF.getLo() & ~(1 << 7));
	}

}

void CPU::setSubtractFlag(bool value)
{
	if (value)
	{
		m_AF.setLo(m_AF.getLo() | 1 << 6);
	}

	else
	{
		m_AF.setLo(m_AF.getLo() & ~(1 << 6));
	}

}

void CPU::setHalfCarryFlag(bool value)
{
	if (value)
	{
		m_AF.setLo(m_AF.getLo() | 1 << 5);
	}

	else
	{
		m_AF.setLo(m_AF.getLo() & ~(1 << 5));
	}
}

void CPU::setCarryFlag(bool value)
{
	if (value)
	{
		m_AF.setLo(m_AF.getLo() | 1 << 4);
	}

	else
	{
		m_AF.setLo(m_AF.getLo() & ~(1 << 4));
	}

}
	
