#include "lista.h"
#include <iostream>

int contarOcurrencias(Lista &l, int v){
	int ans = 0;
	for(int i = 1; i <= l.longLista(); i++){
		if(v == l.infoLista(i)){
			ans += 1;
		}
	}
	return ans;
}

Lista obtenerMenores(Lista &l, int v){
	Lista ans;
	for(int i = 1; i <= l.longLista(); i++){
		int temp = l.infoLista(i);
		if(temp < v){
			ans.anxLista(temp);
		}
	}
	return ans;
}


int main(){
	Lista l1;
	l1.anxLista(4);
	l1.anxLista(12);
	l1.anxLista(1);
	l1.anxLista(7);
	l1.anxLista(14);
	l1.anxLista(3);
	l1.anxLista(8);
	l1.anxLista(9);

	int v = 10;

	int ocurrencias = contarOcurrencias(l1, v);

	Lista menores = obtenerMenores(l1, v);

	return 0;
}