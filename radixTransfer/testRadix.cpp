//============================================================================
// Name        : test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include "N_radix.h"
using namespace std;

//int main()
int testRadix()
{
	//operation test
	N_radix nr1(10,"12");
	N_radix nr2(10,"15");
	N_radix nr3=nr1+nr2;
	N_radix nr4(16,"E");
	N_radix nr5(16,"F");
	N_radix nr6=nr4+nr5;
	cout<<nr3.getValue()<<"   "<<nr6.getValue();
	return 0;
}
