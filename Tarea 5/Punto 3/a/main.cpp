#include "lista.h"
#include <iostream>


// O(n)
void insertarEnListaOrdenada(Lista &l, int v){
	int tamano = l.longLista(); // O(n)
	bool bandera = 1;
	int i = 1;
	while(i < tamano && bandera == 1){ // O(n)
		int anterior = l.infoLista(i);  //O(k)
		int siguiente = l.infoLista(i + 1); // O(k)
		if(anterior <= v && siguiente > v){
			l.insLista(v, i + 1); //O(k)
			bandera = 0;
		}
		i++;
	}
}



int main(){
	Lista l;
	l.anxLista(1);
	l.anxLista(2);
	l.anxLista(3);
	l.anxLista(4);
	l.anxLista(5);
	l.anxLista(6);
	l.anxLista(7);
	int v = 6;

	insertarEnListaOrdenada(l, v);

	return 0;
}