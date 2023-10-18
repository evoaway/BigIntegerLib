#include "MyBigInt.h"

MyBigInt::MyBigInt()
{
}

void MyBigInt::setHex(std::string hexNumber)
{
    std::transform(hexNumber.begin(), hexNumber.end(), hexNumber.begin(),
        [](unsigned char c) { return std::tolower(c); });
	if (validateHexChars(hexNumber)) {
		number.clear();
		int blocks_num = (hexNumber.length() + MAX_HEX_LEN - 1) / MAX_HEX_LEN;
        for (size_t i = hexNumber.length(); i >= 16; i -= 16) {
            std::string block = hexNumber.substr(i - 16, 16);
            number.push_back(hexadecimalToDecimal(block));
        }
        if (hexNumber.length() % 16 != 0) {
            std::string block = hexNumber.substr(0, hexNumber.length() % 16);
            number.push_back(hexadecimalToDecimal(block));
        }

	}
}

std::string MyBigInt::getHex()
{
    if (number.size() == 0)
        return "0";
    std::string hexNum = "";
    for (size_t i = number.size(); i > 0; i--)
    {
        hexNum += decimalToHexadecimal(number[i - 1]);
    }
	return hexNum;
}

MyBigInt MyBigInt::INV()
{
    MyBigInt result;
    for (size_t i = 0; i < number.size(); i++)
    {
        result.number.push_back(~number[i]);
    }
    return result;
}

MyBigInt MyBigInt::XOR(MyBigInt other)
{
    MyBigInt result;
    int max_len = std::max(number.size(), other.number.size());
    for (int i = 0; i < max_len; i++)
    {
        uint64_t num1 = i < number.size() ? number[i] : 0;
        uint64_t num2 = i < other.number.size() ? other.number[i] : 0;
        uint64_t res = num1 ^ num2;
        result.number.push_back(res);
    }
    return result;
}

MyBigInt MyBigInt::OR(MyBigInt other)
{
    MyBigInt result;
    int max_len = std::max(number.size(), other.number.size());
    for (int i = 0; i < max_len; i++)
    {
        if (i > number.size()) {
            result.number.push_back(other.number[i]);
        }
        else if (i > other.number.size()) {
            result.number.push_back(number[i]);
        }
        else {
            result.number.push_back(number[i] | other.number[i]);
        }
    }
    return result;
}

MyBigInt MyBigInt::AND(MyBigInt other)
{
    MyBigInt result;
    int max_len = std::max(number.size(), other.number.size());
    for (int i = 0; i < max_len; i++)
    {
        if (i > number.size()) {
            result.number.push_back(0);
        }
        else if (i > other.number.size()) {
            result.number.push_back(0);
        }
        else {
            result.number.push_back(number[i] & other.number[i]);
        }
    }
    return result;
}

MyBigInt MyBigInt::shiftR(int num)
{
    MyBigInt result;
    for (int i = 0; i < number.size(); i++)
    {
        result.number.push_back(number[i] >> num);
        if (i > 0) {
            result.number[i] |= (number[i - 1] << (MAX_HEX_LEN - num));
        }
    }
    return result;
}

MyBigInt MyBigInt::shiftL(int num)
{
    MyBigInt result;
    for (int i = 0; i < number.size(); i++)
    {
        result.number.push_back(number[i] << num);
        if (i > 0) {
            result.number[i] |= (number[i - 1] >> (MAX_HEX_LEN - num));
        }
    }
    return result;
}

MyBigInt MyBigInt::ADD(MyBigInt other)
{
    MyBigInt result;
    uint64_t cary = 0;
    size_t max_len = std::max(number.size(), other.number.size());
    result.number.resize(max_len, 0);
    for (size_t i = 0; i < max_len; ++i) {
        if (i > number.size()) {
            result.number[i] = number[i];
        }
        else if (i > other.number.size()) {
            result.number[i] = other.number[i];
        }
        else {
            result.number[i] = number[i] + other.number[i] + cary;
        }
        if (result.number[i] < number[i] || result.number[i] < other.number[i])
            cary = 1;
        else
            cary = 0;
    }
    if (cary) {
        result.number.push_back(cary);
    }
    return result;
}

MyBigInt MyBigInt::SUB(MyBigInt other)
{
    //Not done!
    MyBigInt result;
    /*if (other.number.size() > number.size() ||
        (other.number[0] > number[0] && other.number.size() == number.size())) {
        std::cout << "The second number must be less than the first!";
        return;
    }*/
    return result;
}

MyBigInt MyBigInt::MOD(MyBigInt other)
{
    return MyBigInt();
}

uint64_t MyBigInt::hexadecimalToDecimal(std::string hexNumber)
{
    uint64_t len = hexNumber.length();
    uint64_t base = 1;
    uint64_t decValue = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (hexNumber[i] >= '0' && hexNumber[i] <= '9') {
            decValue += (uint64_t(hexNumber[i]) - 48) * base;

            base = base * 16;
        }
        else if (hexNumber[i] >= 'a' && hexNumber[i] <= 'f') {
            decValue += (uint64_t(hexNumber[i]) - 87) * base;

            base = base * 16;
        }
    }
    return decValue;
}

std::string MyBigInt::decimalToHexadecimal(uint64_t number)
{
    uint64_t remainder, product = 1;
    std::string hexNum = "";
    while (number != 0) {
        remainder = number % 16;
        char ch;
        if (remainder >= 10)
            ch = remainder + 87;
        else
            ch = remainder + 48;
        hexNum += ch;

        number /= 16;
        product *= 10;
    }
    reverse(hexNum.begin(), hexNum.end());
    return hexNum;
}

bool MyBigInt::validateHexChars(std::string hexNumber)
{
    if (hexNumber.length() == 0) {
        std::cout << "Number cannot be an empty string!";
        return false;
    }
    for (size_t i = 0; i < hexNumber.length(); i++)
    {
        if (hexNumber[i] < '0'
            || (hexNumber[i] > '9' && hexNumber[i] < 'a')
            || hexNumber[i] > 'f') {
            std::cout << "Number contains invalid characters!";
            return false;
        }
    }
    return true;
}
