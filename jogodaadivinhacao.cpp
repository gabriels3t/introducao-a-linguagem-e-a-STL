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
    float pontos = 1000.0f;
    float pontos_perdidos = 0.0f;
    do{
        tentativas++;
        cout << "Tentativa numero : " << tentativas << endl;
        cout << "Qual seu chute ? " << endl;
        cin >>  chute;
        pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos -= pontos_perdidos;
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
    cout << "Fim de jogo " << endl;
    cout << "O numero de tentativas foi : " << tentativas <<endl;
    cout.precision(2); // Passando uma precissao de 2 casas
    cout << fixed; // deixando fixo para nao ficar em notação cientifica
    cout << "Sua pontuacao foi de : " << pontos << endl;
    
}