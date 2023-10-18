#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class MyBigInt {
public:
	MyBigInt();
	void setHex(std::string hexNumber);
	std::string getHex();
	MyBigInt INV();
	MyBigInt XOR(MyBigInt other);
	MyBigInt OR(MyBigInt other);
	MyBigInt AND(MyBigInt other);
	MyBigInt shiftR(int num);
	MyBigInt shiftL(int num);
	MyBigInt ADD(MyBigInt other);
	MyBigInt SUB(MyBigInt other);
	MyBigInt MOD(MyBigInt other);
private:
	const int MAX_HEX_LEN = 16;
	std::vector<uint64_t> number;
	uint64_t hexadecimalToDecimal(std::string hexVal);
	std::string decimalToHexadecimal(uint64_t number);
	bool validateHexChars(std::string hexNumber);
};