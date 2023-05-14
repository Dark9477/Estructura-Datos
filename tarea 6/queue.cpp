/*

Benjamin Ortiz Morales

8978145

Realizacion del punto queue

14/05/2023

*/


//El auto lo uso para no escribir deque<int>::iterator it

//En el mejor caso la complejidad es O(n) en el peor es O(n^2)

#include <iostream>
#include <deque>

using namespace std;


int main(){
	int pacientes;
	int acciones;
	deque<int> cola;
	deque<int> imprimir;
	int caso = 1;
	char accion;
	int movimiento;
	int bandera;
	int banderaTactica;

	cin >> pacientes;
	cin >> acciones;



	while(pacientes != 0 && acciones != 0){
		if(acciones > pacientes){
			for(int i = 1; i <= pacientes; i++){ //O(n)
				cola.push_back(i);
			}
			banderaTactica = 0;
		}
		else{
			for(int i = 1; i <= acciones; i++){ //O(n)
				cola.push_back(i);
			}
			banderaTactica = 1;
		}
		

		for(int i = 0; i < acciones; i++){ //O(n)
			cin >> accion;
			if(accion == 'N'){
				imprimir.push_back(cola.front());
				cola.push_back(cola.front());
				cola.pop_front();
			}
			else if(accion == 'E'){
				cin >> movimiento;
				bandera = 0;
				if(banderaTactica == 0){
					for(auto it = cola.begin(); it != cola.end() && bandera == 0; it++){ //O(n^2)
						if(*it == movimiento){
							cola.push_front(*it);
							cola.erase(it);
							bandera = 1;
						}
					}
				}
				else{
					cola.push_front(movimiento);
				}
			}
		}
	
		cout << "Case " << caso << ":" << endl;
		for(auto it = imprimir.begin(); it != imprimir.end(); it++){
			cout << *it << endl;
		}
		cola.clear();
		imprimir.clear();


		cin >> pacientes;
		cin >> acciones;
		caso += 1;
	}
	return 0;
}