#include<stdio.h>
#include<math.h>

/*

Benjamin Ortiz Morales

8978145

*/

int main(){
    int n,i,flag,num,arreglo1[3000],arreglo2[3000],arreglo3[3000],j;
    while(scanf("%d",&n)!=EOF){
        for(i = 0; i < n; i++){
            scanf("%d", &arreglo1[i]);
        }
        for(i = 0; i < n-1; i++){
            arreglo2[i]= abs(arreglo1[i] - arreglo1[i+1]);
        }
        num = 1;
        for(i = 0; i < n-1; i++){
            arreglo3[i] = num;
            num++;
        }
        flag = 0;
        i = 0;
        while(i < n-1 && flag != 2){
            for(j = 0; j < n-1; j++){
                if(arreglo3[i] == arreglo2[j]){
                       flag =1 ;
                }
            }
            if(flag == 1){
                flag = 0;
            }
            else{
                flag = 2;
            }
            i++;
        }
        if(flag == 2){
            printf("Not jolly\n");
        }
        else{
            printf("Jolly\n");
        }
    }
    return 0;
}