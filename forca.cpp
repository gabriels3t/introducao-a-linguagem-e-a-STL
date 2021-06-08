#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;


string palavra_secreta;
map <char,bool> chutou; //Dicionario em c++
vector<char> chutes_errados;  // array que pode ser adicionado valores dinamicamente 

bool letra_existe(char chute){
    for(char letra : palavra_secreta){ // funciona apartir do c++ 11 
         if(chute == letra){
            return true;
        }
    }
    return false;
}

bool nao_acertou(){
    for(char letra:palavra_secreta){
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
    for(char letra : palavra_secreta){
        if (chutou[letra]){
            cout << letra << " ";
        }
        else{
            cout <<"_ ";
        }
    }
    cout << endl;
}

vector<string> le_arquivo(){
    ifstream arquivo; // para entrada de arquivos (ler)
    int quantidade_de_palavras;
    arquivo.open("palavras.txt");
    if(arquivo.is_open()){
        arquivo >> quantidade_de_palavras;
        
        vector<string> palavras_do_arquivo;
        for(int i=0; i < quantidade_de_palavras; i++){
            string palavra_lida;
            arquivo >> palavra_lida;
            palavras_do_arquivo.push_back(palavra_lida);
        }
        arquivo.close();
        return palavras_do_arquivo;
    }
    else{
        cout << "Nao foi possivel acessar o banco de palavras" << endl;
        exit(0);
    }
}
void sorteia_palavra(){
    vector<string> palavras = le_arquivo();
    srand(time(NULL));
    int indice_sorteado = rand()% palavras.size();
    palavra_secreta = palavras[indice_sorteado];

}
void salva_arquivos(vector<string>lista_palavras){
    ofstream arquivo;  // para saida de arquivos (escrever)
    arquivo.open("palavras.txt");
    if(arquivo.is_open()){
        arquivo << lista_palavras.size() << endl;
        for(string palavra : lista_palavras){
            arquivo << palavra << endl;
        }
        arquivo.close();
    }
    else{
        cout<<"Erro ao adicionar a palavra  " << endl;
        exit(0);
    }
}
string palavra_maiuscula(string palavra){
    string palavra_minuscula = palavra;
    string palavra_maiuscula;
    for(char letra : palavra){
        palavra_maiuscula += toupper(letra);
    }
    return palavra_maiuscula;
}
void adiciona_palavra(){
    cout << "Digite a nova palavra " << endl;
    string nova_palavra;
    cin >> nova_palavra;
    nova_palavra = palavra_maiuscula(nova_palavra);
    vector<string> lista_palavras = le_arquivo();
    lista_palavras.push_back(nova_palavra);
    salva_arquivos(lista_palavras);
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
    sorteia_palavra();
    imprime_cabecalho();
    while (nao_acertou() && nao_enforcou()){   
        imprime_erros();
        imprime_palavra();
        chuta();
        
    }
    cout << "FIM DE JOGO !!" << endl;
    if(!nao_acertou()){
        cout << "Parabens vc ganhou !!" << endl;
        cout << "Gostaria de adicionar uma nova palavra ? (S/N)" << endl;
        char resposta;
        cin >> resposta;
        resposta = toupper(resposta);
        if(resposta == 'S'){
            adiciona_palavra();
        }
    }else{
        cout << "Voce perdeu !! , tente novamente " << endl;
    }
    
    
}