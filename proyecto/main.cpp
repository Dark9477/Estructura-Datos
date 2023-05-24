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
	BigInteger resultado;
	BigInteger b1("-100");
	BigInteger b2("1000");

	resultado = b1 + b2;

	cout << resultado.toString() << endl;



	return 0;
}