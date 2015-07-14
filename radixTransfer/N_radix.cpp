#include "N_radix.h"
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <sstream>
using namespace std;
const char* N_radix::BC =
		"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
N_radix::N_radix() :
		_radix(0), _str(""), _lenght(), _char(0)
{
}
N_radix::N_radix(int radix, string str)
{
	//radix max is 62
	if (radix < 63)
	{
		this->_radix = radix;
	}
	else
	{
		throw "Initialization ERROR 0: radix is two big (not bigger then 62)\n";
	}
	setChar(radix);
	this->_lenght = str.size();
	if (!isValid(str))
	{
		throw("");
	}
	this->_str = str;
}
int N_radix::getRedix() const
{
	return this->_radix;
}

void N_radix::setChar(int radix)
{
	char* ch = new char[radix];
	for (int i = 0; i < radix; i++)
	{
		ch[i] = N_radix::BC[i];
	}
	this->_char = ch;
}
string N_radix::getValue() const
{
	return this->_str;
}
inline int N_radix::lenght() const
{
	return _str.size();
}

inline char* N_radix::baseChar()
{
	return _char;
}

N_radix::N_radix(const N_radix &rhs)
{
	_str = rhs._str;
	_radix = rhs._radix;
	_char = rhs._char;
	_lenght = rhs._lenght;
}

const N_radix N_radix::operator+(const N_radix &rhs) const
{
	if (this->_radix == rhs._radix)
	{
		int baseRadix = this->_radix;
		stringstream ss;
		string str1 = this->transferValue(baseRadix, 10, this->_str);
		string str2 = rhs.transferValue(baseRadix, 10, rhs._str);
		int n1, n2;
		//int trnafer to string
		ss << str1;
		ss >> n1;
		ss.str("");
		ss.clear();
		ss << str2;
		ss >> n2;
		int result = n1 + n2; //(atoi(str1.c_str()) + atoi(str1.c_str()));
		//string transfer to int
		string str3;
		ss.str("");
		ss.clear();
		ss << result;
		ss >> str3;
		str3 = this->transferValue(10, baseRadix, str3);
		N_radix nr(baseRadix, str3);
		return nr;
	}
	throw("operation add ERROR: base number has different radix to destnation number!");
}

const N_radix N_radix::operator-(const N_radix &rhs) const
{
	if (this->_radix == rhs._radix)
	{
		int baseRadix = this->_radix;
		stringstream ss;
		string str1 = this->transferValue(baseRadix, 10, this->_str);
		string str2 = rhs.transferValue(baseRadix, 10, rhs._str);
		int n1, n2;
		ss << str1;
		ss >> n1;
		ss.str("");
		ss.clear();
		ss << str2;
		ss >> n2;
		int result = n1 - n2;
		string str3;
		ss.str("");
		ss.clear();
		ss << result;
		ss >> str3;
		str3 = this->transferValue(10, baseRadix, str3);
		N_radix nr(baseRadix, str3);
		return nr;
	}
	throw("operation add ERROR: base number has different radix to destnation number!");
}

const N_radix N_radix::operator*(const N_radix &rhs) const
{
	if (this->_radix == rhs._radix)
	{
		int baseRadix = this->_radix;
		stringstream ss;
		string str1 = this->transferValue(baseRadix, 10, this->_str);
		string str2 = rhs.transferValue(baseRadix, 10, rhs._str);
		int n1, n2;
		ss << str1;
		ss >> n1;
		ss.str("");
		ss.clear();
		ss << str2;
		ss >> n2;
		int result = n1 * n2;
		string str3;
		ss.str("");
		ss.clear();
		ss << result;
		ss >> str3;
		str3 = this->transferValue(10, baseRadix, str3);
		N_radix nr(baseRadix, str3);
		return nr;
	}
	throw("operation add ERROR: base number has different radix to destnation number!");
}

const N_radix N_radix::operator/(const N_radix &rhs) const
{
	if (this->_radix == rhs._radix)
	{
		int baseRadix = this->_radix;
		stringstream ss;
		string str1 = this->transferValue(baseRadix, 10, this->_str);
		string str2 = rhs.transferValue(baseRadix, 10, rhs._str);
		int n1, n2;
		ss << str1;
		ss >> n1;
		ss.str("");
		ss.clear();
		ss << str2;
		ss >> n2;
		int result = n1 / n2;
		string str3;
		ss.str("");
		ss.clear();
		ss << result;
		ss >> str3;
		str3 = this->transferValue(10, baseRadix, str3);
		N_radix nr(baseRadix, str3);
		return nr;
	}
	throw("operation add ERROR: base number has different radix to destnation number!");

}

string N_radix::transferValue(int baseRadix, int destRadix,
		string baseString) const
{
	//进制转换
	vector<int> ch;
	double sum = 0;
	const char* baseStr = baseString.c_str();
	for (int i = 0; i < baseString.size(); i++)
	{
		sum += this->getIndexOfChar(baseStr[i])
				* pow((double) (baseRadix), (double) ((baseString.size() - 1 - i)));
	}
	int result = sum;
	int remainder = 0;
	int k = 1;
	while (result > destRadix)
	{
		result = sum / destRadix;
		remainder = (static_cast<int>(sum)) % destRadix;
		sum = result;
		k++;
		ch.push_back(remainder);
	}
	ch.push_back(result);
	string str;
	int size = ch.size();
	for (int j = 0; j <= size - 1; j++)
	{
		char c = _char[ch[size - 1 - j]];
		str.insert(j, 1, c);
	}
	return str;
}

N_radix &N_radix::tranferRadixValue(int radix)
{
	//进制转换
	string str = transferValue(this->_radix,radix, this->_str);
	this->_radix = radix;
	this->_str = str;
	this->_lenght = this->lenght();
	setChar(radix);
	return *this;
}

bool N_radix::isValid(string &str)
{
	const char* ch = str.c_str();
	for (int i = 0; i < _lenght; ++i)
	{
		if (getIndexOfChar(ch[i]) == -1)
		{
			throw("Function N_radix::isValid ERROR 2:input number is invalid!!! Please input again:");
			return false;
		}
	}
	return true;
}

int N_radix::getIndexOfChar(char ch) const
{
	for (int i = 0; i < _radix; ++i)
	{
		if (ch != _char[i])
		{
			continue;
		}
		else
		{
			return i;
		}
	}
	throw("Function N_radix::getIndexOfChar ERROR 1:cant't match char in the basic char");
	return -1;
}

