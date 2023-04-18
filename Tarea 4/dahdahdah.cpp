#include <iostream>
#include <string>
#include <vector>


using namespace std;


int main(){


    vector<char> letras = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', ',', '?', '\'',
    '!', '/', '(', ')', '&', ':', ';', '=', '+', '-', '_', '\"','@'};

    vector<string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---",
    "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-",
    "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...",
    "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.",".--.-."};

    int itera;

    cin >> itera;
    cin.ignore();

    for(int i = 1; i < itera + 1; i++){
        string palabra;
        getline(cin,palabra);

        cout << "Message #" << i << endl;

        string letra = "";
        
        for(int s = 0; s < palabra.size(); s++){
            if(palabra[s] == ' '){
                int j = 0;
                int flag = 0;
        
                if(letra != ""){
                    while(j < morse.size() && flag == 0){
                        if(morse[j] == letra){
                            cout << letras[j];
                            flag = 1;
                        }
                        j++;
                    }
                }
                
                if (s < palabra.size() - 1 && palabra[s + 1] == ' '){
                    cout << " ";
                    s++;
                }
                letra = "";
            }
            else{
                letra += palabra[s];
            }
        }

        int j = 0;
        int flag = 0;
        while(j < morse.size() && flag == 0){
            if(morse[j] == letra){
                cout << letras[j];
                flag = 1;
            }
            j++;
        }

        cout << endl << endl;
    }
    return 0;
}