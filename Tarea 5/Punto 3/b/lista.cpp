#include "lista.h"

Lista::Lista(){
  act = NULL;
}



void Lista::insListaOrdenada(Elemento v){
    Nodo* nuevo = new Nodo;
    nuevo->dato = v;
    nuevo->sig = NULL;
  
    if(act == NULL){
        act = nuevo;
    } 
    else if(v < act->dato){
        nuevo->sig = act;
        act = nuevo;
    } 
    else{
        Nodo* tmp = act->sig;
        Nodo* ant = act;
        while(tmp != NULL && v > tmp->dato){
            ant = tmp;
            tmp = tmp->sig;
        }
        nuevo->sig = tmp;
        ant->sig = nuevo;
    }
}




void Lista::elimLista(int pos){
  Nodo *tmp, *elim;
  if(pos >= 1 && pos <= longLista()){
    if(pos == 1)
      act = act->sig;
    else{
      tmp = act;
      for(int i = 0; i < pos-2; i++)
	tmp = tmp->sig;
      elim = tmp->sig;
      tmp->sig = tmp->sig->sig;
      delete elim;
    }
  }
}

Elemento Lista::infoLista(int pos){
  Nodo* tmp = act;

  for(int i = 1; i < pos; i++)
    tmp = tmp->sig;

  return tmp->dato;
}

int Lista::longLista(){
  Nodo* tmp = act;
  int cont = 0;

  while(tmp != NULL){
    tmp = tmp->sig;
    cont++;
  }

  return cont;
}

bool Lista::vaciaLista(){
  return act == NULL;
}
