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

BigInteger::BigInteger(){
	big.push_back(0);
}


BigInteger::BigInteger(string cad){
	if(cad[0] == '-'){
		esPositivo = false;
	}
	else{
		esPositivo = true;
	}

	for(int i = cad.size() - 1; i >= 0; i--){
		if(esPositivo || i != 0){
			big.push_back(cad[i] - '0');
		}
	}
}


BigInteger::BigInteger(BigInteger& big){
	this->esPositivo = big.esPositivo;
	for(int i = 0; i < big.big.size(); i++){
		this->big.push_back(big.big[i]);
	}
}



//Modificadoras

void BigInteger::add(BigInteger& big){
	int i = 0;
	int sum;
	int sobra = 0;

	if(this->esPositivo == big.esPositivo){
		while(i < this->big.size() || i < big.big.size() || sobra){
			if(i >= this->big.size()){
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
	else if(this->esPositivo == true && big.esPositivo == false){
		big.esPositivo = true;
		if(*this == big){
			this->big.clear();
			this->big.push_back(0);
		}
		else{
			substract(big);
		}
	}
	else if(this->esPositivo == false && big.esPositivo == true){
		big.esPositivo = false;
		if(*this == big){
			this->big.clear();
			this->big.push_back(0);
			this->esPositivo = true;
		}
		else{
			substract(big);
		}
	}
}

BigInteger BigInteger::operator+(BigInteger& big){
	BigInteger ans(*this);
	ans.add(big);
	return ans;
}



string BigInteger::toString(){
	string res = "";
	if(!esPositivo){
		res += '-';
	}

	for(int i = big.size() - 1; i >= 0; i--){
		char digit = '0' + big[i];
		res += digit;
	}
	return res;
}

void BigInteger::product(BigInteger& big){

	if(esPositivo == false && big.esPositivo == false){
		esPositivo = true;
	}
	else if(esPositivo == true && big.esPositivo == false){
		esPositivo = false;
	}
	else if(esPositivo == false && big.esPositivo == true){
		esPositivo = false;
	}
	else{
		esPositivo = true;
	}

	int sobra = 0;
	int suma = 0;
	BigInteger temp;

	for(int i = 0; i < big.big.size() || i < this->big.size(); i++){
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

		if(sobra != 0){
			temp.big[i + this->big.size()] += sobra;
			sobra = 0;
			suma = 0;
		}
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

BigInteger BigInteger::operator*(BigInteger& big){
	BigInteger ans(*this);
	ans.product(big);
	return ans;
}


void BigInteger::pow(int num){
	BigInteger temp(*this);
	for(int i = 0; i < num - 1; i++){
		product(temp);
	}
}

bool BigInteger::operator==(BigInteger& big){
	bool ans = true;
	if(this->esPositivo == big.esPositivo){
		if(this->big.size() != big.big.size()){
			ans = false;
		}
		else{
			for(int i = 0; i < this->big.size() && ans; i++){
				if(this->big[i] != big.big[i]){
				ans = false;
				}
			}
		}
	}
	else if(this->esPositivo == false && big.esPositivo == true){
		ans = false;
	}
	else if(this->esPositivo == true && big.esPositivo == false){
		ans = false;
	}

	return ans;
}

bool BigInteger::operator<=(BigInteger& big){
	bool ans = true;
	bool flag = true;
	if(this->esPositivo == true && big.esPositivo == true){
		if(this->big.size() < big.big.size()){
			ans = true;
		}
		else if(this->big.size() > big.big.size()){
			ans = false;
		}
		else{
			for(int i = this->big.size(); i >= 0 && ans && flag; i--){
				if(this->big[i] > big.big[i]){
					ans = false;
				}
				if(this->big[i] < big.big[i]){
					ans = true;
					flag = false;
				}
				if(this->big[i] == big.big[i]){
					ans = true;
				}
			}
		}
	}
	else if(this->esPositivo == false && big.esPositivo == true){
		ans = true;
	}
	else if(this->esPositivo == true && big.esPositivo == false){
		ans = false;
	}
	else{
		if(this->big.size() < big.big.size()){
			ans = false;
		}
		else if(this->big.size() > big.big.size()){
			ans = true;
		}
		else{
			for(int i = this->big.size(); i >= 0 && ans && flag; i--){
				if(this->big[i] > big.big[i]){
					ans = true;
					flag = false;
				}
				if(this->big[i] < big.big[i]){
					ans = false;
					flag = false;
				}
				if(this->big[i] == big.big[i]){
					ans = true;
				}
			}
		}		
	}


	return ans;
}

bool BigInteger::operator<(BigInteger& big){
	bool ans = true;
	bool flag = true;
	if(this->esPositivo == true && big.esPositivo == true){
		if(this->big.size() < big.big.size()){
			ans = true;
		}
		else if(this->big.size() > big.big.size()){
			ans = false;
		}
		else if(*this==big){
			ans = false;
		}
		else{
			for(int i = this->big.size() - 1; i >= 0 && ans && flag; i--){
				if(this->big[i] > big.big[i]){
					ans = false;
				}
				if(this->big[i] < big.big[i]){
					ans = true;
					flag = false;
				}
			}
		}
	}
	else if(this->esPositivo == true && big.esPositivo == false){
		ans = false;
	}
	else if(this->esPositivo == false && big.esPositivo == true){
		ans = true;
	}
	else{
		if(this->big.size() < big.big.size()){
			ans = false;
		}
		else if(this->big.size() > big.big.size()){
			ans = true;
		}
		else if(*this==big){
			ans = false;
		}
		else{
			for(int i = this->big.size() - 1; i >= 0 && ans && flag; i--){
				if(this->big[i] > big.big[i]){
					ans = true;
					flag = false;
				}
				if(this->big[i] < big.big[i]){
					ans = false;
					flag = false;
				}
			}
		}		
	}
	return ans;
}



void BigInteger::substract(BigInteger& big){
	bool flag = true;
	bool flag2 = false;
	if(this->esPositivo == true && big.esPositivo == true){
		BigInteger temp(big);
		if(*this < big){
			this->esPositivo = false;
		}
		if(*this == big){
			this->big.clear();
			this->big.push_back(0);
			flag2 = true;
		}
		else{
			if(this->esPositivo){
				int i = 0;
				while(i < this->big.size() || i < big.big.size()){
					if(i < big.big.size()){
						if(this->big[i] >= big.big[i]){
							this->big[i] -= big.big[i];
						}
						else{
							for(int s = i + 1; s < this->big.size() && flag; s++){
								if(this->big[s] > 0){
									this->big[s] -= 1;
									flag = false;
								}
								else if(this->big[s] == 0){
									this->big[s] = 9;
								}
							}
							this->big[i] += 10;
							this->big[i] -= big.big[i];
						}
					}
					i++;
				}	
			}
			else{
				int i = 0;
				while(i < this->big.size() || i < temp.big.size()){
					if(i < this->big.size()){
						if(temp.big[i] >= this->big[i]){
							temp.big[i] -= this->big[i];
						}
						else{
							for(int s = i + 1; s < temp.big.size() && flag; s++){
								if(temp.big[s] > 0){
									temp.big[s] -= 1;
									flag = false;
								}
								else if(temp.big[s] == 0){
									temp.big[s] = 9;
								}
							}
							temp.big[i] += 10;
							temp.big[i] -= this->big[i];
						}
					}
					i++;
				}
				
			}
		}
		if(!this->esPositivo){
			this->big = temp.big;
		}
			
		if(!flag2){
			int s = this->big.size() - 1;
			while(this->big[s] == 0){
				this->big.pop_back();
				s = this->big.size() - 1;
			}			
		}


	}
	else if(this->esPositivo == true && big.esPositivo == false){
		big.esPositivo = true;
		add(big);
	}
	else if(this->esPositivo == false && big.esPositivo == true){
		big.esPositivo = false;
		add(big);
	}
	else{
		bool temp;
		if(*this < big){
			temp = false;
			this->esPositivo = true;
			big.esPositivo = true;
			substract(big);
			this->esPositivo = temp;
		}
		else if(*this == big){
			this->big.clear();
			this->big.push_back(0);
		}	
		else{
			temp = true;
			this->esPositivo = true;
			big.esPositivo = true;
			substract(big);
			this->esPositivo = temp;
		}
	}
}


BigInteger BigInteger::operator-(BigInteger& big){
	BigInteger ans(*this);
	ans.substract(big);
	return ans;
}
