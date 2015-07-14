#include <string>
#include <iostream>
using namespace std;

/*a class of 2 to 62 raidx,can do some arithmatic operation,transfer
 * one radix to another radix ,which just do for integer ,but don't include
 * decimal.That can be optimizing buy using 2 radix as the transit instead
 * of 10 radix,and add the decimal management.
 * */
class N_radix
{
public:
	//constructor
	N_radix();
	N_radix(int redix, string str);
	//copy constructor
	N_radix(const N_radix &rhs);
	//set basic chars
	void setChar(int radix);
	//get the radix of current number
	inline int getRedix() const;
	//get the value of current number (is a stirng)
	string getValue() const;
	//the lenght of the number's char for example: 101 lenght is 3
	inline int lenght() const;
	//get the basic chars
	inline char* baseChar();
	/*truansfer one radix of number to another.for example:
	 2 radix value is "0101" trnsfer to 10 radix ,the value
	 should be 5.
	 */
	N_radix& tranferRadixValue(int radix);
	//assiginment function
	//N_radix& operator=(N_radix const &rhs);
	//override operation add
	const N_radix operator+(const N_radix &rhs) const;
	//override operation minus
	const N_radix operator-(const N_radix &rhs) const;
	//override operation multiplication
	const N_radix operator*(const N_radix &rhs) const;
	//override operation divide
	const N_radix operator/(const N_radix &rhs) const;
private:
	int getIndexOfChar(char ch) const;
	//check the chars of a number is valid
	bool isValid(string &str);
	//transfer a string to another radix string
	string transferValue(int baseRadix,int destRadix,string baseString) const;
	int _radix;
	string _str;
	int _lenght;
	char* _char;
	static const char* BC;

	/*{'0','1','2','3','4','5','6','7','8','9',
	 'A','B','C','D','E','F','G','H','I','J',
	 'K','L','M','N','O','P','Q','R','S','T',
	 'U','V','W','X','Y','Z',
	 'a','b','c','d','e','f','g','h','i','j',
	 'k','l','m','n','o','p','q','r','s','t',
	 'u','v','w','x','y','z'};*/
};
//const char* BC="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
