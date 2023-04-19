#include "lista.h"
#include <iostream>

//O(n^2)
void concatenarListas(Lista &l1, Lista &l2){
	for(int i = 1; i <= l2.longLista(); i++){ //O(n)
		l1.anxLista(l2.infoLista(i)); // n*n = O(n^2)
	}
}



int main(){

	Lista l1;
	Lista l2;

	l1.anxLista(1);
	l1.anxLista(2);
	l1.anxLista(3);

	l2.anxLista(4);
	l2.anxLista(5);
	l2.anxLista(6);

	concatenarListas(l1, l2);

	return 0;
}