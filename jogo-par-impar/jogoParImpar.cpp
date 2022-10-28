#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int j=0;
int c=0;

void score();
int par_impar();
int player();
int numero_computador();
int jogada(int parimpar, int play, int pc);

int par_impar(){
    int num;
    cout<< "Escolha par ou impar:\n";
    cout<< "0. Par\n";
    cout<< "1. Impar\n";
    cin>> num;
    if(num==0){
        cout<<"Par foi o escolhido!\n";
    }
    else if(num==1){
        cout<<"Impar foi o escolhido!\n";
    }
    return num;
}

int player (){
    int num;
    cout<< "Escolha um numero inteiro para sua jogada:"<<endl;
    cin>> num;
    cout<< "\n";
    return num;
}

int numero_computador(){
    unsigned seed = time (0);
    srand(seed);
    return rand()%11;
}

int jogada(int parimpar, int nplayer, int ncomputador){
    cout<< "=======================\n";
    cout<< "     HORA DO JOGO!     \n";
    cout<< "=======================\n";
    cout<< "Escolha do usuario: "<<nplayer<<endl;
    cout<< "Escolha da Maquina: "<<ncomputador<<endl;
    cout<< "Resultado da jogada:\n";
    cout<< nplayer << "+" << ncomputador <<"="<<nplayer+ncomputador<<endl;

    if((nplayer+ncomputador)%2==0){
        cout<< "\nPAR!!\n";
    }
    else{
        cout<< "\nIMPAR!!\n";
    }
    
    if((nplayer+ncomputador)%2 == parimpar){
        cout<< "\nPARABENS! Voce venceu a rodada!"<<endl;
        j++;
        return j;
    }
    else{
        cout<< "\nQue pena... A maquina venceu a rodada!"<<endl;
        c++;
        return c;
    }

}

void score(){
    cout<<" "<<endl;
    cout<<"================"<<endl;
    cout<<"     PLACAR     "<<endl;
    cout<<"================"<<endl;
    cout <<"Jogador: "<<j<<"\t Maquina: "<<c<<endl;
}

int main (){
    char continuar;
    int parimpar, nplayer, ncomputador;

    do{
        parimpar = par_impar();
        nplayer = player();
        ncomputador = numero_computador();
        jogada(parimpar, nplayer, ncomputador);

        score();
        cout<<"Deseja jogar novamente?"<<endl;
        cout<<"[S/N]"<<endl;
        cin>> continuar;
        continuar= toupper(continuar);
         
    }
    while (continuar== 'S');
        return 0;
        
}