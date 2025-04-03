#include "MBC.h"


MBC::MBC(int nBanks)
{
	m_nBanks = nBanks;
	m_ROMBanks.reserve(nBanks);

	for (int i = 0; i < nBanks; i++)
	{
		m_ROMBanks.push_back(std::vector<uint8_t>(0x4000, 0));
	}
}




