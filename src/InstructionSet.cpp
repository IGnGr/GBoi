#include "InstructionSet.h"
#include <stdexcept>


InstructionSet::InstructionSet(std::shared_ptr<CPU> cpu, std::shared_ptr<MMU> mmu)
{
	m_mmu = mmu;
	m_cpu = cpu;
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
        /*case 0x02:
            m_instructionMap[opcode] = [this]() { ld_bc_a(); };
            break;
        case 0x03:
            m_instructionMap[opcode] = [this]() { inc_bc(); };
            break;
        case 0x04:
            m_instructionMap[opcode] = [this]() { inc_b(); };
            break;
        case 0x05:
            m_instructionMap[opcode] = [this]() { dec_b(); };
            break;
        case 0x06:
            m_instructionMap[opcode] = [this]() { ld_b_n(); };
            break;
        case 0x07:
            m_instructionMap[opcode] = [this]() { rlca(); };
            break;
        case 0x08:
            m_instructionMap[opcode] = [this]() { ld_nn_sp(); };
            break;
        case 0x09:
            m_instructionMap[opcode] = [this]() { add_hl_bc(); };
            break;
        case 0x0A:
            m_instructionMap[opcode] = [this]() { ld_a_bc(); };
            break;
        case 0x0B:
            m_instructionMap[opcode] = [this]() { dec_bc(); };
            break;
        case 0x0C:
            m_instructionMap[opcode] = [this]() { inc_c(); };
            break;
        case 0x0D:
            m_instructionMap[opcode] = [this]() { dec_c(); };
            break;
        case 0x0E:
            m_instructionMap[opcode] = [this]() { ld_c_n(); };
            break;
        case 0x0F:
            m_instructionMap[opcode] = [this]() { rrca(); };
            break;
        case 0x10:
            m_instructionMap[opcode] = [this]() { stop(); };
            break;*/
    case 0x11:
        ld(Reg::DE, data);        
        break;
        /*
    case 0x12:
        m_instructionMap[opcode] = [this]() { ld_de_a(); };
        break;
    case 0x13:
        m_instructionMap[opcode] = [this]() { inc_de(); };
        break;
    case 0x14:
        m_instructionMap[opcode] = [this]() { inc_d(); };
        break;
    case 0x15:
        m_instructionMap[opcode] = [this]() { dec_d(); };
        break;
    case 0x16:
        m_instructionMap[opcode] = [this]() { ld_d_n(); };
        break;
    case 0x17:
        m_instructionMap[opcode] = [this]() { rla(); };
        break;
    case 0x18:
        m_instructionMap[opcode] = [this]() { jr_n(); };
        break;
    case 0x19:
        m_instructionMap[opcode] = [this]() { add_hl_de(); };
        break;
    case 0x20:
        m_instructionMap[opcode] = [this]() { jr_nz(); };
        break;
    case 0x21:
        m_instructionMap[opcode] = [this]() { ld_hl_nn(); };
        break;
    case 0x22:
        m_instructionMap[opcode] = [this]() { ldi_hl_a(); };
        break;
    case 0x23:
        m_instructionMap[opcode] = [this]() { inc_hl(); };
        break;
    case 0x24:
        m_instructionMap[opcode] = [this]() { inc_h(); };
        break;
    case 0x25:
        m_instructionMap[opcode] = [this]() { dec_h(); };
        break;
    case 0x26:
        m_instructionMap[opcode] = [this]() { ld_h_n(); };
        break;
    case 0x27:
        m_instructionMap[opcode] = [this]() { daa(); };
        break;
    case 0x28:
        m_instructionMap[opcode] = [this]() { jr_z(); };
        break;
    case 0x29:
        m_instructionMap[opcode] = [this]() { add_hl_hl(); };
        break;
    case 0x30:
        m_instructionMap[opcode] = [this]() { jr_nc(); };
        break;
    case 0x31:
        m_instructionMap[opcode] = [this]() { ld_sp_nn(); };
        break;
    case 0x32:
        m_instructionMap[opcode] = [this]() { ldd_hl_a(); };
        break;
    case 0x33:
        m_instructionMap[opcode] = [this]() { inc_sp(); };
        break;
    case 0x34:
        m_instructionMap[opcode] = [this]() { inc_hl(); };
        break;
    case 0x35:
        m_instructionMap[opcode] = [this]() { dec_hl(); };
        break;
    case 0x36:
        m_instructionMap[opcode] = [this]() { ld_hl_n(); };
        break;
    case 0x37:
        m_instructionMap[opcode] = [this]() { scf(); };
        break;
    case 0x38:
        m_instructionMap[opcode] = [this]() { jr_c(); };
        break;
    case 0x39:
        m_instructionMap[opcode] = [this]() { add_hl_sp(); };
        break;
    case 0x40:
        m_instructionMap[opcode] = [this]() { ld_b_b(); };
        break;
    case 0x41:
        m_instructionMap[opcode] = [this]() { ld_c_b(); };
        break;
    case 0x42:
        m_instructionMap[opcode] = [this]() { ld_d_b(); };
        break;
    case 0x43:
        m_instructionMap[opcode] = [this]() { ld_e_b(); };
        break;
    case 0x44:
        m_instructionMap[opcode] = [this]() { ld_h_b(); };
        break;
    case 0x45:
        m_instructionMap[opcode] = [this]() { ld_l_b(); };
        break;
    case 0x46:
        m_instructionMap[opcode] = [this]() { ld_hl_b(); };
        break;
    case 0x47:
        m_instructionMap[opcode] = [this]() { ld_a_b(); };
        break;
    case 0x48:
        m_instructionMap[opcode] = [this]() { ld_b_c(); };
        break;
    case 0x49:
        m_instructionMap[opcode] = [this]() { ld_c_c(); };
        break;
    case 0x4A:
        m_instructionMap[opcode] = [this]() { ld_d_c(); };
        break;
    case 0x4B:
        m_instructionMap[opcode] = [this]() { ld_e_c(); };
        break;
    case 0x4C:
        m_instructionMap[opcode] = [this]() { ld_h_c(); };
        break;
    case 0x4D:
        m_instructionMap[opcode] = [this]() { ld_l_c(); };
        break;
    case 0x4E:
        m_instructionMap[opcode] = [this]() { ld_hl_c(); };
        break;
    case 0x4F:
        m_instructionMap[opcode] = [this]() { ld_a_c(); };
        break;
    case 0x50:
        m_instructionMap[opcode] = [this]() { ld_d_b(); };
        break;
    case 0x51:
        m_instructionMap[opcode] = [this]() { ld_d_c(); };
        break;
    case 0x52:
        m_instructionMap[opcode] = [this]() { ld_d_d(); };
        break;
    case 0x53:
        m_instructionMap[opcode] = [this]() { ld_d_e(); };
        break;
    case 0x54:
        m_instructionMap[opcode] = [this]() { ld_d_h(); };
        break;
    case 0x55:
        m_instructionMap[opcode] = [this]() { ld_d_l(); };
        break;
    case 0x56:
        m_instructionMap[opcode] = [this]() { ld_hl_d(); };
        break;
    case 0x57:
        m_instructionMap[opcode] = [this]() { ld_a_d(); };
        break;
    case 0x58:
        m_instructionMap[opcode] = [this]() { ld_e_b(); };
        break;
    case 0x59:
        m_instructionMap[opcode] = [this]() { ld_e_c(); };
        break;
    case 0x5A:
        m_instructionMap[opcode] = [this]() { ld_e_d(); };
        break;
    case 0x5B:
        m_instructionMap[opcode] = [this]() { ld_e_e(); };
        break;
    case 0x5C:
        m_instructionMap[opcode] = [this]() { ld_e_h(); };
        break;
    case 0x5D:
        m_instructionMap[opcode] = [this]() { ld_e_l(); };
        break;
    case 0x5E:
        m_instructionMap[opcode] = [this]() { ld_hl_e(); };
        break;
    case 0x5F:
        m_instructionMap[opcode] = [this]() { ld_e_a(); };
        break;
    case 0x60:
        m_instructionMap[opcode] = [this]() { ld_h_b(); };
        break;
    case 0x61:
        m_instructionMap[opcode] = [this]() { ld_h_c(); };
        break;
    case 0x62:
        m_instructionMap[opcode] = [this]() { ld_h_d(); };
        break;
    case 0x63:
        m_instructionMap[opcode] = [this]() { ld_h_e(); };
        break;
    case 0x64:
        m_instructionMap[opcode] = [this]() { ld_h_h(); };
        break;
    case 0x65:
        m_instructionMap[opcode] = [this]() { ld_h_l(); };
        break;
    case 0x66:
        m_instructionMap[opcode] = [this]() { ld_hl_h(); };
        break;
    case 0x67:
        m_instructionMap[opcode] = [this]() { ld_a_h(); };
        break;
    case 0x68:
        m_instructionMap[opcode] = [this]() { ld_l_b(); };
        break;
    case 0x69:
        m_instructionMap[opcode] = [this]() { ld_l_c(); };
        break;
    case 0x70:
        m_instructionMap[opcode] = [this]() { ld_hl_b(); };
        break;
    case 0x71:
        m_instructionMap[opcode] = [this]() { ld_hl_c(); };
        break;
    case 0x72:
        m_instructionMap[opcode] = [this]() { ld_hl_d(); };
        break;
    case 0x73:
        m_instructionMap[opcode] = [this]() { ld_hl_e(); };
        break;
    case 0x74:
        m_instructionMap[opcode] = [this]() { ld_hl_h(); };
        break;
    case 0x75:
        m_instructionMap[opcode] = [this]() { ld_hl_l(); };
        break;
    case 0x76:
        m_instructionMap[opcode] = [this]() { halt(); };
        break;
    case 0x77:
        m_instructionMap[opcode] = [this]() { ld_hl_a(); };
        break;
    case 0x78:
        m_instructionMap[opcode] = [this]() { ld_a_b(); };
        break;
    case 0x79:
        m_instructionMap[opcode] = [this]() { ld_a_c(); };
        break;
    case 0x80:
        m_instructionMap[opcode] = [this]() { add_a_b(); };
        break;
    case 0x81:
        m_instructionMap[opcode] = [this]() { add_a_c(); };
        break;
    case 0x82:
        m_instructionMap[opcode] = [this]() { add_a_d(); };
        break;
    case 0x83:
        m_instructionMap[opcode] = [this]() { add_a_e(); };
        break;
    case 0x84:
        m_instructionMap[opcode] = [this]() { add_a_h(); };
        break;
    case 0x85:
        m_instructionMap[opcode] = [this]() { add_a_l(); };
        break;
    case 0x86:
        m_instructionMap[opcode] = [this]() { add_a_hl(); };
        break;
    case 0x87:
        m_instructionMap[opcode] = [this]() { add_a_a(); };
        break;
    case 0x88:
        m_instructionMap[opcode] = [this]() { adc_a_b(); };
        break;
    case 0x89:
        m_instructionMap[opcode] = [this]() { adc_a_c(); };
        break;
    case 0x8A:
        m_instructionMap[opcode] = [this]() { adc_a_d(); };
        break;
    case 0x8B:
        m_instructionMap[opcode] = [this]() { adc_a_e(); };
        break;
    case 0x8C:
        m_instructionMap[opcode] = [this]() { adc_a_h(); };
        break;
    case 0x8D:
        m_instructionMap[opcode] = [this]() { adc_a_l(); };
        break;
    case 0x8E:
        m_instructionMap[opcode] = [this]() { adc_a_hl(); };
        break;
    case 0x8F:
        m_instructionMap[opcode] = [this]() { adc_a_a(); };
        break;
    case 0x90:
        m_instructionMap[opcode] = [this]() { sub_b(); };
        break;
    case 0x91:
        m_instructionMap[opcode] = [this]() { sub_c(); };
        break;
    case 0x92:
        m_instructionMap[opcode] = [this]() { sub_d(); };
        break;
    case 0x93:
        m_instructionMap[opcode] = [this]() { sub_e(); };
        break;
    case 0x94:
        m_instructionMap[opcode] = [this]() { sub_h(); };
        break;
    case 0x95:
        m_instructionMap[opcode] = [this]() { sub_l(); };
        break;
    case 0x96:
        m_instructionMap[opcode] = [this]() { sub_hl(); };
        break;
    case 0x97:
        m_instructionMap[opcode] = [this]() { sub_a(); };
        break;
    case 0x98:
        m_instructionMap[opcode] = [this]() { sbc_a_b(); };
        break;
    case 0x99:
        m_instructionMap[opcode] = [this]() { sbc_a_c(); };
        break;
    case 0x9A:
        m_instructionMap[opcode] = [this]() { sbc_a_d(); };
        break;
    case 0x9B:
        m_instructionMap[opcode] = [this]() { sbc_a_e(); };
        break;
    case 0x9C:
        m_instructionMap[opcode] = [this]() { sbc_a_h(); };
        break;
    case 0x9D:
        m_instructionMap[opcode] = [this]() { sbc_a_l(); };
        break;
    case 0x9E:
        m_instructionMap[opcode] = [this]() { sbc_a_hl(); };
        break;
    case 0x9F:
        m_instructionMap[opcode] = [this]() { sbc_a_a(); };
        break;
    case 0xA0:
        m_instructionMap[opcode] = [this]() { and_b(); };
        break;
    case 0xA1:
        m_instructionMap[opcode] = [this]() { and_c(); };
        break;
    case 0xA2:
        m_instructionMap[opcode] = [this]() { and_d(); };
        break;
    case 0xA3:
        m_instructionMap[opcode] = [this]() { and_e(); };
        break;
    case 0xA4:
        m_instructionMap[opcode] = [this]() { and_h(); };
        break;
    case 0xA5:
        m_instructionMap[opcode] = [this]() { and_l(); };
        break;
    case 0xA6:
        m_instructionMap[opcode] = [this]() { and_hl(); };
        break;
    case 0xA7:
        m_instructionMap[opcode] = [this]() { and_a(); };
        break;
    case 0xA8:
        m_instructionMap[opcode] = [this]() { xor_b(); };
        break;
    case 0xA9:
        m_instructionMap[opcode] = [this]() { xor_c(); };
        break;
    case 0xAA:
        m_instructionMap[opcode] = [this]() { xor_d(); };
        break;
    case 0xAB:
        m_instructionMap[opcode] = [this]() { xor_e(); };
        break;
    case 0xAC:
        m_instructionMap[opcode] = [this]() { xor_h(); };
        break;
    case 0xAD:
        m_instructionMap[opcode] = [this]() { xor_l(); };
        break;
    case 0xAE:
        m_instructionMap[opcode] = [this]() { xor_hl(); };
        break;
    case 0xAE:
    m_instructionMap[opcode] = [this]() { xor_hl(); };
    break;
    case 0xAF:
        m_instructionMap[opcode] = [this]() { xor_a(); };
        break;
    case 0xB0:
        m_instructionMap[opcode] = [this]() { or_b(); };
        break;
    case 0xB1:
        m_instructionMap[opcode] = [this]() { or_c(); };
        break;
    case 0xB2:
        m_instructionMap[opcode] = [this]() { or_d(); };
        break;
    case 0xB3:
        m_instructionMap[opcode] = [this]() { or_e(); };
        break;
    case 0xB4:
        m_instructionMap[opcode] = [this]() { or_h(); };
        break;
    case 0xB5:
        m_instructionMap[opcode] = [this]() { or_l(); };
        break;
    case 0xB6:
        m_instructionMap[opcode] = [this]() { or_hl(); };
        break;
    case 0xB7:
        m_instructionMap[opcode] = [this]() { or_a(); };
        break;
    case 0xB8:
        m_instructionMap[opcode] = [this]() { cp_b(); };
        break;
    case 0xB9:
        m_instructionMap[opcode] = [this]() { cp_c(); };
        break;
    case 0xBA:
        m_instructionMap[opcode] = [this]() { cp_d(); };
        break;
    case 0xBB:
        m_instructionMap[opcode] = [this]() { cp_e(); };
        break;
    case 0xBC:
        m_instructionMap[opcode] = [this]() { cp_h(); };
        break;
    case 0xBD:
        m_instructionMap[opcode] = [this]() { cp_l(); };
        break;
    case 0xBE:
        m_instructionMap[opcode] = [this]() { cp_hl(); };
        break;
    case 0xBF:
        m_instructionMap[opcode] = [this]() { cp_a(); };
        break;
    case 0xC0:
        m_instructionMap[opcode] = [this]() { ret_nz(); };
        break;
    case 0xC1:
        m_instructionMap[opcode] = [this]() { pop_bc(); };
        break;
    case 0xC2:
        m_instructionMap[opcode] = [this]() { jp_nz_nn(); };
        break;
    case 0xC3:
        m_instructionMap[opcode] = [this]() { jp_nn(); };
        break;
    case 0xC4:
        m_instructionMap[opcode] = [this]() { call_nz_nn(); };
        break;
    case 0xC5:
        m_instructionMap[opcode] = [this]() { push_bc(); };
        break;
    case 0xC6:
        m_instructionMap[opcode] = [this]() { add_a_n(); };
        break;
    case 0xC7:
        m_instructionMap[opcode] = [this]() { rst_00(); };
        break;
    case 0xC8:
        m_instructionMap[opcode] = [this]() { ret_z(); };
        break;
    case 0xC9:
        m_instructionMap[opcode] = [this]() { ret(); };
        break;
    case 0xCA:
        m_instructionMap[opcode] = [this]() { jp_z_nn(); };
        break;
    case 0xCB:
        m_instructionMap[opcode] = [this]() { cb(); };
        break;
    case 0xCC:
        m_instructionMap[opcode] = [this]() { call_z_nn(); };
        break;
    case 0xCD:
        m_instructionMap[opcode] = [this]() { call_nn(); };
        break;
    case 0xCE:
        m_instructionMap[opcode] = [this]() { adc_a_n(); };
        break;
    case 0xCF:
        m_instructionMap[opcode] = [this]() { rst_08(); };
        break;
    case 0xD0:
        m_instructionMap[opcode] = [this]() { ret_nc(); };
        break;
    case 0xD1:
        m_instructionMap[opcode] = [this]() { pop_de(); };
        break;
    case 0xD2:
        m_instructionMap[opcode] = [this]() { jp_nc_nn(); };
        break;
    case 0xD4:
        m_instructionMap[opcode] = [this]() { call_nc_nn(); };
        break;
    case 0xD5:
        m_instructionMap[opcode] = [this]() { push_de(); };
        break;
    case 0xD6:
        m_instructionMap[opcode] = [this]() { sub_n(); };
        break;
    case 0xD7:
        m_instructionMap[opcode] = [this]() { rst_10(); };
        break;
    case 0xD8:
        m_instructionMap[opcode] = [this]() { ret_c(); };
        break;
    case 0xD9:
        m_instructionMap[opcode] = [this]() { reti(); };
        break;
    case 0xDA:
        m_instructionMap[opcode] = [this]() { jp_c_nn(); };
        break;
    case 0xDC:
        m_instructionMap[opcode] = [this]() { call_c_nn(); };
        break;
    case 0xDE:
        m_instructionMap[opcode] = [this]() { sbc_a_n(); };
        break;
    case 0xDF:
        m_instructionMap[opcode] = [this]() { rst_18(); };
        break;
    case 0xE0:
        m_instructionMap[opcode] = [this]() { ldh_n_a(); };
        break;
    case 0xE1:
        m_instructionMap[opcode] = [this]() { pop_hl(); };
        break;
    case 0xE2:
        m_instructionMap[opcode] = [this]() { ld_c_a(); };
        break;
    case 0xE5:
        m_instructionMap[opcode] = [this]() { push_hl(); };
        break;
    case 0xE6:
        m_instructionMap[opcode] = [this]() { and_n(); };
        break;
    case 0xE7:
        m_instructionMap[opcode] = [this]() { rst_20(); };
        break;
    case 0xE8:
        m_instructionMap[opcode] = [this]() { add_sp_n(); };
        break;
    case 0xE9:
        m_instructionMap[opcode] = [this]() { jp_hl(); };
        break;
    case 0xEA:
        m_instructionMap[opcode] = [this]() { ld_nn_a(); };
        break;
    case 0xEE:
        m_instructionMap[opcode] = [this]() { xor_n(); };
        break;
    case 0xEF:
        m_instructionMap[opcode] = [this]() { rst_28(); };
        break;
    case 0xF0:
        m_instructionMap[opcode] = [this]() { ldh_a_n(); };
        break;
    case 0xF1:
        m_instructionMap[opcode] = [this]() { pop_af(); };
        break;
    case 0xF2:
        m_instructionMap[opcode] = [this]() { ld_a_c(); };
        break;
    case 0xF3:
        m_instructionMap[opcode] = [this]() { di(); };
        break;
    case 0xF5:
        m_instructionMap[opcode] = [this]() { push_af(); };
        break;
    case 0xF6:
        m_instructionMap[opcode] = [this]() { or_n(); };
        break;
    case 0xF7:
        m_instructionMap[opcode] = [this]() { rst_30(); };
        break;
    case 0xF8:
        m_instructionMap[opcode] = [this]() { ld_hl_sp_n(); };
        break;
    case 0xF9:
        m_instructionMap[opcode] = [this]() { ld_sp_hl(); };
        break;
    case 0xFA:
        m_instructionMap[opcode] = [this]() { ld_a_nn(); };
        break;
    case 0xFB:
        m_instructionMap[opcode] = [this]() { ei(); };
        break;
    case 0xFE:
        m_instructionMap[opcode] = [this]() { cp_n(); };
        break;
    case 0xFF:
        m_instructionMap[opcode] = [this]() { rst_38(); };
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
}

void InstructionSet::halt()
{
}

void InstructionSet::ld(Reg reg, uint16_t value)
{
	m_cpu->setRegisterValue(reg, value);
}


void InstructionSet::ldh()
{
}

void InstructionSet::inc()
{
}

void InstructionSet::dec()
{
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
