/*

Benjamin Ortiz Morales

8978145

Realizacion del punto A keyboard

10/05/2023

*/

#include <iostream>
#include <string>
#include <deque>

using namespace std;

//La complejidad del programa es de O(n^2)

int main(){
	deque<char> ans;
	deque<char> temp;
	string cadena;
	int bandera;
	while(getline(cin, cadena)){
		bandera = 0;
		for(int i = 0; i < cadena.size(); i++){ //O(n)
			if(cadena[i] == '['){
				bandera = 1;
			}
			else if(cadena[i] == ']'){
				bandera = 0;
			}

			if(bandera == 1){
				if(cadena[i] != '[' && cadena[i] != ']'){
					temp.push_front(cadena[i]);
				}
				else if(cadena[i] == '[' || cadena[i] == ']'){
					for(int s = 0; s < temp.size(); s++){ //O(n^2)
						ans.push_front(temp[s]);
					}
					temp.clear();
				}
			}
			else{
				if(cadena[i] != '[' && cadena[i] != ']'){
					ans.push_back(cadena[i]);
				}
			}
		
		}
	if(!temp.empty()){
		for(int s = 0; s < temp.size(); s++){
			ans.push_front(temp[s]);
		}
		temp.clear();
	}

	for(int i = 0; i < ans.size(); i++){
		cout << ans[i]; 
	}
	cout << endl;
	ans.clear();
	}
	return 0;
}