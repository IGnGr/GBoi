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
    void ldAddress(Reg regAddress, uint8_t value);
    void ldAddress(uint8_t address, Reg reg);
    void ldAddress(uint16_t address, Reg reg);
    void ldh(uint16_t address, Reg A);
    void ldh(uint8_t c, Reg A);
    void inc(Reg reg);
    void incAddress(Reg reg);
    void rotateLeft(Reg reg, bool setCarryFlag);
    void rotateRight(Reg reg, bool setCarryFlag);
    void dec(Reg reg);
    void andOp(Reg reg);
    void andOp(uint8_t value);

    void orOp(Reg reg);
    void orOp(uint8_t value);
    void xorOp(Reg reg);
    void xorOp(uint8_t value);
    void bit();
    void add(Reg reg, uint8_t value, bool carryFlag);
    void add(Reg reg, uint16_t value, bool carryFlag);
    void add(Reg reg1, Reg reg2, bool carryFlag);
    void adc();
    void sub(Reg reg, bool carryFlag);
    void sub(uint8_t value, bool carryFlag);
    void sbc();
    //Compare
    void cp(uint8_t value);
    void cp(Reg reg);

    void cpl();
    void res();
    void set();
    void swap();
    void rlc();
    void rl();
    void pop(Reg reg);

    void rrc();
    void rr();
    void sla();
    void sra();
    void srl();
    void jp(bool condition, uint16_t address);

    void jr(bool cc, int8_t destination);
    void jr(int8_t offset);
    void call(bool condition, uint16_t address);
    //Return from subroutine
    void ret(bool condition);
    void push(Reg reg);

    void reti();
    void rst();
    //decimalAdjustAccumulator
    void daa();
    //ComplementCarryFlag
    void ccf();
    //setCarryFlag
    void scf();
};
