#pragma once
#include <unordered_map>
#include <functional>
#include <optional>
#include "CPU.h"
#include "MMU.h"


using Reg = CPU::RegisterType;

class InstructionSet
{
private:

	std::shared_ptr<MMU> m_mmu;
    std::shared_ptr<CPU> m_cpu;


public:
    InstructionSet(std::shared_ptr<CPU> cpu, std::shared_ptr<MMU> mmu);
    ~InstructionSet();
    void executeInstruction(uint8_t opCode);
    void nop();
    void stop();
    void halt();
    void ld(Reg reg, uint16_t value);
    void ld(Reg reg, uint8_t value);
    void ld(Reg regFrom, Reg regTo);
    void ldAddress(Reg regAddress, Reg regValue);
    void ldAddress(uint8_t address, Reg reg);
    void ldAddress(uint16_t address, Reg reg);
    void ldh(uint16_t address, Reg A);
    void ldh(uint8_t c, Reg A);
    void inc(Reg reg);
    void rlca();
    void dec(Reg reg);
    void andOp();
    void orOp();
    void xorOp();
    void bit();
    void add();
    void adc();
    void sub();
    void sbc();
    void cp();
    void cpl();
    void res();
    void set();
    void swap();
    void rlc();
    void rl();
    void rrc();
    void rr();
    void sla();
    void sra();
    void srl();
    void jp();
    void jr();
    void call();
    void ret();
    void reti();
    void rst();
    void daa();
    void ccf();
    void scf();
};
