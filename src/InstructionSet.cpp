#include "InstructionSet.h"
#include <stdexcept>
#include <cassert>


InstructionSet::InstructionSet(std::shared_ptr<CPU> cpu, std::shared_ptr<MMU> mmu) : m_cpu(cpu), m_mmu(mmu)
{
	
}

InstructionSet::~InstructionSet()
{
}

void InstructionSet::executeInstruction(uint8_t opCode)
{
	uint16_t data = m_mmu->readWord(m_cpu->getPC());

    switch (opCode)
    {
    case 0x00:
        nop();
        break;
    case 0x01:
        ld(Reg::BC, data);
        break;
    case 0x02:
		ldAddress(Reg::BC, Reg::A);
        break;
    case 0x03:
        inc(Reg::BC);
        break;
    case 0x04:
		inc(Reg::B);
        break;
    case 0x05:
        dec(Reg::B);
        break;
    case 0x06:
        ld(Reg::B, (uint8_t) data);
        break;
    case 0x07:
        rotateLeft(Reg::A, true);
        break;
    case 0x08:
        ldAddress((uint16_t) data, Reg::SP);
        break;
    case 0x09:
        add(Reg::HL, Reg::BC, false);
        break;
    case 0x0A:
        ldAddress(Reg::A, Reg::BC);
        break;
    case 0x0B:
        dec(Reg::BC);
        break;
    case 0x0C:
        inc(Reg::C);
        break;
    case 0x0D:
        dec(Reg::C);
        break;
    case 0x0E:
        ld(Reg::C, (uint8_t) data);
        break;
    case 0x0F:
        rotateRight(Reg::A, false);
        break;
    case 0x10:
        stop();
        break;
    case 0x11:
        ld(Reg::DE, (uint16_t) data);        
        break;
    case 0x12:
        ldAddress(Reg::DE, Reg::A);
        break;
    case 0x13:
        inc(Reg::DE);
        break;
    case 0x14:
        inc(Reg::D);
        break;
    case 0x15:
        dec(Reg::D);
        break;
    case 0x16:
        ld(Reg::D, (uint8_t)data);
        break;
    case 0x17:
        rotateLeft(Reg::A, false);
        break;
    case 0x18:
        jr((int8_t) data);
        break;
    case 0x19:
        add(Reg::HL, Reg::DE, false);
        break;
    case 0x1A:
        ldAddress(Reg::A, Reg::DE);
        break;
    case 0x1B:
        dec(Reg::DE);
        break;
    case 0x1C:
        inc(Reg::E);
        break;
    case 0x1D:
        dec(Reg::E);
        break;
    case 0x1E:
        ld(Reg::E, (uint8_t)data);
        break;
    case 0x1F:
        rotateRight(Reg::A, false);
        break;
    case 0x20:
        jr(!m_cpu->getZeroFlag(),(uint8_t) data);
        break;
    case 0x21:
        ldAddress(Reg::DE, Reg::A);
        break; 
    case 0x22:
        ldAddress(Reg::HL,Reg::A);
        inc(Reg::HL);
        break;
    case 0x23:
        inc(Reg::HL);
        break;
    case 0x24:
        inc(Reg::H);
        break;
    case 0x25:
        dec(Reg::H);
        break;
    case 0x26:
        ld(Reg::H, (uint8_t) data);
        break;
    case 0x27:
        daa();
        break;
    case 0x28:
        jr(m_cpu->getZeroFlag(),(int8_t) data);
        break;
    case 0x29:
        add(Reg::HL, Reg::HL, false);
        break;
    case 0x2A:
        ldAddress(Reg::A, Reg::HL);
        break;
    case 0x2B:
        dec(Reg::HL);
        break;
    case 0x2C:
        inc(Reg::L);
        break;
    case 0x2D:
        dec(Reg::L);
        break;
    case 0x2E:
        ld(Reg::L, (uint8_t) data);
        break;
    case 0x2F:
        cpl();
        break;
    case 0x30:
        jr(!m_cpu->getCarryFlag(), (int8_t) data);
        break;
    case 0x31:
        ld(Reg::SP, (uint16_t) data);
        break;
    case 0x32:
        ldAddress(Reg::HL, Reg::A);
        dec(Reg::HL);
        break;
    case 0x33:
        inc(Reg::SP);
        break;
    case 0x34:
        incAddress(Reg::HL);
        break;
    case 0x35:
        dec(Reg::HL);
        break;
    case 0x36:
        ldAddress(Reg::HL, (uint8_t)data);
        break;
    case 0x37:
        scf();
        break;
    case 0x38:
        jr(m_cpu->getCarryFlag(), (int8_t)data);
        break;
    case 0x39:
        add(Reg::HL, Reg::SP, false);
        break;
    case 0x3A:
        ldAddress(Reg::A, Reg::HL);
        dec(Reg::HL);
        break;
    case 0x3B:
        dec(Reg::SP);
        break;
    case 0x3C:
        inc(Reg::A);
        break;
    case 0x3D:
        dec(Reg::A);
        break;
    case 0x3E:
        ld(Reg::A, (uint8_t) data);
        break;
    case 0x3F:
        ccf();
        break;
    case 0x40:
        ld(Reg::B, Reg::B);
        break;
    case 0x41:
        ld(Reg::C, Reg::B);
        break;
    case 0x42:
        ld(Reg::D, Reg::B);
        break;
    case 0x43:
        ld(Reg::E, Reg::B);
        break;
    case 0x44:
        ld(Reg::H, Reg::B);
        break;
    case 0x45:
        ld(Reg::H, Reg::B);        
        break;
    case 0x46:
        ldAddress(Reg::B, Reg::HL);
        break;
    case 0x47:
        ld(Reg::B, Reg::A);
        break;
    case 0x48:
        ld(Reg::C, Reg::B);
        break;
    case 0x49:
        ld(Reg::C, Reg::C);
        break;
    case 0x4A:
        ld(Reg::C, Reg::D);
        break;
    case 0x4B:
        ld(Reg::C, Reg::E);
        break;
    case 0x4C:
        ld(Reg::C, Reg::H);
        break;
    case 0x4D:
        ld(Reg::C, Reg::L);
        break;
    case 0x4E:
        ldAddress(Reg::C, Reg::HL);
        break;
    case 0x4F:
        ld(Reg::C, Reg::A);
        break;
    case 0x50:
        ld(Reg::D, Reg::B);
        break;
    case 0x51:
        ld(Reg::D, Reg::C);
        break;
    case 0x52:
        ld(Reg::D, Reg::D);
        break;
    case 0x53:
        ld(Reg::D, Reg::E);
        break;
    case 0x54:
        ld(Reg::D, Reg::H);
        break;
    case 0x55:
        ld(Reg::D, Reg::L);
        break;
    case 0x56:
        ldAddress(Reg::D, Reg::HL);
        break;
    case 0x57:
        ld(Reg::D, Reg::A);
        break;
    case 0x58:
        ld(Reg::E, Reg::B);
        break;
    case 0x59:
        ld(Reg::E, Reg::C);
        break;
    case 0x5A:
        ld(Reg::E, Reg::D);
        break;
    case 0x5B:
        ld(Reg::E, Reg::E);
        break;
    case 0x5C:
        ld(Reg::E, Reg::H);
        break;
    case 0x5D:
        ld(Reg::E, Reg::L);
        break;
    case 0x5E:
        ldAddress(Reg::E, Reg::HL);
        break;
    case 0x5F:
        ld(Reg::E, Reg::A);
        break;
    case 0x60:
        ld(Reg::H, Reg::B);
        break;
    case 0x61:
        ld(Reg::H, Reg::C);
        break;
    case 0x62:
        ld(Reg::H, Reg::D);
        break;
    case 0x63:
        ld(Reg::H, Reg::E);
        break;
    case 0x64:
        ld(Reg::H, Reg::H);
        break;
    case 0x65:
        ld(Reg::H, Reg::L);
        break;
    case 0x66:
        ldAddress(Reg::H, Reg::HL);
        break;
    case 0x67:
        ld(Reg::H, Reg::A);
        break;
    case 0x68:
        ld(Reg::L, Reg::B);
        break;
    case 0x69:
        ld(Reg::L, Reg::C);
        break;
    case 0x6A:
        ld(Reg::L, Reg::D);
        break;
    case 0x6B:
        ld(Reg::L, Reg::E);
        break;
    case 0x6C:
        ld(Reg::L, Reg::H);
        break;
    case 0x6D:
        ld(Reg::L, Reg::L);
        break;
    case 0x6E:
        ldAddress(Reg::L, Reg::HL);
        break;
    case 0x6F:
        ld(Reg::L, Reg::A);
        break;
    case 0x70:
        ldAddress(Reg::HL, Reg::B);
        break;
    case 0x71:
        ldAddress(Reg::HL, Reg::C);
        break;
    case 0x72:
        ldAddress(Reg::HL, Reg::D);
        break;
    case 0x73:
        ldAddress(Reg::HL, Reg::E);
        break;
    case 0x74:
        ldAddress(Reg::HL, Reg::H);
        break;
    case 0x75:
        ldAddress(Reg::HL, Reg::L);
        break;
    case 0x76:
        halt();
        break;
    case 0x77:
        ldAddress(Reg::HL, Reg::A);
        break;
    case 0x78:
        ld(Reg::A, Reg::B);
        break;
    case 0x79:
        ld(Reg::A, Reg::C);
        break;
    case 0x7A:
        ld(Reg::A, Reg::D);
        break;
    case 0x7B:
        ld(Reg::A, Reg::E);
        break;
    case 0x7C:
        ld(Reg::A, Reg::H);
        break;
    case 0x7D:
        ld(Reg::A, Reg::L);
        break;
    case 0x7E:
        ldAddress(Reg::A, Reg::HL);
        break;
    case 0x7F:
        ld(Reg::A, Reg::A);
        break;
    case 0x80:
        add(Reg::A, Reg::B, false);
        break;
    case 0x81:
        add(Reg::A, Reg::C, false);
        break;
    case 0x82:
        add(Reg::A, Reg::D, false);
        break;
    case 0x83:
        add(Reg::A, Reg::E, false);
        break;
    case 0x84:
        add(Reg::A, Reg::H, false);
        break;
    case 0x85:
        add(Reg::A, Reg::L, false);
        break;
    case 0x86:
        add(Reg::A, m_mmu->readByte(m_cpu->getRegisterValue<uint16_t>(Reg::HL)), false);
        break;
    case 0x87:
        add(Reg::A, Reg::A, false);
        break;
    case 0x88:
        add(Reg::A, Reg::B, true);
        break;
    case 0x89:
        add(Reg::A, Reg::C, true);
        break;
    case 0x8A:
        add(Reg::A, Reg::D, true);
        break;
    case 0x8B:
        add(Reg::A, Reg::E, true);
        break;
    case 0x8C:
        add(Reg::A, Reg::H, true);
        break;
    case 0x8D:
        add(Reg::A, Reg::L, true);
        break;
    case 0x8E:
        add(Reg::A, m_mmu->readByte(m_cpu->getRegisterValue<uint16_t>(Reg::HL)), true);
        break;
    case 0x8F:
        add(Reg::A, Reg::A, true);
        break;
    case 0x90:
        sub(Reg::A, false);
        break;
    case 0x91:
        sub(Reg::C, false);
        break;
    case 0x92:
        sub(Reg::D, false);
        break;
    case 0x93:
        sub(Reg::E, false);
        break;
    case 0x94:
        sub(Reg::H, false);
        break;
    case 0x95:
        sub(Reg::L, false);
        break;
    case 0x96:
        sub(m_mmu->readByte(m_cpu->getRegisterValue<uint16_t>(Reg::HL)), false);
        break;
    case 0x97:
        sub(Reg::A, false);
        break;
    case 0x98:
        sub(Reg::B, true);
        break;
    case 0x99:
        sub(Reg::C, true);
        break;
    case 0x9A:
        sub(Reg::D, true);
        break;
    case 0x9B:
        sub(Reg::E, true);
        break;
    case 0x9C:
        sub(Reg::H, true);
        break;
    case 0x9D:
        sub(Reg::L, true);
        break;
    case 0x9E:
        sub(m_mmu->readByte(m_cpu->getRegisterValue<uint16_t>(Reg::HL)), true);
        break;
    case 0x9F:
        sub(Reg::A, true);
        break;
    case 0xA0:
        andOp(Reg::B);
        break;
    case 0xA1:
        andOp(Reg::C);
        break;
    case 0xA2:
        andOp(Reg::D);
        break;
    case 0xA3:
        andOp(Reg::E);
        break;
    case 0xA4:
        andOp(Reg::H);
        break;
    case 0xA5:
        andOp(Reg::L);
        break;
    case 0xA6:
        andOp(Reg::B);
        break;
    case 0xA7:
        andOp(m_mmu->readByte(m_cpu->getRegisterValue<uint16_t>(Reg::HL)));
        break;
    case 0xA8:
        xorOp(Reg::B);
        break;
    case 0xA9:
        xorOp(Reg::C);
        break;
    case 0xAA:
        xorOp(Reg::D);
        break;
    case 0xAB:
        xorOp(Reg::E);
        break;
    case 0xAC:
        xorOp(Reg::H);
        break;
    case 0xAD:
        xorOp(Reg::L);
        break;
    case 0xAE:
        xorOp(m_mmu->readByte(m_cpu->getRegisterValue<uint16_t>(Reg::HL)));
        break;
    case 0xAF:
        xorOp(Reg::A);
        break;
    case 0xB0:
        orOp(Reg::B);
        break;
    case 0xB1:
        orOp(Reg::C);
        break;
    case 0xB2:
        orOp(Reg::D);
        break;
    case 0xB3:
        orOp(Reg::E);
        break;
    case 0xB4:
        orOp(Reg::H);
        break;
    case 0xB5:
        orOp(Reg::L);
        break;
    case 0xB6:
        orOp(m_mmu->readByte(m_cpu->getRegisterValue<uint16_t>(Reg::HL)));
        break;
    case 0xB7:
        orOp(Reg::A);
        break;
    case 0xB8:
        cp(Reg::B);
        break;
    case 0xB9:
        cp(Reg::C);
        break;
    case 0xBA:
        cp(Reg::D);
        break;
    case 0xBB:
        cp(Reg::E);
        break;
    case 0xBC:
        cp(Reg::H);
        break;
    case 0xBD:
        cp(Reg::L);
        break;
    case 0xBE:
        cp(m_mmu->readByte(m_cpu->getRegisterValue<uint16_t>(Reg::HL)));
        break;
    case 0xBF:
        cp(Reg::A);
        break;
    case 0xC0:
        ret(!m_cpu->getZeroFlag());
        break;
    case 0xC1:
        pop(Reg::BC);
        break;
    case 0xC2:
        jp(!m_cpu->getZeroFlag(), m_mmu->readWord((uint16_t) data));
        break;
    case 0xC3:
        jp(true, m_mmu->readWord((uint16_t)data));
        break;
    case 0xC4:
        call(!m_cpu->getZeroFlag(), m_mmu->readWord((uint16_t)data));
        break;
    case 0xC5:
        push(Reg::BC);
        break;
    case 0xC6:
        add(Reg::A, (uint8_t) data, false);
        break;
    case 0xC7:
        //rst $00
        call(true, m_mmu->readWord(0x00));
        break;
    case 0xC8:
        ret(m_cpu->getZeroFlag());
        break;
    case 0xC9:
        ret(true);
        break;
    case 0xCA:
        jp(m_cpu->getZeroFlag(), (uint16_t)data);
        break;
    case 0xCB:
        cb((uint16_t) data) ;
        break;
    case 0xCC:
        call(m_cpu->getZeroFlag(), (uint16_t)data);
        break;
    case 0xCD:
        call(true, (uint16_t) data);
        break;
    case 0xCE:
        add(Reg::A, (uint8_t) data, true);
        break;
    case 0xCF:
        //rst $08
        call(true, m_mmu->readWord(0x08));
        break;
    case 0xD0:
        ret(!m_cpu->getCarryFlag());
        break;
    case 0xD1:
        pop(Reg::DE);
        break;
    case 0xD2:
        jp(!m_cpu->getCarryFlag(), (uint16_t) data);
        break;
    case 0xD4:
        call(!m_cpu->getCarryFlag(), (uint16_t)data);
        break;
    case 0xD5:
        push(Reg::DE);
        break;
    case 0xD6:
        sub((uint8_t) data, false);
        break;
    case 0xD7:
        //rst $10
        call(true, m_mmu->readWord(0x10));
        break;
    case 0xD8:
        ret(m_cpu->getCarryFlag());
        break;
    case 0xD9:
        ei();
        ret(true);
        break;
    case 0xDA:
        jp(Reg::C, (uint16_t) data);
        break;
    case 0xDC:
        call(m_cpu->getCarryFlag(), (uint16_t) data);
        break;
    case 0xDE:
        //sbc A, n8
        sub((uint8_t)data, true);
        break;
    case 0xDF:
        //rst $18
        call(true, m_mmu->readWord(0x18));
        break;
    case 0xE0:
        ldh((uint16_t) data, Reg::A);
        break;
    case 0xE1:
        pop(Reg::HL);
        break;
    case 0xE2:
        ldh((uint8_t)data, Reg::A);
        break;
    case 0xE5:
        push(Reg::HL);
        break;
    case 0xE6:
        andOp((uint8_t) data);
        break;
    case 0xE7:
        //rst $20
        call(true, m_mmu->readWord(0x20));
        break;
    case 0xE8:
        add(Reg::SP, (uint8_t) data, false);
        break;
    case 0xE9:
        jp(m_cpu->getCarryFlag(), (uint16_t) data);
        break;
    case 0xEA:
        ldAddress((uint16_t) data, Reg::A);
        break;
    case 0xEE:
        xorOp((uint8_t) data);
        break;
    case 0xEF:
        //rst $28
        call(true, m_mmu->readWord(0x28));
        break;
    case 0xF0:
        ldh(Reg::A, (uint8_t) data);
        break;
    case 0xF1:
        pop(Reg::AF);
        break;
    case 0xF2:
        ldh(Reg::A, (uint8_t) data);
        break;
    case 0xF3:
        di();
        break;
    case 0xF5:
        push(Reg::AF);
        break;
    case 0xF6:
        orOp((uint8_t) data);
        break;
    case 0xF7: 
        //rst $30
        call(true, m_mmu->readWord(0x30));        
        break;
    case 0xF8:
        ld(Reg::HL, Reg::SP,(int8_t) data);
        break;
    case 0xF9:
        ld(Reg::SP, Reg::HL);
        break;
    case 0xFA:
        ld(Reg::A, (uint16_t) data);
        break;
    case 0xFB:
        ei();
        break;
    case 0xFE:
        cp((uint8_t) data);
        break;
    case 0xFF:
        //rst $38
        call(true, m_mmu->readWord(0x38));         
        break;
    default:
        throw std::invalid_argument("Invalid Operation code");
        break;

    }
}

void InstructionSet::nop()
{
}

void InstructionSet::stop()
{
    throw std::invalid_argument("Operation not implemented");
}

void InstructionSet::halt()
{
    throw std::invalid_argument("Operation not implemented");
}

void InstructionSet::ld(Reg reg, uint16_t value)
{
	m_cpu->setRegisterValue(reg, value);
}

void InstructionSet::ld(Reg reg, uint8_t value)
{
    m_cpu->setRegisterValue(reg, value);
}

void InstructionSet::ld(Reg regTo, Reg regFrom)
{
    if(regFrom == Reg::AF || regFrom == Reg::BC || regFrom == Reg::DE || regFrom == Reg::HL || regFrom == Reg::SP)
	    m_cpu->setRegisterValue(regTo, m_cpu->getRegisterValue<uint16_t>(regFrom));
    else 
        m_cpu->setRegisterValue(regTo, m_cpu->getRegisterValue<uint8_t>(regFrom));
}

void InstructionSet::ld(Reg regTo, Reg regFrom, int8_t offset)
{
    uint8_t newVal = m_cpu->getRegisterValue<uint8_t>(regFrom) + offset;
    m_cpu->setRegisterValue(regTo,newVal);

    m_cpu->setZeroFlag(false);
    m_cpu->setSubtractFlag(false);
    //bit 3 
    m_cpu->setCarryFlag(newVal & 0x80);
    //bit 7
    m_cpu->setHalfCarryFlag(newVal & 0x08);
}


void InstructionSet::ldAddress(Reg regAddress, Reg regValue)
{
    if (regValue == Reg::AF || regValue == Reg::BC || regValue == Reg::DE || regValue == Reg::HL || regValue == Reg::SP)
        m_mmu->setWord(m_cpu->getRegisterValue<uint16_t>(regAddress), m_cpu->getRegisterValue<uint16_t>(regValue));
    else
        m_mmu->setWord(m_cpu->getRegisterValue<uint16_t>(regAddress), m_cpu->getRegisterValue<uint8_t>(regValue));
}


void InstructionSet::ldAddress(Reg regAddress, uint8_t value)
{
    m_mmu->setByte(m_cpu->getRegisterValue<uint16_t>(regAddress), value);
}


void InstructionSet::ldAddress(uint8_t address, Reg regValue)
{
    m_mmu->setWord(address, m_cpu->getRegisterValue<uint16_t>(regValue));
}

void InstructionSet::ldAddress(uint16_t address, Reg regValue)
{
    m_mmu->setWord(address, m_cpu->getRegisterValue<uint16_t>(regValue));
}

//Copy the value in register A into the byte at address n16, provided the address is between $FF00 and $FFFF.
void InstructionSet::ldh(uint16_t address, Reg A)
{
    assert(address > 0xFF00 && address < 0xFFFF);
	ldAddress(address, A);
}

//Copy the value in register A into the byte at address $FF00+C.
void InstructionSet::ldh(uint8_t c , Reg A)
{
    uint16_t address = 0xFF00 + c;
    assert(address > 0xFF00 && address < 0xFFFF);
    m_mmu->setWord(address, m_cpu->getRegisterValue<uint8_t>(A));
}

void InstructionSet::ldh(Reg reg, uint16_t value)
{
    assert(value > 0xFF00 && value < 0xFFFF);
    ldAddress(reg, value);
}

void InstructionSet::ldh(Reg reg, uint8_t value)
{
    assert((0xFF00 + value) > 0xFF00 && (0xFF00 + value) < 0xFFFF);
    ldAddress(reg, 0xFF00 + value);
}


void InstructionSet::inc(Reg reg)
{
	if (reg == Reg::AF || reg == Reg::BC || reg == Reg::DE || reg == Reg::HL|| reg == Reg::SP)
		m_cpu->setRegisterValue(reg, static_cast<uint16_t>(m_cpu->getRegisterValue<uint16_t>(reg) + 1));
	else
        m_cpu->setRegisterValue(reg, static_cast<uint8_t> (m_cpu->getRegisterValue<uint8_t>(reg) + 1));
}

void InstructionSet::incAddress(Reg reg)
{
    uint8_t value = m_mmu->readByte(m_cpu->getRegisterValue<uint16_t>(reg));
    m_mmu->setByte(m_cpu->getRegisterValue<uint16_t>(reg), value + 1);
}

void InstructionSet::rotateLeft(Reg reg, bool setCarryFlag)
{
    if (reg == Reg::AF || reg == Reg::BC || reg == Reg::DE || reg == Reg::HL || reg == Reg::SP)
    {
        uint16_t regValue = m_cpu->getRegisterValue<uint16_t>(reg);
        if(setCarryFlag) m_cpu->setCarryFlag(regValue & 0x8000);
        //Shift A left by 1 bit and set the least significant bit to the value of the carry flag.
        regValue = (regValue << 1) | (regValue >> 15);
        m_cpu->setRegisterValue(reg, regValue);
    }
    else
    {
        uint8_t regValue = m_cpu->getRegisterValue<uint8_t>(reg);
        if(setCarryFlag) m_cpu->setCarryFlag(regValue & 0x08);
        //Shift A left by 1 bit and set the least significant bit to the value of the carry flag.
        regValue = (regValue << 1) | (regValue >> 7);
        m_cpu->setRegisterValue(reg, regValue);
    }
}

void InstructionSet::rotateRight(Reg reg, bool setCarryFlag)
{
    if (reg == Reg::AF || reg == Reg::BC || reg == Reg::DE || reg == Reg::HL || reg == Reg::SP)
    {
        uint16_t regValue = m_cpu->getRegisterValue<uint16_t>(reg);
        if(setCarryFlag) m_cpu->setCarryFlag(regValue & 0x01);
        //Shift A right by 1 bit and set the most significant bit to the value of the carry flag.
        regValue = (regValue >> 1) | (regValue << 15);
        m_cpu->setRegisterValue(reg, regValue);
    }
    else
    {
        uint8_t regValue = m_cpu->getRegisterValue<uint8_t>(reg);
        if(setCarryFlag) m_cpu->setCarryFlag(regValue & 0x01);
        //Shift A right by 1 bit and set the most significant bit to the value of the carry flag.
        regValue = (regValue >> 1) | (regValue << 7);
        m_cpu->setRegisterValue(reg, regValue);
    }
}


void InstructionSet::dec(Reg reg)
{
    if (reg == Reg::AF || reg == Reg::BC || reg == Reg::DE || reg == Reg::HL || reg == Reg::SP)
        m_cpu->setRegisterValue(reg, static_cast<uint16_t>(m_cpu->getRegisterValue<uint16_t>(reg) - 1));
    else
        m_cpu->setRegisterValue(reg, static_cast<uint8_t> (m_cpu->getRegisterValue<uint8_t>(reg) - 1));
}

void InstructionSet::andOp(Reg reg)
{
    uint8_t A = m_cpu->getRegisterValue<uint8_t>(Reg::A);
    andOp(m_cpu->getRegisterValue<uint8_t>(reg));
}

void InstructionSet::andOp(uint8_t value)
{
    uint8_t A = m_cpu->getRegisterValue<uint8_t>(Reg::A);
    uint8_t newA = A & value;
    m_cpu->setRegisterValue(Reg::A, newA);

    m_cpu->setZeroFlag(newA == 0x0);
    m_cpu->setSubtractFlag(false);
    m_cpu->setHalfCarryFlag(true);
    m_cpu->setCarryFlag(false);
}


void InstructionSet::orOp(Reg reg)
{
    uint8_t A = m_cpu->getRegisterValue<uint8_t>(Reg::A);
    orOp(m_cpu->getRegisterValue<uint8_t>(reg));
}

void InstructionSet::orOp(uint8_t value)
{
    uint8_t A = m_cpu->getRegisterValue<uint8_t>(Reg::A);
    uint8_t newA = A | value;
    m_cpu->setRegisterValue(Reg::A, newA);

    m_cpu->setZeroFlag(newA == 0x0);
    m_cpu->setSubtractFlag(false);
    m_cpu->setHalfCarryFlag(false);
    m_cpu->setCarryFlag(false);
}

void InstructionSet::xorOp(Reg reg)
{
    uint8_t A = m_cpu->getRegisterValue<uint8_t>(Reg::A);
    xorOp(m_cpu->getRegisterValue<uint8_t>(reg));
}

void InstructionSet::xorOp(uint8_t value)
{
    uint8_t A = m_cpu->getRegisterValue<uint8_t>(Reg::A);
    uint8_t newA = A ^ value;
    m_cpu->setRegisterValue(Reg::A, newA);

    m_cpu->setZeroFlag(newA == 0x0);
    m_cpu->setSubtractFlag(false);
    m_cpu->setHalfCarryFlag(false);
    m_cpu->setCarryFlag(false);
}


void InstructionSet::add(Reg reg, uint8_t value, bool carryFlag)
{

    m_cpu->setRegisterValue(reg, (uint8_t) (m_cpu->getRegisterValue<uint8_t>(reg) + value + carryFlag));

    uint8_t reg1Value = m_cpu->getRegisterValue<uint8_t>(reg);

    //Bit 7 overflow
    m_cpu->setCarryFlag(0x80 && reg1Value && value);
    //Bit 3 overflow
    m_cpu->setHalfCarryFlag(0x08 && reg1Value && value);
}

void InstructionSet::add(Reg reg, uint16_t value, bool carryFlag)
{

    m_cpu->setRegisterValue(reg, (uint16_t)(m_cpu->getRegisterValue<uint16_t>(reg) + value + carryFlag));

    uint16_t reg1Value = m_cpu->getRegisterValue<uint16_t>(reg);

    //Bit 15 overflow
    m_cpu->setCarryFlag(0x8000 && reg1Value && value);
    //Bit 11 overflow
    m_cpu->setHalfCarryFlag(0x0800 && reg1Value && value);
}

void InstructionSet::add(Reg reg1, Reg reg2, bool carryFlag)
{
    if (reg1 == Reg::AF || reg1 == Reg::BC || reg1 == Reg::DE || reg1 == Reg::HL || reg1 == Reg::SP)
    {
        uint16_t regValue = m_cpu->getRegisterValue<uint16_t>(reg2) + carryFlag;
        add(reg1, regValue, false);
    }
        
    else
    {
        uint8_t regValue = m_cpu->getRegisterValue<uint8_t>(reg2) + carryFlag;
        add(reg1, regValue, false);
    }
}



void InstructionSet::sub(Reg reg, bool carryFlag)
{
    if (reg == Reg::AF || reg == Reg::BC || reg == Reg::DE || reg == Reg::HL || reg == Reg::SP)
        throw std::invalid_argument("16 bit register substraction not allowed");


    sub(m_cpu->getRegisterValue<uint8_t>(reg),carryFlag);

}
void InstructionSet::sub(uint8_t value, bool carryFlag)
{
    
    uint8_t A = m_cpu->getRegisterValue<uint8_t>(Reg::A);

    A -= (value + carryFlag);


    m_cpu->setSubtractFlag(true);
    m_cpu->setZeroFlag(A == 0x0);
    m_cpu->setHalfCarryFlag(((value & 0x0F)+ carryFlag) > (A & 0x0F));
    m_cpu->setCarryFlag((value + carryFlag) > A);



    m_cpu->setRegisterValue(Reg::A, (uint8_t) A);


}


void InstructionSet::cb(uint16_t operation)
{
    switch (operation)
    {
        // Rotate and Shift Instructions
        case 0x00: rl(Reg::B, true); break;
        case 0x01: rl(Reg::C, true); break;
        case 0x02: rl(Reg::D, true); break;
        case 0x03: rl(Reg::E, true); break;
        case 0x04: rl(Reg::H, true); break;
        case 0x05: rl(Reg::L, true); break;
        case 0x06: rlAddress(Reg::HL, true); break;
        case 0x07: rl(Reg::A, true); break;

        case 0x08: rl(Reg::B, true); break;
        case 0x09: rl(Reg::C, true); break;
        case 0x0A: rl(Reg::D, true); break;
        case 0x0B: rl(Reg::E, true); break;
        case 0x0C: rl(Reg::H, true); break;
        case 0x0D: rl(Reg::L, true); break;
        case 0x0E: rlAddress(Reg::HL, true); break;
        case 0x0F: rl(Reg::A, true); break;

        case 0x10: rr(Reg::B, true); break;
        case 0x11: rr(Reg::C, true); break;
        case 0x12: rr(Reg::D, true); break;
        case 0x13: rr(Reg::E, true); break;
        case 0x14: rr(Reg::H, true); break;
        case 0x15: rr(Reg::L, true); break;
        case 0x16: rrAddress(Reg::HL, true); break;
        case 0x17: rr(Reg::A, true); break;

        case 0x18: rr(Reg::B, true); break;
        case 0x19: rr(Reg::C, true); break;
        case 0x1A: rr(Reg::D, true); break;
        case 0x1B: rr(Reg::E, true); break;
        case 0x1C: rr(Reg::H, true); break;
        case 0x1D: rr(Reg::L, true); break;
        case 0x1E: rrAddress(Reg::HL, true); break;
        case 0x1F: rr(Reg::A, true); break;

        case 0x20: sla(Reg::B); break;
        case 0x21: sla(Reg::C); break;
        case 0x22: sla(Reg::D); break;
        case 0x23: sla(Reg::E); break;
        case 0x24: sla(Reg::H); break;
        case 0x25: sla(Reg::L); break;
        case 0x26: slaAddress(Reg::HL); break;
        case 0x27: sla(Reg::A); break;

        case 0x28: sra(Reg::B); break;
        case 0x29: sra(Reg::C); break;
        case 0x2A: sra(Reg::D); break;
        case 0x2B: sra(Reg::E); break;
        case 0x2C: sra(Reg::H); break;
        case 0x2D: sra(Reg::L); break;
        case 0x2E: sraAddress(Reg::HL); break;
        case 0x2F: sra(Reg::A); break;

        case 0x30: swap(Reg::B); break;
        case 0x31: swap(Reg::C); break;
        case 0x32: swap(Reg::D); break;
        case 0x33: swap(Reg::E); break;
        case 0x34: swap(Reg::H); break;
        case 0x35: swap(Reg::L); break;
        case 0x36: swapAddress(Reg::HL); break;
        case 0x37: swap(Reg::A); break;

        case 0x38: srl(Reg::B); break;
        case 0x39: srl(Reg::C); break;
        case 0x3A: srl(Reg::D); break;
        case 0x3B: srl(Reg::E); break;
        case 0x3C: srl(Reg::H); break;
        case 0x3D: srl(Reg::L); break;
        case 0x3E: srlAddress(Reg::HL); break;
        case 0x3F: srl(Reg::A); break;

            // BIT Instructions
        case 0x40: bit(0, Reg::B); break;
        case 0x41: bit(0, Reg::C); break;
        case 0x42: bit(0, Reg::D); break;
        case 0x43: bit(0, Reg::E); break;
        case 0x44: bit(0, Reg::H); break;
        case 0x45: bit(0, Reg::L); break;
        case 0x46: bitAddress(0, Reg::HL); break;
        case 0x47: bit(0, Reg::A); break;

        case 0x48: bit(1, Reg::B); break;
        case 0x49: bit(1, Reg::C); break;
        case 0x4A: bit(1, Reg::D); break;
        case 0x4B: bit(1, Reg::E); break;
        case 0x4C: bit(1, Reg::H); break;
        case 0x4D: bit(1, Reg::L); break;
        case 0x4E: bitAddress(1, Reg::HL); break;
        case 0x4F: bit(1, Reg::A); break;

        case 0x50: bit(2, Reg::B); break;
        case 0x51: bit(2, Reg::C); break;
        case 0x52: bit(2, Reg::D); break;
        case 0x53: bit(2, Reg::E); break;
        case 0x54: bit(2, Reg::H); break;
        case 0x55: bit(2, Reg::L); break;
        case 0x56: bitAddress(2, Reg::HL); break;
        case 0x57: bit(2, Reg::A); break;

        case 0x58: bit(3, Reg::B); break;
        case 0x59: bit(3, Reg::C); break;
        case 0x5A: bit(3, Reg::D); break;
        case 0x5B: bit(3, Reg::E); break;
        case 0x5C: bit(3, Reg::H); break;
        case 0x5D: bit(3, Reg::L); break;
        case 0x5E: bitAddress(3, Reg::HL); break;
        case 0x5F: bit(3, Reg::A); break;

        case 0x60: bit(4, Reg::B); break;
        case 0x61: bit(4, Reg::C); break;
        case 0x62: bit(4, Reg::D); break;
        case 0x63: bit(4, Reg::E); break;
        case 0x64: bit(4, Reg::H); break;
        case 0x65: bit(4, Reg::L); break;
        case 0x66: bitAddress(4, Reg::HL); break;
        case 0x67: bit(4, Reg::A); break;

        case 0x68: bit(5, Reg::B); break;
        case 0x69: bit(5, Reg::C); break;
        case 0x6A: bit(5, Reg::D); break;
        case 0x6B: bit(5, Reg::E); break;
        case 0x6C: bit(5, Reg::H); break;
        case 0x6D: bit(5, Reg::L); break;
        case 0x6E: bitAddress(5, Reg::HL); break;
        case 0x6F: bit(5, Reg::A); break;

        case 0x70: bit(6, Reg::B); break;
        case 0x71: bit(6, Reg::C); break;
        case 0x72: bit(6, Reg::D); break;
        case 0x73: bit(6, Reg::E); break;
        case 0x74: bit(6, Reg::H); break;
        case 0x75: bit(6, Reg::L); break;
        case 0x76: bitAddress(6, Reg::HL); break;
        case 0x77: bit(6, Reg::A); break;

        case 0x78: bit(7, Reg::B); break;
        case 0x79: bit(7, Reg::C); break;
        case 0x7A: bit(7, Reg::D); break;
        case 0x7B: bit(7, Reg::E); break;
        case 0x7C: bit(7, Reg::H); break;
        case 0x7D: bit(7, Reg::L); break;
        case 0x7E: bitAddress(7, Reg::HL); break;
        case 0x7F: bit(7, Reg::A); break;

            // RES Instructions (0x80 - 0xBF)
        case 0x80: res(0, Reg::B); break;
        case 0x81: res(0, Reg::C); break;
        case 0x82: res(0, Reg::D); break;
        case 0x83: res(0, Reg::E); break;
        case 0x84: res(0, Reg::H); break;
        case 0x85: res(0, Reg::L); break;
        case 0x86: resAddress(0, Reg::HL); break;
        case 0x87: res(0, Reg::A); break;

        case 0x88: res(1, Reg::B); break;
        case 0x89: res(1, Reg::C); break;
        case 0x8A: res(1, Reg::D); break;
        case 0x8B: res(1, Reg::E); break;
        case 0x8C: res(1, Reg::H); break;
        case 0x8D: res(1, Reg::L); break;
        case 0x8E: resAddress(1, Reg::HL); break;
        case 0x8F: res(1, Reg::A); break;

        case 0x90: res(2, Reg::B); break;
        case 0x91: res(2, Reg::C); break;
        case 0x92: res(2, Reg::D); break;
        case 0x93: res(2, Reg::E); break;
        case 0x94: res(2, Reg::H); break;
        case 0x95: res(2, Reg::L); break;
        case 0x96: resAddress(2, Reg::HL); break;
        case 0x97: res(2, Reg::A); break;

        case 0x98: res(3, Reg::B); break;
        case 0x99: res(3, Reg::C); break;
        case 0x9A: res(3, Reg::D); break;
        case 0x9B: res(3, Reg::E); break;
        case 0x9C: res(3, Reg::H); break;
        case 0x9D: res(3, Reg::L); break;
        case 0x9E: resAddress(3, Reg::HL); break;
        case 0x9F: res(3, Reg::A); break;

        case 0xA0: res(4, Reg::B); break;
        case 0xA1: res(4, Reg::C); break;
        case 0xA2: res(4, Reg::D); break;
        case 0xA3: res(4, Reg::E); break;
        case 0xA4: res(4, Reg::H); break;
        case 0xA5: res(4, Reg::L); break;
        case 0xA6: resAddress(4, Reg::HL); break;
        case 0xA7: res(4, Reg::A); break;

        case 0xA8: res(5, Reg::B); break;
        case 0xA9: res(5, Reg::C); break;
        case 0xAA: res(5, Reg::D); break;
        case 0xAB: res(5, Reg::E); break;
        case 0xAC: res(5, Reg::H); break;
        case 0xAD: res(5, Reg::L); break;
        case 0xAE: resAddress(5, Reg::HL); break;
        case 0xAF: res(5, Reg::A); break;

        case 0xB0: res(6, Reg::B); break;
        case 0xB1: res(6, Reg::C); break;
        case 0xB2: res(6, Reg::D); break;
        case 0xB3: res(6, Reg::E); break;
        case 0xB4: res(6, Reg::H); break;
        case 0xB5: res(6, Reg::L); break;
        case 0xB6: resAddress(6, Reg::HL); break;
        case 0xB7: res(6, Reg::A); break;

        case 0xB8: res(7, Reg::B); break;
        case 0xB9: res(7, Reg::C); break;
        case 0xBA: res(7, Reg::D); break;
        case 0xBB: res(7, Reg::E); break;
        case 0xBC: res(7, Reg::H); break;
        case 0xBD: res(7, Reg::L); break;
        case 0xBE: resAddress(7, Reg::HL); break;
        case 0xBF: res(7, Reg::A); break;

            // SET Instructions (0xC0 - 0xFF)
        case 0xC0: set(0, Reg::B); break;
        case 0xC1: set(0, Reg::C); break;
        case 0xC2: set(0, Reg::D); break;
        case 0xC3: set(0, Reg::E); break;
        case 0xC4: set(0, Reg::H); break;
        case 0xC5: set(0, Reg::L); break;
        case 0xC6: setAddress(0, Reg::HL); break;
        case 0xC7: set(0, Reg::A); break;

        case 0xC8: set(1, Reg::B); break;
        case 0xC9: set(1, Reg::C); break;
        case 0xCA: set(1, Reg::D); break;
        case 0xCB: set(1, Reg::E); break;
        case 0xCC: set(1, Reg::H); break;
        case 0xCD: set(1, Reg::L); break;
        case 0xCE: setAddress(1, Reg::HL); break;
        case 0xCF: set(1, Reg::A); break;

        case 0xD0: set(2, Reg::B); break;
        case 0xD1: set(2, Reg::C); break;
        case 0xD2: set(2, Reg::D); break;
        case 0xD3: set(2, Reg::E); break;
        case 0xD4: set(2, Reg::H); break;
        case 0xD5: set(2, Reg::L); break;
        case 0xD6: setAddress(2, Reg::HL); break;
        case 0xD7: set(2, Reg::A); break;

        case 0xD8: set(3, Reg::B); break;
        case 0xD9: set(3, Reg::C); break;
        case 0xDA: set(3, Reg::D); break;
        case 0xDB: set(3, Reg::E); break;
        case 0xDC: set(3, Reg::H); break;
        case 0xDD: set(3, Reg::L); break;
        case 0xDE: setAddress(3, Reg::HL); break;
        case 0xDF: set(3, Reg::A); break;

        case 0xE0: set(4, Reg::B); break;
        case 0xE1: set(4, Reg::C); break;
        case 0xE2: set(4, Reg::D); break;
        case 0xE3: set(4, Reg::E); break;
        case 0xE4: set(4, Reg::H); break;
        case 0xE5: set(4, Reg::L); break;
        case 0xE6: setAddress(4, Reg::HL); break;
        case 0xE7: set(4, Reg::A); break;

        case 0xE8: set(5, Reg::B); break;
        case 0xE9: set(5, Reg::C); break;
        case 0xEA: set(5, Reg::D); break;
        case 0xEB: set(5, Reg::E); break;
        case 0xEC: set(5, Reg::H); break;
        case 0xED: set(5, Reg::L); break;
        case 0xEE: setAddress(5, Reg::HL); break;
        case 0xEF: set(5, Reg::A); break;

        case 0xF0: set(6, Reg::B); break;
        case 0xF1: set(6, Reg::C); break;
        case 0xF2: set(6, Reg::D); break;
        case 0xF3: set(6, Reg::E); break;
        case 0xF4: set(6, Reg::H); break;
        case 0xF5: set(6, Reg::L); break;
        case 0xF6: setAddress(6, Reg::HL); break;
        case 0xF7: set(6, Reg::A); break;

        case 0xF8: set(7, Reg::B); break;
        case 0xF9: set(7, Reg::C); break;
        case 0xFA: set(7, Reg::D); break;
        case 0xFB: set(7, Reg::E); break;
        case 0xFC: set(7, Reg::H); break;
        case 0xFD: set(7, Reg::L); break;
        case 0xFE: setAddress(7, Reg::HL); break;
        case 0xFF: set(7, Reg::A); break;

    default:
        throw std::invalid_argument("Invalid CB Operation code");
    }

}

void InstructionSet::cp(Reg reg)
{
    if (reg == Reg::AF || reg == Reg::BC || reg == Reg::DE || reg == Reg::HL || reg == Reg::SP)
        throw std::invalid_argument("16 bit register comparison not allowed");


    cp(m_cpu->getRegisterValue<uint8_t>(reg));
}

void InstructionSet::cp(uint8_t value)
{
    uint8_t A = m_cpu->getRegisterValue<uint8_t>(Reg::A);
    A -= (value + A);

    m_cpu->setSubtractFlag(true);
    m_cpu->setZeroFlag(A == 0x0);
    m_cpu->setHalfCarryFlag((value & 0x0F) > (A & 0x0F));
    m_cpu->setCarryFlag((value) > A);


}


void InstructionSet::cpl()
{
    uint8_t newVal = m_cpu->getRegisterValue<uint8_t>(Reg::A);

    m_cpu->setSubtractFlag(true);
    m_cpu->setHalfCarryFlag(true);

    newVal = ~newVal;
    m_cpu->setRegisterValue(Reg::A, newVal);
}

void InstructionSet::bit(int pos, Reg reg)
{
}

void InstructionSet::bitAddress(int pos, Reg reg)
{
}


void InstructionSet::res(int pos, Reg reg)
{
}

void InstructionSet::resAddress(int pos, Reg reg)
{
}

void InstructionSet::set(int pos, Reg reg)
{
}

void InstructionSet::setAddress(int pos, Reg reg)
{
}

void InstructionSet::swap(Reg reg)
{
}

void InstructionSet::swapAddress(Reg reg)
{
}

void InstructionSet::rlAddress(Reg reg, bool carryFlag)
{
}


void InstructionSet::rl(Reg reg, bool carryFlag)
{
}


void InstructionSet::pop(Reg reg)
{
    if (reg != Reg::AF && reg != Reg::BC && reg != Reg::DE && reg != Reg::HL && reg != Reg::SP)
        throw std::invalid_argument("8 bit register pop not allowed");

    ldAddress(m_cpu->getLo(reg), Reg::SP);
    inc(Reg::SP);
    ldAddress(m_cpu->getHi(reg), Reg::SP);
    inc(Reg::SP);

    if (reg == Reg::AF)
    {
        uint8_t F = m_cpu->getRegisterValue<uint8_t>(Reg::F);
        //bit 7
        m_cpu->setZeroFlag(F & 0x80);
        //bit 6
        m_cpu->setSubtractFlag(F & 0x40);
        //bit 5
        m_cpu->setHalfCarryFlag(F & 0x20);
        //bit 4
        m_cpu->setCarryFlag(F & 0x10);
    }

}

void InstructionSet::rr(Reg reg, bool carryFlag)
{
}

void InstructionSet::rrAddress(Reg reg, bool carryFlag)
{
}

void InstructionSet::sla(Reg reg)
{
}

void InstructionSet::slaAddress(Reg reg)
{
}

void InstructionSet::sra(Reg reg)
{
}

void InstructionSet::sraAddress(Reg reg)
{
}

void InstructionSet::srl(Reg reg)
{
}

void InstructionSet::srlAddress(Reg reg)
{
}

void InstructionSet::jp(bool condition, uint16_t address)
{
    if (condition)
    {
        m_cpu->setPC(address);
    }
}

void InstructionSet::jr(bool cc, int8_t destination)
{
    if (cc) 
        jr(destination);
}

void InstructionSet::jr(int8_t offset)
{
    assert(offset >= -128 && offset <= 127);
    m_cpu->setPC(m_cpu->getPC() + offset);
}

void InstructionSet::call(bool condition,uint16_t address)
{
    if (condition)
    {
        m_mmu->setWord(m_mmu->readWord(m_cpu->getRegisterValue<uint16_t>(Reg::SP)), m_cpu->getPC() + 2);
        inc(Reg::SP);
        inc(Reg::SP);
        jp(true, address);
    }
}

void InstructionSet::ret(bool condition)
{
    if (condition)
    {
        uint16_t returnAddress = m_mmu->readWord(m_cpu->getRegisterValue<uint16_t>(Reg::SP));
        m_cpu->setPC(returnAddress);
        inc(Reg::SP);
        inc(Reg::SP);
    }
}

void InstructionSet::push(Reg reg)
{
    if (reg != Reg::AF && reg != Reg::BC && reg != Reg::DE && reg != Reg::HL && reg != Reg::SP)
        throw std::invalid_argument("8 bit register push not allowed");


    ldAddress(Reg::SP, m_cpu->getHi(reg));
    dec(Reg::SP);
    ldAddress(Reg::SP, m_cpu->getLo(reg));
    dec(Reg::SP);

}

void InstructionSet::ei()
{
    //TODO:The flag is only set after the instruction following EI.
    m_cpu->setInterruptsFlag(true);
}


void InstructionSet::di()
{
    m_cpu->setInterruptsFlag(false);
}





void InstructionSet::daa()
{
    uint8_t adjustment = 0;

    if (m_cpu->getSubstractFlag())
    {
        if (m_cpu->getHalfCarryFlag()) adjustment += 0x6;
        if (m_cpu->getCarryFlag()) adjustment += 0x60;
        sub(adjustment, false);
    }
    else
    {
        uint8_t A = m_cpu->getRegisterValue<uint8_t>(Reg::A);
        if (m_cpu->getHalfCarryFlag() || (A & 0xF) > 0x9) adjustment += 0x6;
        if (m_cpu->getCarryFlag() || (A > 0x99))
        {
            adjustment += 0x60;
            m_cpu->setCarryFlag(true);
        }
        add(Reg::A,adjustment, false);

    }

    m_cpu->setZeroFlag(m_cpu->getRegisterValue<uint8_t>(Reg::A) == 0x0);
    m_cpu->setHalfCarryFlag(false);


}

void InstructionSet::ccf()
{
    m_cpu->setCarryFlag(!m_cpu->getCarryFlag());
}

void InstructionSet::scf()
{
    m_cpu->setCarryFlag(true);
}
