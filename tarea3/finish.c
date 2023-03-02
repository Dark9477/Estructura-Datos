#include <stdio.h>

/*

Benjamin Ortiz Morales

8978145

*/

int main(){
	int caso;
	int itera;
	int i;
	int w;
	int s;
	int gas = 0;
	int mayor;
	int gaso = 0;
	int esta = 0;
	scanf("%d", &caso);
	for(i = 0; i < caso; i++){
		scanf("%d", &itera);
		int gasolina[itera];
		int estacion[itera];
		for(w = 0; w < itera; w++){
			scanf("%d", &gasolina[w]);
			gaso += gasolina[w];
			}
		for(w = 0; w < itera; w++){
			scanf("%d", &estacion[w]);
			esta += estacion[w];
			}

		if(gaso > esta){

			w = 0;
			int bandera = 0;
			int x = 0;
			int bandera2 = 0;
			int flag;
			while(x < itera  && bandera2 == 0){
				while(w < itera && bandera == 0){
					x = w;
					if(gasolina[w] > estacion[w]){
						mayor = w;
						gas = 0;
						s = w;
						flag = 0;
						while(s < itera && flag == 0){
							gas += (gasolina[s]);
							gas -= (estacion[s]);
							if(gas < 0){
								flag = 1;
								}
							s++;
							}
						if(gas > 0){   //revisar despues si es > o >=
							bandera = 1;
							}
						}
						w++;
					}


				if(bandera == 1){
					w = 0;
					while(w < mayor){
						gas += (gasolina[w]);
						gas -= (estacion[w]);
						w++;
						}
					}

				else{
					printf("Case %d: Not possible\n", i + 1);
					bandera2 = 2;		
					}


				if(gas > 0){
					bandera2 = 1;
				}	

				}

			if(bandera2 == 1){
				printf("Case %d: Possible from station %d\n", i + 1, mayor + 1);
				}

			}
		else{
			printf("Case %d: Not possible\n", i + 1);
			}
		gaso = 0;
		esta = 0;
		}
		

	return 0;
	}

