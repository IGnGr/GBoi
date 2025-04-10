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
    void ld(Reg regTo, Reg regFrom, int8_t offset);
    void ldAddress(Reg regAddress, Reg regValue);
    void ldAddress(Reg regAddress, uint8_t value);
    void ldAddress(uint8_t address, Reg reg);
    void ldAddress(uint16_t address, Reg reg);
    void ldh(uint16_t address, Reg A);
    void ldh(uint8_t c, Reg A);
    void ldh(Reg reg, uint16_t value);
    void ldh(Reg reg, uint8_t value);
    void inc(Reg reg);
    void incAddress(Reg reg);
    void dec(Reg reg);
    void andOp(Reg reg);
    void andOp(uint8_t value);

    void orOp(Reg reg);
    void orOp(uint8_t value);
    void xorOp(Reg reg);
    void xorOp(uint8_t value);
    void add(Reg reg, uint8_t value, bool carryFlag);
    void add(Reg reg, uint16_t value, bool carryFlag);
    void add(Reg reg1, Reg reg2, bool carryFlag);
    void sub(Reg reg, bool carryFlag);
    void sub(uint8_t value, bool carryFlag);

    //Shift, rotation and bit instructions
    void cb(uint16_t operation);

    //Compare
    void cp(uint8_t value);
    void cp(Reg reg);

    void cpl();
    void pop(Reg reg);


    void bit(uint8_t pos, Reg reg);
    void bitAddress(uint8_t pos, Reg reg);
    void res(uint8_t pos, Reg reg);
    void resAddress(uint8_t pos, Reg reg);
    void set(uint8_t pos, Reg reg);
    void setAddress(uint8_t pos, Reg reg);
    void rlAddress(Reg reg, bool carryFlag);
    void swap(Reg reg);
    void swapAddress(Reg reg);
    //rotateLeft
    void rl(Reg reg, bool setCarryFlag);
    //rotateRight
    void rr(Reg reg, bool setCarryFlag);
    void rrAddress(Reg reg, bool carryFlag);
    void sla(Reg reg);
    void slaAddress(Reg reg);
    void sra(Reg reg);
    void sraAddress(Reg reg);
    void srl(Reg reg);
    void srlAddress(Reg reg);
    void jp(bool condition, uint16_t address);

    void jr(bool cc, int8_t destination);
    void jr(int8_t offset);
    void call(bool condition, uint16_t address);
    //Return from subroutine
    void ret(bool condition);
    void push(Reg reg);
    //EnableInterrupts
    void ei();
    //DisableInterruptions
    void di();
    //decimalAdjustAccumulator
    void daa();
    //ComplementCarryFlag
    void ccf();
    //setCarryFlag
    void scf();
};
