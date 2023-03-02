#include <stdio.h>

/*

Benjamin Ortiz Morales

8978145

*/

int main(){
	int caso;
	int n;
	int i;
	int j;
	int arreglo[100];
	int mayorSt;
	int menorSt;
	int res;

	scanf("%d", &caso);

	for(i = 0; i < caso; i++){
		scanf("%d", &n);
		for(j = 0; j < n; j++){
			scanf("%d", &arreglo[i]);
			if(j == 0){
            	mayorSt = arreglo[i];
            	menorSt = arreglo[i];
        		}
        	if(menorSt > arreglo[i]){
            	menorSt = arreglo[i];
        		}
        	if(mayorSt < arreglo[i]){
            	mayorSt = arreglo[i];
        		}
			}
			res = (mayorSt - menorSt) * 2;
		printf("%d\n", res);
		}
	return 0;
}