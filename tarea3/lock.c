#include <stdio.h>

/*

Benjamin Ortiz Morales

8978145

*/

int main(){
	int n;
	int clave1;
	int clave2;
	int clave3;
	int contador;
	int i;
	int flag = 0;

	scanf("%d", &n);
	scanf("%d", &clave1);
	scanf("%d", &clave2);
	scanf("%d", &clave3);
	while (flag != 1){
		contador = 120;
		if(n < clave1){
			contador += (n - clave1) + 40;
		}
		else{
			contador += (n - clave1);
		}

		if(clave2 < clave1){
			contador += (clave2 - clave1) + 40;
		}
		else{
			contador += (clave2 - clave1);
		}
		if(clave2 < clave3){
			contador += (clave2 - clave3) + 40;
		}
		else{
			contador += (clave2 - clave3);
		}

		contador = contador * 9;
		printf("%d\n", contador);
		scanf("%d", &n);
		scanf("%d", &clave1);
		scanf("%d", &clave2);
		scanf("%d", &clave3);
		if(((n == 0) && (clave1 == 0)) && ((clave2 == 0) && (clave3 == 0))){
			flag = 1;
		}

	}
		
	return 0;
}