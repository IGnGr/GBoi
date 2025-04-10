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
        rst_00();
        break;
    case 0xC8:
        ret_z();
        break;
    case 0xC9:
        ret();
        break;
    case 0xCA:
        jp_z_nn();
        break;
    case 0xCB:
        cb();
        break;
    case 0xCC:
        call_z_nn();
        break;
    case 0xCD:
        call_nn();
        break;
    case 0xCE:
        adc_a_n();
        break;
    case 0xCF:
        rst_08();
        break;/*
    case 0xD0:
        ret_nc();
        break;
    case 0xD1:
        pop_de();
        break;
    case 0xD2:
        jp_nc_nn();
        break;
    case 0xD4:
        call_nc_nn();
        break;
    case 0xD5:
        push_de();
        break;
    case 0xD6:
        sub_n();
        break;
    case 0xD7:
        rst_10();
        break;
    case 0xD8:
        ret_c();
        break;
    case 0xD9:
        reti();
        break;
    case 0xDA:
        jp_c_nn();
        break;
    case 0xDC:
        call_c_nn();
        break;
    case 0xDE:
        sbc_a_n();
        break;
    case 0xDF:
        rst_18();
        break;
    case 0xE0:
        ldh_n_a();
        break;
    case 0xE1:
        pop_hl();
        break;
    case 0xE2:
        ld_c_a();
        break;
    case 0xE5:
        push_hl();
        break;
    case 0xE6:
        and_n();
        break;
    case 0xE7:
        rst_20();
        break;
    case 0xE8:
        add_sp_n();
        break;
    case 0xE9:
        jp_hl();
        break;
    case 0xEA:
        ld_nn_a();
        break;
    case 0xEE:
        xor_n();
        break;
    case 0xEF:
        rst_28();
        break;
    case 0xF0:
        ldh_a_n();
        break;
    case 0xF1:
        pop_af();
        break;
    case 0xF2:
        ld_a_c();
        break;
    case 0xF3:
        di();
        break;
    case 0xF5:
        push_af();
        break;
    case 0xF6:
        or_n();
        break;
    case 0xF7:
        rst_30();
        break;
    case 0xF8:
        ld_hl_sp_n();
        break;
    case 0xF9:
        ld_sp_hl();
        break;
    case 0xFA:
        ld_a_nn();
        break;
    case 0xFB:
        ei();
        break;
    case 0xFE:
        cp_n();
        break;
    case 0xFF:
        rst_38();
        break;*/
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

void InstructionSet::bit()
{
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


void InstructionSet::adc()
{
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

void InstructionSet::sbc()
{
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

void InstructionSet::res()
{
}

void InstructionSet::set()
{
}

void InstructionSet::swap()
{
}

void InstructionSet::rlc()
{
}

void InstructionSet::rl()
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
        uint16_t F = m_cpu->getRegisterValue<uint8_t>(Reg::F);
        //bit 7
        m_cpu->setZeroFlag(F & 0x40);
        //bit 6
        m_cpu->setSubtractFlag(F & 0x20);
        //bit 5
        m_cpu->setHalfCarryFlag(F & 0x10);
        //bit 4
        m_cpu->setCarryFlag(F & 0x08);
    }

}

void InstructionSet::rrc()
{
}

void InstructionSet::rr()
{
}

void InstructionSet::sla()
{
}

void InstructionSet::sra()
{
}

void InstructionSet::srl()
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


void InstructionSet::reti()
{
}

void InstructionSet::rst()
{
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
