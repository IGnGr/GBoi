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
        rlca();
        break;/*
    case 0x08:
        ld(Reg::SP, );
        break;
    case 0x09:
        add_hl_bc();
        break;
    case 0x0A:
        ld_a_bc();
        break;
    case 0x0B:
        dec_bc();
        break;
    case 0x0C:
        inc_c();
        break;
    case 0x0D:
        dec_c();
        break;
    case 0x0E:
        ld_c_n();
        break;
    case 0x0F:
        rrca();
        break;*/
    case 0x10:
        stop();
        break;
    case 0x11:
        ld(Reg::DE, data);        
        break;
        /*
    case 0x12:
        ld_de_a();
        break;
    case 0x13:
        inc_de();
        break;
    case 0x14:
        inc_d();
        break;
    case 0x15:
        dec_d();
        break;
    case 0x16:
        ld_d_n();
        break;
    case 0x17:
        rla();
        break;
    case 0x18:
        jr_n();
        break;
    case 0x19:
        add_hl_de();
        break;
    case 0x20:
        jr_nz();
        break;
    case 0x21:
        ld_hl_nn();
        break;
    case 0x22:
        ldi_hl_a();
        break;
    case 0x23:
        inc_hl();
        break;
    case 0x24:
        inc_h();
        break;
    case 0x25:
        dec_h();
        break;
    case 0x26:
        ld_h_n();
        break;
    case 0x27:
        daa();
        break;
    case 0x28:
        jr_z();
        break;
    case 0x29:
        add_hl_hl();
        break;
    case 0x30:
        jr_nc();
        break;
    case 0x31:
        ld_sp_nn();
        break;
    case 0x32:
        ldd_hl_a();
        break;
    case 0x33:
        inc_sp();
        break;
    case 0x34:
        inc_hl();
        break;
    case 0x35:
        dec_hl();
        break;
    case 0x36:
        ld_hl_n();
        break;
    case 0x37:
        scf();
        break;
    case 0x38:
        jr_c();
        break;
    case 0x39:
        add_hl_sp();
        break;
    case 0x40:
        ld_b_b();
        break;
    case 0x41:
        ld_c_b();
        break;
    case 0x42:
        ld_d_b();
        break;
    case 0x43:
        ld_e_b();
        break;
    case 0x44:
        ld_h_b();
        break;
    case 0x45:
        ld_l_b();
        break;
    case 0x46:
        ld_hl_b();
        break;
    case 0x47:
        ld_a_b();
        break;
    case 0x48:
        ld_b_c();
        break;
    case 0x49:
        ld_c_c();
        break;
    case 0x4A:
        ld_d_c();
        break;
    case 0x4B:
        ld_e_c();
        break;
    case 0x4C:
        ld_h_c();
        break;
    case 0x4D:
        ld_l_c();
        break;
    case 0x4E:
        ld_hl_c();
        break;
    case 0x4F:
        ld_a_c();
        break;
    case 0x50:
        ld_d_b();
        break;
    case 0x51:
        ld_d_c();
        break;
    case 0x52:
        ld_d_d();
        break;
    case 0x53:
        ld_d_e();
        break;
    case 0x54:
        ld_d_h();
        break;
    case 0x55:
        ld_d_l();
        break;
    case 0x56:
        ld_hl_d();
        break;
    case 0x57:
        ld_a_d();
        break;
    case 0x58:
        ld_e_b();
        break;
    case 0x59:
        ld_e_c();
        break;
    case 0x5A:
        ld_e_d();
        break;
    case 0x5B:
        ld_e_e();
        break;
    case 0x5C:
        ld_e_h();
        break;
    case 0x5D:
        ld_e_l();
        break;
    case 0x5E:
        ld_hl_e();
        break;
    case 0x5F:
        ld_e_a();
        break;
    case 0x60:
        ld_h_b();
        break;
    case 0x61:
        ld_h_c();
        break;
    case 0x62:
        ld_h_d();
        break;
    case 0x63:
        ld_h_e();
        break;
    case 0x64:
        ld_h_h();
        break;
    case 0x65:
        ld_h_l();
        break;
    case 0x66:
        ld_hl_h();
        break;
    case 0x67:
        ld_a_h();
        break;
    case 0x68:
        ld_l_b();
        break;
    case 0x69:
        ld_l_c();
        break;
    case 0x70:
        ld_hl_b();
        break;
    case 0x71:
        ld_hl_c();
        break;
    case 0x72:
        ld_hl_d();
        break;
    case 0x73:
        ld_hl_e();
        break;
    case 0x74:
        ld_hl_h();
        break;
    case 0x75:
        ld_hl_l();
        break;
    case 0x76:
        halt();
        break;
    case 0x77:
        ld_hl_a();
        break;
    case 0x78:
        ld_a_b();
        break;
    case 0x79:
        ld_a_c();
        break;
    case 0x80:
        add_a_b();
        break;
    case 0x81:
        add_a_c();
        break;
    case 0x82:
        add_a_d();
        break;
    case 0x83:
        add_a_e();
        break;
    case 0x84:
        add_a_h();
        break;
    case 0x85:
        add_a_l();
        break;
    case 0x86:
        add_a_hl();
        break;
    case 0x87:
        add_a_a();
        break;
    case 0x88:
        adc_a_b();
        break;
    case 0x89:
        adc_a_c();
        break;
    case 0x8A:
        adc_a_d();
        break;
    case 0x8B:
        adc_a_e();
        break;
    case 0x8C:
        adc_a_h();
        break;
    case 0x8D:
        adc_a_l();
        break;
    case 0x8E:
        adc_a_hl();
        break;
    case 0x8F:
        adc_a_a();
        break;
    case 0x90:
        sub_b();
        break;
    case 0x91:
        sub_c();
        break;
    case 0x92:
        sub_d();
        break;
    case 0x93:
        sub_e();
        break;
    case 0x94:
        sub_h();
        break;
    case 0x95:
        sub_l();
        break;
    case 0x96:
        sub_hl();
        break;
    case 0x97:
        sub_a();
        break;
    case 0x98:
        sbc_a_b();
        break;
    case 0x99:
        sbc_a_c();
        break;
    case 0x9A:
        sbc_a_d();
        break;
    case 0x9B:
        sbc_a_e();
        break;
    case 0x9C:
        sbc_a_h();
        break;
    case 0x9D:
        sbc_a_l();
        break;
    case 0x9E:
        sbc_a_hl();
        break;
    case 0x9F:
        sbc_a_a();
        break;
    case 0xA0:
        and_b();
        break;
    case 0xA1:
        and_c();
        break;
    case 0xA2:
        and_d();
        break;
    case 0xA3:
        and_e();
        break;
    case 0xA4:
        and_h();
        break;
    case 0xA5:
        and_l();
        break;
    case 0xA6:
        and_hl();
        break;
    case 0xA7:
        and_a();
        break;
    case 0xA8:
        xor_b();
        break;
    case 0xA9:
        xor_c();
        break;
    case 0xAA:
        xor_d();
        break;
    case 0xAB:
        xor_e();
        break;
    case 0xAC:
        xor_h();
        break;
    case 0xAD:
        xor_l();
        break;
    case 0xAE:
        xor_hl();
        break;
    case 0xAE:
    xor_hl();
    break;
    case 0xAF:
        xor_a();
        break;
    case 0xB0:
        or_b();
        break;
    case 0xB1:
        or_c();
        break;
    case 0xB2:
        or_d();
        break;
    case 0xB3:
        or_e();
        break;
    case 0xB4:
        or_h();
        break;
    case 0xB5:
        or_l();
        break;
    case 0xB6:
        or_hl();
        break;
    case 0xB7:
        or_a();
        break;
    case 0xB8:
        cp_b();
        break;
    case 0xB9:
        cp_c();
        break;
    case 0xBA:
        cp_d();
        break;
    case 0xBB:
        cp_e();
        break;
    case 0xBC:
        cp_h();
        break;
    case 0xBD:
        cp_l();
        break;
    case 0xBE:
        cp_hl();
        break;
    case 0xBF:
        cp_a();
        break;
    case 0xC0:
        ret_nz();
        break;
    case 0xC1:
        pop_bc();
        break;
    case 0xC2:
        jp_nz_nn();
        break;
    case 0xC3:
        jp_nn();
        break;
    case 0xC4:
        call_nz_nn();
        break;
    case 0xC5:
        push_bc();
        break;
    case 0xC6:
        add_a_n();
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
        break;
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


void InstructionSet::rlca()
{
    uint8_t A = m_cpu->getRegisterValue<uint8_t>(Reg::A);
    m_cpu->setCarryFlag(A & 0x80);
    //Shift A left by 1 bit and set the least significant bit to the value of the carry flag.
    A = (A << 1) | (A >> 7);
    m_cpu->setRegisterValue(Reg::A, A);

}


void InstructionSet::inc(Reg reg)
{
	if (reg == Reg::AF || reg == Reg::BC || reg == Reg::DE || reg == Reg::HL|| reg == Reg::SP)
		m_cpu->setRegisterValue(reg, static_cast<uint16_t>(m_cpu->getRegisterValue<uint16_t>(reg) + 1));
	else
        m_cpu->setRegisterValue(reg, static_cast<uint8_t> (m_cpu->getRegisterValue<uint8_t>(reg) + 1));
}


void InstructionSet::dec(Reg reg)
{
    if (reg == Reg::AF || reg == Reg::BC || reg == Reg::DE || reg == Reg::HL || reg == Reg::SP)
        m_cpu->setRegisterValue(reg, static_cast<uint16_t>(m_cpu->getRegisterValue<uint16_t>(reg) - 1));
    else
        m_cpu->setRegisterValue(reg, static_cast<uint8_t> (m_cpu->getRegisterValue<uint8_t>(reg) - 1));
}

void InstructionSet::andOp()
{
}

void InstructionSet::orOp()
{
}

void InstructionSet::xorOp()
{
}

void InstructionSet::bit()
{
}

void InstructionSet::add()
{
}

void InstructionSet::adc()
{
}

void InstructionSet::sub()
{
}

void InstructionSet::sbc()
{
}

void InstructionSet::cp()
{
}

void InstructionSet::cpl()
{
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

void InstructionSet::jp()
{
}

void InstructionSet::jr()
{
}

void InstructionSet::call()
{
}

void InstructionSet::ret()
{
}

void InstructionSet::reti()
{
}

void InstructionSet::rst()
{
}

void InstructionSet::daa()
{
}

void InstructionSet::ccf()
{
}

void InstructionSet::scf()
{
}
