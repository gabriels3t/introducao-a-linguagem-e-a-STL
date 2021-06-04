#include <iostream>
using namespace std;
int main (){
    cout << "***************************************" << endl;
    cout << "* Boas vindas ao Jogo da Adivinhacaoo! *"<< endl;
    cout << "*************************************** "<< endl;
     
    const int NUMERO_SECRETO = 42;
    bool acertou_numero_secreto =false;
    int chute;
    int tentativas = 0;
    
    do{
        tentativas++;
        cout << "Tentativa numero : " << tentativas << endl;
        cout << "Qual seu chute ? " << endl;
        cin >>  chute;
        cout << "O chute foi : " << chute << endl;
        bool acertou = chute == NUMERO_SECRETO;
        bool chute_maior = chute > NUMERO_SECRETO;
        if(acertou){
            cout << "Parabens voce acertou !!"<< endl;
            acertou_numero_secreto = true;
        }else if(chute_maior){
            cout << "Seu chute foi maior que o numero secreto" << endl;
        }else{
            cout << "Seu chute foi menor que o numero secreto" << endl;
        }
    }while(!acertou_numero_secreto);
    cout << "O numero de tentativas foi : " << tentativas <<endl;
    cout << "Fim de jogo " << endl;
    
}