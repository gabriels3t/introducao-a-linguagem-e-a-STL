#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;


const string PALAVRA_SECRETA = "MELANCIA";
map <char,bool> chutou; //Dicionario em c++
vector<char> chutes_errados;  // array que pode ser adicionado valores dinamicamente 

bool letra_existe(char chute){
    for(char letra : PALAVRA_SECRETA){ // funciona apartir do c++ 11 
         if(chute == letra){
            return true;
        }
    }
    return false;
}

bool nao_acertou(){
    for(char letra:PALAVRA_SECRETA){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;

}

bool nao_enforcou(){
    return chutes_errados.size() < 5;
}

void imprime_cabecalho(){
    cout << "*********************" << endl;
    cout << "*** Jogo da Forca ***" << endl;
    cout << "*********************" << endl;
    cout << endl;
}

void imprime_erros(){
    cout << "Chutes errados: ";
    for(char letra: chutes_errados){
        cout << letra << " ";
    }
    cout << endl;
}

void imprime_palavra(){
    for(char letra : PALAVRA_SECRETA){
        if (chutou[letra]){
            cout << letra << " ";
        }
        else{
            cout <<"_ ";
        }
    }
    cout << endl;
}

void chuta(){
    char chute;
    cout << "Seu Chute : ";
    cin >> chute;
    chute = toupper(chute);
    chutou[chute] = true;
    if(letra_existe(chute)){
        cout << "Voce acertou, seu chute esta na palavra" << endl;
    }
    else{
        cout << "voce errou"<< endl;
        chutes_errados.push_back(chute); // colocando valor no final do array

    }
    cout << endl;
}
int main(){
    imprime_cabecalho();
    while (nao_acertou() && nao_enforcou()){   
        imprime_erros();
        imprime_palavra();
        chuta();
        
    }
    cout << "FIM DE JOGO !!" << endl;
    if(!nao_acertou()){
        cout << "Parabens vc ganhou !!" << endl;
    }else{
        cout << "Voce perdeu !! , tente novamente " << endl;
    }
    
    
}