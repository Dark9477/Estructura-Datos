/*

Autor: Benjamin Ortiz Morales

Codigo: 8978145

Implementacion TAD BigInteger

*/

#include "BigInteger.h"
#include <string>
#include <vector>
#include <iostream>


using namespace std;

//Constructores

bigInteger::bigInteger(){
	big.push_back(0);
}


bigInteger::bigInteger(string cad){
	for(int i = cad.size() - 1; i >= 0; i--){
		big.push_back(cad[i] - '0');
	}
}


bigInteger::bigInteger(bigInteger& big){
	for(int i = 0; i < big.big.size(); i++){
		this->big.push_back(big.big[i]);
	}
}



//Modificadoras

void bigInteger::add(bigInteger& big){
	int i = 0;
	int sum;
	int sobra = 0;
	while(i < this->big.size() || i < big.big.size() || sobra){
		if(i == this->big.size()){
			this->big.push_back(0);
		}
		sum = this->big[i] + sobra;
		if (i < big.big.size()) {
			sum += big.big[i];
		}
		this->big[i] = sum % 10;
		sobra = sum / 10;
		i++;
	}
}

string bigInteger::toString(){
	string res = "";
	for(int i = big.size() - 1; i >= 0; i--) {
		res += to_string(big[i]);
	}
	return res;
}

void bigInteger::product(bigInteger& big){
	int sobra = 0;
	int suma = 0;
	bigInteger temp;

	for(int i = 0; i < big.big.size() -1 || i < this->big.size() -1; i++){
		temp.big.push_back(0);
	}

	for(int i = 0; i < big.big.size(); i++){
		for(int s = 0; s < this->big.size(); s++){
			suma += this->big[s] * big.big[i];
			sobra = suma / 10;
			suma = suma % 10;
			temp.big[s + i] += suma;
			suma = sobra;
		}
		temp.big.push_back(0);
	}
	for(int i = 0; i < temp.big.size(); i++){
		if(temp.big[i] > 9){
			sobra = temp.big[i] / 10;
			suma = temp.big[i] % 10;
			temp.big[i] = suma;
			temp.big[i + 1] += sobra;
		}
	}
	int i = 0;
	int s = temp.big.size() - 1;
	while(temp.big[s] == 0){
		temp.big.pop_back();
		s = temp.big.size() - 1;
	}
	this->big = temp.big;
}

