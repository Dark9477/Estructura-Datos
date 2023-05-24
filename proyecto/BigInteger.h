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

class BigInteger{
	private:
		vector<int> big;
		bool esPositivo;

	public:
		//Constructoras:
		BigInteger(); //YA
		BigInteger(string cad); //YA
		BigInteger(BigInteger& big); //YA

		//Modificadoras 

		void add(BigInteger& big); //YA
		void product(BigInteger& big); //YA
		void substract(BigInteger& big); //YA
		void quotient(BigInteger& big);
		void remainder(BigInteger& big);
		void pow(int num); //YA
		string toString(); //YA

		//Sobrecarga

		BigInteger operator+(BigInteger& big); //YA
		BigInteger operator-(BigInteger& big); //YA
		BigInteger operator*(BigInteger& big); //YA
		BigInteger operator/(BigInteger& big);
		BigInteger operator%(BigInteger& big);
		bool operator==(BigInteger& big); //YA
		bool operator<(BigInteger& big); //YA
		bool operator<=(BigInteger& big); //YA
};

#endif

