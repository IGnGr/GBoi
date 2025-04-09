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
    void rotateLeft(Reg reg, bool setCarryFlag);
    void rotateRight(Reg reg, bool setCarryFlag);
    void dec(Reg reg);
    void andOp();
    void orOp();
    void xorOp();
    void bit();
    void add(Reg reg1, Reg reg2);
    void adc();
    void sub(Reg reg);

    void sub(uint8_t value);
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
    void jp(Reg reg);
    void jr(bool cc, int8_t destination);
    void jr(int8_t offset);
    void call();
    void ret();
    void reti();
    void rst();
    void decimalAdjustAccumulator();
    void ccf();
    void scf();
};
