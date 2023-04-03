#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main() {
    int num_casos, num_juegos, intento, num1, num2;
    scanf("%d", &num_casos);

    vector<vector<char>> posibles_soluciones(10000, vector<char>(4));

    for (int i = 0; i <= 9999; i++) {
        int n = i;
        for (int j = 3; j >= 0; j--) {
            posibles_soluciones[i][j] = (n % 10) + '0';
            n /= 10;
        }
    }

    while (num_casos--) {
        scanf("%d", &num_juegos);
        vector<vector<char>> juegos(num_juegos, vector<char>(4));
        vector<int> respuestas_a(num_juegos), respuestas_b(num_juegos);
        for (int i = 0; i < num_juegos; i++) {
            scanf("%s %d/%d", &juegos[i][0], &respuestas_a[i], &respuestas_b[i]);
        }
        int contador = 0, respuesta;
        vector<char> intento_actual(4);
        for (int i = 0; i <= 9999 && contador < 2; i++) {
            for (int j = 0; j < 4; j++) {
                intento_actual[j] = posibles_soluciones[i][j];
            }
            bool solucion_valida = true;
            for (int j = 0; j < num_juegos; j++) {
                vector<int> num(10, 0);
                int a = 0, b = 0;
                for (int k = 0; k < 4; k++) {
                    num[juegos[j][k] - '0']++;
                }
                for (int k = 0; k < 4; k++) {
                    if (num[intento_actual[k] - '0'] > 0) {
                        b++;
                        num[intento_actual[k] - '0']--;
                    }
                }
                for (int k = 0; k < 4; k++) {
                    if (intento_actual[k] == juegos[j][k]) {
                        a++;
                        b--;
                    }
                }
                if (respuestas_a[j] != a || respuestas_b[j] != b) {
                    solucion_valida = false;
                }
            }
            if (solucion_valida) {
                contador++;
                respuesta = i;
            }
        }
        if (contador == 1) {
            printf("%04d\n", respuesta);
        }
        else if (contador == 0) {
            printf("impossible \n");
        }
        else {
            printf("indeterminate \n");
        }
    }
    return 0;
}
