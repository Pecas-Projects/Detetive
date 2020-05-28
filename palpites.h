#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <list>
#include <cstring>
#include <algorithm>
#include <fstream>

using namespace std;

typedef struct {
    string nome;
    string tipo;
    bool x;
    int cor;
}item;

void textcolor (int iColor){
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

 vector<item> criarlista (){
 	
 	vector<item> lista;
    
    lista[0].nome =  "Pelourinho";
    lista[0].tipo = "lugar";
    lista[0].x = false;
    lista[0].cor = 7;

    lista[1].nome =  "Farol da Barra";
    lista[1].tipo = "lugar";
    lista[1].x = false;
    lista[1].cor = 7;

    lista[2].nome =  "Senai";
    lista[2].tipo = "lugar";
    lista[2].x = false;
    lista[2].cor = 7;

    lista[3].nome =  "Rio Vermelho";
    lista[3].tipo = "lugar";
    lista[3].x = false;
    lista[3].cor = 7;

    lista[4].nome =  "Abrantes";
    lista[4].tipo = "lugar";
    lista[4].x = false;
    lista[4].cor = 7;

    lista[5].nome =  "Salvador Shopping";
    lista[5].tipo = "lugar";
    lista[5].x = false;
    lista[5].cor = 7;

    lista[6].nome =  "UFBA";
    lista[6].tipo = "lugar";
    lista[6].x = false;
    lista[6].cor = 7;

    lista[7].nome =  "Alphaville";
    lista[7].tipo = "lugar";
    lista[7].x = false;
    lista[0].cor = 7;

    lista[8].nome =  "Alagoinhas";
    lista[8].tipo = "lugar";
    lista[8].x = false;
    lista[8].cor = 7;

    lista[9].nome =  "Lapinha";
    lista[9].tipo = "Personagem";
    lista[9].x = false;
    lista[9].cor = 7;

    lista[10].nome =  "Mariazinha";
    lista[10].tipo = "Personagem";
    lista[10].x = false;
    lista[10].cor = 7;

    lista[11].nome =  "Veganinho";
    lista[11].tipo = "Personagem";
    lista[11].x = false;
    lista[11].cor = 7;

    lista[12].nome =  "Gr√ozinho";
    lista[12].tipo = "Personagem";
    lista[12].x = false;
    lista[12].cor = 7;

    lista[13].nome =  "Jo√ozinho";
    lista[13].tipo = "Personagem";
    lista[13].x = false;
    lista[13].cor = 7;

    lista[14].nome =  "Aninha";
    lista[14].tipo = "Personagem";
    lista[14].x = false;
    lista[14].cor = 7;
 
    lista[15].nome =  "Fernandinha";
    lista[15].tipo = "Personagem";
    lista[15].x = false;
    lista[15].cor = 7;

    lista[16].nome =  "Biazinha";
    lista[16].tipo = "Personagem";
    lista[16].x = false;
    lista[16].cor = 7;

    lista[17].nome =  "Chumbinho";
    lista[17].tipo = "Arma";
    lista[17].x = false;
    lista[17].cor = 7;

    lista[18].nome =  "Pe de cabra";
    lista[18].tipo = "Arma";
    lista[18].x = false;
    lista[18].cor = 7;

    lista[19].nome =  "Pedra";
    lista[19].tipo = "Arma";
    lista[19].x = false;
    lista[19].cor = 7;

    lista[20].nome =  "Fuzil";
    lista[20].tipo = "Arma";
    lista[20].x = false;
    lista[20].cor = 7;

    lista[21].nome =  "Canudo";
    lista[21].tipo = "Arma";
    lista[21].x = false;
    lista[21].cor = 7;

    lista[22].nome =  "Tesoura";
    lista[22].tipo = "Arma";
    lista[22].x = false;
    lista[22].cor = 7;

    lista[23].nome =  "Estilingue";
    lista[23].tipo = "Arma";
    lista[23].x = false;
    lista[23].cor = 7;

    lista[24].nome =  "Pa";
    lista[24].tipo = "Arma";
    lista[24].x = false;
    lista[24].cor = 7;
    
    return lista;  
 }

 void printarLista (vector<item>lista) {
 
    cout<<"********************"<<endl<<"Lugares:"<<endl;
    
    for(int i = 0; i<9; ++i){
        textcolor(lista[i].cor);
        cout<<lista[i].nome<<endl;
     }

    cout<<"********************"<<endl<<"Suspeitos:"<<endl;

    for(int i = 9; i<18; ++i){
        textcolor(lista[i].cor);
        cout<<lista[i].nome<<endl;
    }

    cout<<"********************"<<endl<<"Armas:"<<endl;

    for(int i = 18; i<25; ++i){
        textcolor(lista[i].cor);
        cout<<lista[i].nome<<endl;
    }


 }


 void manipularLista (vector<item> lista){

     string aux;
     int cont, n;

    while (true) {

    printarLista(lista);    
     
     cout<<"Se desejar marcar algum carta na sua lista, digite o seu nome, se n√o digite a letra N "<<endl;
     cin>>aux;

     if (aux == "N"){
        system("cls");
        break;
     }

    while (true) {

    for (int i = 0; i<25; ++i){
        if (aux != lista[i].nome) cont ++;
    } 

    if(cont == 24){
       
        cout<<"Essa carta n eh valida, digite outra:"<<endl;
        cin>>aux;
   
    } else break;
    
    }

    cout<<"Se voce deseja marcar esse item como 'Nao eh' digite 1, para marcar como 'talvez seja' digite 2 e para marcar como 'com certeza eh', digite 3"<<endl; 
    cin>>n;

    while (true){

        if (n != 1 && n != 2 && n !=3){
            cout<<"Esse numero nao eh valido, digite outro:"<<endl;
            cin>>n;
            if (n == 1 || n == 2 || n == 3) break;
        }
        

    }

     for (int i = 0; i<25; ++i){
         if (aux == lista[i].nome){
            if (n == 1){
                lista[i].cor = 4; //vermelho
            }
            if (n == 2){
                lista[i].cor == 6; //amarelo
            }
            if(n == 3){
                lista[i].cor == 2; //verde
            }
         } 
     }

    system("cls");
    printarLista(lista);
    cout<<"Se desejar maracar outra carta na sua lista, digite a letra S, se n digite a letra N";
    cin>>aux;

    if (aux == "N") break;

    }   

 }


 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
