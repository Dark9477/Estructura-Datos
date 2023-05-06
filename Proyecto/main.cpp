/*

Autor: Benjamin Ortiz Morales

Codigo: 8978145

Implementacion TAD BigInteger

*/

#include <iostream>
#include <string>
#include <vector>
#include "BigInteger.h"

using namespace std;

int main(){
	bigInteger b1("12345");
	bigInteger b2("12345");

	b1.product(b2);

	cout << b1.toString() << endl;



	return 0;
}