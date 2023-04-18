#include <vector> // para poder usar los vectores
#include <iostream> //
#include <string> // para usar strings
#include <iomanip> // libreria para imprimir con formato una string(no me dejaba imprimir el string con printf por eso use esto)
#include <cmath> // para poder analizar en nan que me da al dividir 0 / 0 y convertirlo en N/A
#include <cstring> // para poder usar el strcmp
#include <algorithm> // 

using namespace std;

bool comparaIgnorandoMayusculas(string s1, string s2) {
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    return s1 < s2;
}

void ordenaImprimir(vector<string> equipos,vector<int> puntos,vector<int> juegosJugados,vector<int> golesMetidos,vector<int> golesEnContra,
vector<int> diferenciaGoles, vector<float> porcentajePuntos){

	vector<string> equipos_copia = equipos;
	for(int i = 0; i < diferenciaGoles.size(); i++){
		diferenciaGoles[i] = (golesMetidos[i] - golesEnContra[i]);
	}

	vector<string> w(puntos.size());
	for (int i = 0; i < puntos.size(); i++) {
		int min = i;
		for (int j = i + 1; j < puntos.size(); j++) {
			if (puntos[j] > puntos[min]){
				min = j;
			}
			else if(puntos[j] == puntos[min]){
				if(porcentajePuntos[j] > porcentajePuntos[min]){
					min = j;
				}
				else if(porcentajePuntos[j] == porcentajePuntos[min]){
					if(golesMetidos[j] > golesMetidos[min]){
						min = j;
					}
					else if(golesMetidos[j] == golesMetidos[min]){
						if(juegosJugados[j] > juegosJugados[min]){
							min = j;
						}
						else if(juegosJugados[j] == juegosJugados[min]){						
							if(diferenciaGoles[j] > diferenciaGoles[min]){
								min = j;
							}
							else if(diferenciaGoles[j] == diferenciaGoles[min]){
								if(golesEnContra[j] > golesEnContra[i]){
									min = j;
								}
								else if(golesEnContra[j] == golesEnContra[min]){
									if (comparaIgnorandoMayusculas(equipos_copia[j], equipos_copia[min])){
					                    min = j;
					                }
					            }
				            }
			            } 
		            }
	            }	
			}
		}
	    
        w[i] = puntos[min];
        swap(equipos[i], equipos[min]); 
        swap(puntos[i], puntos[min]); 
        swap(juegosJugados[i], juegosJugados[min]); // el swap sirve para cambiar dos elementos de posicion de un vector 
        swap(golesMetidos[i], golesMetidos[min]);
        swap(golesEnContra[i], golesEnContra[min]);
        swap(diferenciaGoles[i], diferenciaGoles[min]);
        swap(porcentajePuntos[i], porcentajePuntos[min]);
    }
	for(int i = 0; i < equipos.size(); i++){		
        cout << setw(2) << i+1 << ". ";
		cout << setw(15) << equipos[i];
		cout << setw(4) << puntos[i];
		cout << setw(4) << juegosJugados[i];
		cout << setw(4) << golesMetidos[i];
		cout << setw(4) << golesEnContra[i];
		cout << setw(4) << diferenciaGoles[i];
		porcentajePuntos[i] = (float)puntos[i] / (float)(juegosJugados[i] * 3) * 100;
		if(isnan(porcentajePuntos[i])){
			cout << setw(7) << "N/A" << endl;

		}
		else{
			cout << fixed << setprecision(2) << setw(7) << porcentajePuntos[i] << endl;
		}
	}
	cout << endl;

}



int main(){
	int numeroEquipos;
	int numeroPartidos;

	cin >> numeroEquipos;
	cin >> numeroPartidos;

	while(numeroEquipos != 0 || numeroPartidos != 0){
		string equip;
		string nombreEquipo;
		vector<string> equipos;
		vector<int> puntos;
		vector<int> juegosJugados;
		vector<int> golesMetidos;
		vector<int> golesEnContra;
		vector<int> diferenciaGoles;
		vector<float> porcentajePuntos;

		for(int i = 0; i < numeroEquipos; i++){
			cin >> equip;
			equipos.push_back(equip);
			puntos.push_back(0);
			juegosJugados.push_back(0);
			golesMetidos.push_back(0);
			golesEnContra.push_back(0);
			diferenciaGoles.push_back(0);
			porcentajePuntos.push_back(0.00);
			
		}
		string partido;
		vector<string> partidos;
		cin.ignore();
		for(int i = 1; i < numeroPartidos + 1; i++){
			getline(cin, partido);
			partidos.push_back(partido);
		}

		for(int i = 0; i < partidos.size(); i++){
			string equipo1 = "";
			string equipo2 = "";
			string goles1 = "";
			string goles2 = "";
			bool bandera = true;
			bool bandera2 = false;
			for(int s = 0; s < partidos[i].length(); s++){
				if(bandera){
					if(partidos[i][s] != ' ' && bandera){
						equipo1 += partidos[i][s];
					}
					if(partidos[i][s] == ' '){
						bandera = false;
						goles1 = partidos[i][s + 1];
						goles2 = partidos[i][s + 5];
					}
				}
				if(partidos[i][s] == '-'){
					if(partidos[i][s + 1] == ' '){
						bandera2 = true;
					}
				}
				if(bandera2 && (s + 4) < partidos[i].length()){
					equipo2 += partidos[i][s + 4];
				}	
			}

			int eq1;
			int eq2;
			

			for(int w = 0; w < equipos.size(); w++){
				if(equipos[w] == equipo1){
					eq1 = w;
				}
				if(equipos[w] == equipo2){
					eq2 = w;
				}
			}
			
			if(stoi(goles1) > stoi(goles2)){
				puntos[eq1] += (3);
				juegosJugados[eq1] += 1;
				juegosJugados[eq2] += 1;
				golesMetidos[eq1] += stoi(goles1);
				golesMetidos[eq2] += stoi(goles2);
				golesEnContra[eq1] += stoi(goles2);
				golesEnContra[eq2] += stoi(goles1);
				
			}
			else if(stoi(goles2) > stoi(goles1)){
				puntos[eq2] += (3);
				juegosJugados[eq1] += 1;
				juegosJugados[eq2] += 1;
				golesMetidos[eq2] += stoi(goles2);
				golesMetidos[eq1] += stoi(goles1);
				golesEnContra[eq2] += stoi(goles1);
				golesEnContra[eq1] += stoi(goles2);
				
			}
			else{
				puntos[eq1] += (1);
				puntos[eq2] += (1);
				juegosJugados[eq1] += 1;
				juegosJugados[eq2] += 1;
				golesMetidos[eq2] += stoi(goles2);
				golesEnContra[eq2] += stoi(goles1);
				golesMetidos[eq1] += stoi(goles1);
				golesEnContra[eq1] += stoi(goles2);
				
			}				
		}


		ordenaImprimir(equipos,puntos,juegosJugados,golesMetidos,golesEnContra,diferenciaGoles,porcentajePuntos);

		
		cin >> numeroEquipos;
		cin >> numeroPartidos;
	}

	return 0;
}

