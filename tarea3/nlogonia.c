#include <stdio.h>

/*

Benjamin Ortiz Morales

8978145

*/

int main(){
	int casos;
	int i;
	int n;
	int m;
	int x;
	int y;
	scanf("%d", &casos);

	while(casos != 0){
		scanf("%d", &n);
		scanf("%d", &m);
		for(i = 0; i < casos; i++){
			scanf("%d", &x);
			scanf("%d", &y);
			if(x == n || y == m){
				printf("divisa\n");
			}
			else if(x > n && y > m){
				printf("NE\n");
			}
			else if(x < n && y > m){
				printf("NO\n");
			}
			else if(x < n && y < m){
				printf("SO\n");
			}
			else{
				printf("SE\n");
			}
		}
		scanf("%d", &casos);
	}
	return 0;
}