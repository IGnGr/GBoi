#pragma once
#include <vector>
#include <memory>

class MBC {

protected: 
	std::vector<std::vector<uint8_t>> m_ROMBanks;
	int m_nBanks = 0;
	int m_currentBank = 0;

public:
	MBC(int nBanks);
	~MBC() {};
	//Getters and Setters
	std::vector<uint8_t> getCurrentBank() const { return m_ROMBanks[m_currentBank]; }
	void setCurrentBank(int bank) { m_currentBank = bank; };

};

class MBC0 : public MBC {

public:
	MBC0(int nBanks) : MBC(nBanks) {};
	~MBC0() {};
};

class MBC1 : public MBC {

public:
    MBC1(int nBanks) : MBC(nBanks) {};
    ~MBC1() {};
};

class MBC2 : public MBC {

public:
    MBC2(int nBanks) : MBC(nBanks) {};
    ~MBC2() {};
};

class MBC3 : public MBC {

public:
	MBC3(int nBanks) : MBC(nBanks) {};
    ~MBC3() {};
};


//TODO:MBC5, MBC6, MBC7, MMM01, HuC1, HuC3, HuC5, ...
