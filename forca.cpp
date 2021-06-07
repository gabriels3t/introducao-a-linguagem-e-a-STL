#include <iostream>
#include <string>
using namespace std;


const string PALAVRA_SECRETA = "MELANCIA";

bool letra_existe(char chute){
    for(char letra : PALAVRA_SECRETA){ // funciona apartir do c++ 11 
         if(chute == letra){
            return true;
        }
    }
    return false;
}

int main(){
    cout << PALAVRA_SECRETA << endl;
    bool nao_acertou=true;
    bool nao_enforcou = true;
    while (nao_acertou && nao_enforcou)
    {
        char chute;
        cin >> chute;
        if(letra_existe(toupper(chute))){
            cout << "Voce acertou, seu chute esta na palavra" << endl;
        }else{
            cout << "voce errou"<< endl;
        }
    }
    
}