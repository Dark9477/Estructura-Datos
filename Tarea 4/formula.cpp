#include <iostream>
#include <vector>
using namespace std;

int main() {
    int gP;
    int pil;
    int casos;

    scanf("%d %d", &gP, &pil);

    while (gP != 0 && pil != 0){
        int pilots[500][100];
        for (int i = 0; i < gP; i++){
            for (int s = 0; s < pil; s++){
                scanf("%d", &pilots[s][i]);
            }
        }
        scanf("%d", &casos);
        for (int w = 0; w < casos; w++){
            int firstNum;
            scanf("%d", &firstNum);
            int puntuacion[firstNum];
            for (int a = 0; a < firstNum; a++){
                scanf("%d", &puntuacion[a]);
            }

            vector<int> arreglo(pil, 0);
            int mayor = 0;
            for (int i = 0; i < pil; i++){
                for (int j = 0; j < gP; j++){
                    int aux = pilots[i][j] - 1;
                    if (firstNum > aux) {
                        arreglo[i] += puntuacion[aux];
                        if (mayor < arreglo[i]){
                            mayor = arreglo[i];
                        }
                    }
                }
            }
            int Numero = 0;
            for (int ayuda = 0; ayuda < pil; ayuda++){
                if (arreglo[ayuda] == mayor){
                    if (Numero != 0) {
                        cout << " " << (ayuda + 1);
                    } else {
                        cout << (ayuda + 1);
                        Numero = 1;
                    }
                }
            }
            cout << endl;
        }
        scanf("%d %d", &gP, &pil);
    }

    return 0;
}

