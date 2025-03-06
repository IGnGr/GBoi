#include "Utils.h"

std::string Utils::ToBase(unsigned i, unsigned base)
{
	const std::string DIGITS = "0123456789ABCDEF";
	return i ? ToBase(i / base, base) + DIGITS[i % base] : "";
}

std::string Utils::ReadMemoryByteInHex(unsigned i)
{
	std::string ans = ToBase(i, 16);
	if (i < 0xF) ans = "0" + ans;
	if (i == '\0') ans = "00";
	return ans;
}
