/*

Benjamin Ortiz Morales

8978145

Realizacion del punto word

14/05/2023

*/

//La complejiadad de este programa es O(n^3) en el peor de los casos

#include <iostream>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

// O(n)
list<char> cadenaToList(string palabra){
    list<char> ans;
    for(int i = 0; i < palabra.size(); i++){
        ans.push_back(palabra[i]);
    }
    return ans;
}



int main(){
    list<string> diccionario;
    list<char> line;
    string palabra;
    int bandera;
    int contador = 0;
    while(cin >> palabra && palabra != "#") {
        diccionario.push_back(palabra);
    }
    string linea;
    cin.ignore();
    while(getline(cin, linea) && linea != "#"){
        for(int i = 0; i < linea.size(); i++){ //O(n)
            if(linea[i] != ' '){
                line.push_back(linea[i]);
            }
        }
        
        for(auto it = diccionario.begin(); it != diccionario.end(); it++){ //O(n)
            list<char> copyLine = line;
            list<char> listaPalabra = cadenaToList(*it); //O(n^2)
            int bandera2 = 0;
            auto st = copyLine.begin();
            while(bandera2 == 0 && st != copyLine.end()){ //O(n^2)
                bandera = 0;
                auto wt = listaPalabra.begin();
                while(wt != listaPalabra.end() && bandera == 0){ //O(n^3)
                    if(*st == *wt){
                        bandera = 1;
                    }
                    if(bandera == 1){
                        st = copyLine.erase(st);
                        wt = listaPalabra.erase(wt);
                    }
                    else{
                        wt++;
                    }
                    
                }

                if(listaPalabra.empty()){
                    bandera2 = 1;
                    contador += 1;
                }
                if(bandera == 0){
                    st++;
                }
                
            }
            
        }
        cout << contador << endl;
        line.clear();
        contador = 0;
    }
    return 0;
}