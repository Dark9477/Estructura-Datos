/*

Benjamin Ortiz Morales

8978145

Realizacion del punto rails

10/05/2023

*/

//En el peor de los casos la complejidad es de O(n^2)

#include <iostream>
#include <string>
#include <stack>
#include <list>


using namespace std;

void vaciarPila(stack<int>& pila){
	while(!pila.empty()){
		pila.pop();
	}
}

int main(){
	int caso;
	int cont;
	int tama;
	int bandera;
	int tempo;
	int bandera2;
	list<int> temp;
	cin >> caso;
	stack<int> entrada;
	stack<int> a;
	stack<int> station;
	stack<int> b;

	while(caso != 0){
		for(int i = caso; i > 0; i--){
			entrada.push(i);
		}
		int i = 0;
		bandera = 0;
		while(i < caso && bandera == 0){ //O(n)
			cin >> cont;
			if(cont == 0 && i == 0){
				bandera = 1;
			}
			else{
				temp.push_back(cont);
			}
			
			i++;
		}
		int tam = temp.size();
		for(i = 0; i < tam; i++){ //O(n)
			tempo = temp.back();
			a.push(tempo);
			temp.pop_back();
		}

		if(bandera == 0){
			tama = a.size();
			for(int s = 0; s < tama; s++){ //O(n)
				station.push(entrada.top());
				entrada.pop();

				if(station.top() == a.top()){
					bandera2 = 0;
					int w = 0;
					while(w < station.size() && bandera2 == 0){ //O(n^2)
						if(station.top() == a.top()){
							b.push(station.top());
							station.pop();
							a.pop();
						}
						else{
							bandera2 = 1;
						}
						
					}
				}

				
			}

			if(b.size() == tama){
				cout << "Yes" << endl;
			}
			else{
				cout << "No" << endl;
			}
			vaciarPila(a);
			vaciarPila(station);
			vaciarPila(b);
			temp.clear(); 
		}
		else{
			cout << endl;
			cin >> caso;
			vaciarPila(entrada);
		}
	}	
	return 0;
}