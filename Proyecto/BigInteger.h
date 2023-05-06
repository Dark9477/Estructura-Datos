/*

Autor: Benjamin Ortiz Morales

Codigo: 8978145

TAD BigInteger

*/

#ifndef __BigInteger_H
#define __BigInteger_H

#include <iostream>
#include <string>
#include <vector>


using namespace std;

typedef string Cadena;

class bigInteger{
	public:
		vector<int> big;

		//Constructoras:
		bigInteger();
		bigInteger(Cadena cad);
		bigInteger(bigInteger& big);

		//Modificadoras 

		void add(bigInteger& big);
		void product(bigInteger& big);
		void substract(bigInteger& big);
		void quotient(bigInteger& big);
		void remainder(bigInteger& big);
		void pow(bigInteger& big);
		string toString();

		//Sobrecarga

		bigInteger operator+(bigInteger& big);
		bigInteger operator-(bigInteger& big);
		bigInteger operator*(bigInteger& big);
		bigInteger operator/(bigInteger& big);
		bigInteger operator%(bigInteger& big);
		bool operator==(bigInteger& big);
		bool operator<(bigInteger& big);
		bool operator<=(bigInteger& big);
};

#endif

