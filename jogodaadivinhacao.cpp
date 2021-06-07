#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main (){
    char dificuldade;
    int numero_de_tentativas;
    srand(time(NULL));
    const int NUMERO_SECRETO =  (rand()%100);
    bool acertou_numero_secreto =false;
    int chute;
    int tentativas = 0;
    float pontos = 1000.0f;
    float pontos_perdidos = 0.0f;

    cout << "***************************************" << endl;
    cout << "* Boas vindas ao Jogo da Adivinhacaoo! *"<< endl;
    cout << "*************************************** "<< endl;
    cout << "Escolha a dificuldade : " << endl;
    cout << "Facil (F), Media (M), Dificil (D)" << endl;
    cin >> dificuldade;
    if(dificuldade == 'F' || dificuldade == 'f'){
        numero_de_tentativas =15;
    }else if(dificuldade == 'M' || dificuldade == 'm'){
        numero_de_tentativas =10;
    }else{
        numero_de_tentativas =5;
    }
    for(tentativas =1;tentativas <= numero_de_tentativas; tentativas++){
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
            break;
        }else if(chute_maior){
            cout << "Seu chute foi maior que o numero secreto" << endl;
        }else{
            cout << "Seu chute foi menor que o numero secreto" << endl;
        }
    }
    cout << "Fim de jogo " << endl;
    if(acertou_numero_secreto){
        cout << " Voce perdeu tente novamente "<<endl;
    }else{
        cout << "O numero de tentativas foi : " << tentativas <<endl;
        cout.precision(2); // Passando uma precissao de 2 casas
        cout << fixed; // deixando fixo para nao ficar em notação cientifica
        cout << "Sua pontuacao foi de : " << pontos << endl;

    }
    
}