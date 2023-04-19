
#include "lista.h"
#include <iostream>


int main(){
	Lista l1;
	Lista l2;
	l1.anxLista(4);
	l1.anxLista(12);
	l1.anxLista(1);
	l1.anxLista(7);
	l2.anxLista(14);
	l2.anxLista(3);
	l2.anxLista(8);
	l2.anxLista(9);
	l2.anxLista(0);

	Lista l3 = l1 + l2;

	for(int i = 1; i <= l3.longLista(); i++){
		cout << l3.infoLista(i) << endl;
	}

	return 0;
}