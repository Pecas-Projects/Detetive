
#include "jogador.h"

using namespace std;

void desenharMapa(){
	char matriz[21][49] ={{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' ',220,220,220,220,220,220,220,' ',' ',' ',220,220,220,220,220,220,220,' ',' ',' ',220,220,220,220,220,220,220,' ',' ',' ',220,220,220,220,220,220,220,' ',' ',' ',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' ',219,'F','A','R','O','L',219,207,207,207,219,'R','I','O',' ',' ',219,207,207,207,219,'P','E','L','O','U',219,207,207,207,219,'U','F','B','A',' ',219,' ',' ',' ',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' ',219,' ',' ',' ',' ',' ',219,207,207,207,219,'V','E','R','M','.',219,207,207,207,219,'R','I','N','H','O',219,207,207,207,219,' ',' ',' ',' ',' ',219,' ',' ',' ',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' ',223,223,223,223,223,223,223,' ',' ',' ',223,223,223,223,223,223,223,' ',207,' ',223,223,223,223,223,223,223,' ',' ',' ',223,223,223,223,223,223,223,' ',' ',' ',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' ',' ',' ',' ',207,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',207,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',207,' ',' ',' ',' ',' ',' ',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' ',' ',' ',' ',207,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',207,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',207,' ',' ',' ',' ',' ',' ',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' ',' ',' ',' ',207,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',220,220,220,220,220,220,220,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',207,' ',' ',' ',' ',' ',' ',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' ',' ',' ',' ',207,207,207,207,207,207,207,207,207,207,207,207,219,'S','E','N','A','I',219,207,207,207,207,207,207,207,207,207,207,207,207,' ',' ',' ',' ',' ',' ',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' ',' ',' ',' ',207,207,207,207,207,207,207,207,207,207,207,207,219,' ',' ',' ',' ',' ',219,207,207,207,207,207,207,207,207,207,207,207,207,' ',' ',' ',' ',' ',' ',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' ',' ',' ',' ',207,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',223,223,223,223,223,223,223,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',207,' ',' ',' ',' ',' ',' ',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' ',' ',' ',' ',207,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',207,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',207,' ',' ',' ',' ',' ',' ',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' ',' ',' ',' ',207,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',207,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',207,' ',' ',' ',' ',' ',' ',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' ',' ',' ',' ',207,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',207,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',207,' ',' ',' ',' ',' ',' ',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' ',220,220,220,220,220,220,220,' ',' ',' ',220,220,220,220,220,220,220,' ',207,' ',220,220,220,220,220,220,220,' ',' ',' ',220,220,220,220,220,220,220,' ',' ',' ',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' ',219,'A','L','A','G','O',219,207,207,207,219,'A','B','R','A','N',219,207,207,207,219,'A','L','P','H','A',219,207,207,207,219,'S','S','A',' ',' ',219,' ',' ',' ',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' ',219,'I','N','H','A','S',219,207,207,207,219,'T','E','S',' ',' ',219,207,207,207,219,'V','I','L','L','E',219,207,207,207,219,'S','H','O','P','P',219,' ',' ',' ',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' ',223,223,223,223,223,223,223,' ',' ',' ',223,223,223,223,223,223,223,' ',' ',' ',223,223,223,223,223,223,223,' ',' ',' ',223,223,223,223,223,223,223,' ',' ',' ',' ',' ',' '},
                          {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
                          

 for (int i=0;i<21;++i){
	for (int j=0;j<49;j++)
	   cout<<matriz[i][j];
	
	cout<<"\n";
   }
}

void movimentar(JOGADOR *user){

/*COLOCAR ISSO EM UMA FUNCAO DE "COMECANDO O JOGO"

				INICIO								*/
	typedef struct{
		string nome;
		string* prox;
		string* ant;
	}LUGARES;

	LUGARES dados[8];
	vector<string> vetorLugares;
	string *p;

	vetorLugares[0] = "Farol da Barra";
	vetorLugares[1] = "Alagoinhas";
	vetorLugares[2] = "Abrantes";
	vetorLugares[3] = "Alphaville";
	vetorLugares[4] = "SSA Shopping";
	vetorLugares[5] = "UFBA";
	vetorLugares[6] = "Pelourinho";
	vetorLugares[7] = "Rio Vermelho";
	
	for(int i = 0; i < vetorLugares.size(); i++){
		dados[i].nome= vetorLugares[i];

		if(i == 0){
			*p = vetorLugares[7];
			*dados[i].ant = *p;
		}else if(i == 7){
			*p = vetorLugares[0];
			*dados[i].prox = *p;
		}else{
			*p = vetorLugares[i-1];
			*dados[i].ant = *p;
			*p = vetorLugares[i+1];
			*dados[i].prox = *p;
		} 
	}

	int numUser;

	cout<<"Local atual: "<<user->lugar<<endl;
	cout<<"Digite o numero correspondente para ir ate o lugar."<<endl;

	for(int i =0; i< 8 ; i++){
		if(user->lugar == dados[i].nome){
			cout<<"Voce pode ir para: \n[0] SENAI"<<endl;
			cout<<"[1] "<<*dados[i].ant<<endl;
			cout<<"[2] "<<*dados[i].prox<<endl;
			cout<<"Com o custo de 5 pontos de energia\n"<<endl;
			cout<<"[3] "<<*dados[i+1].prox<<endl;
			cout<<"[4] "<<*dados[i-1].ant<<endl;
			cout<<"Com o custo de 7 pontos de energia\n"<<endl;
			cout<<"Lembre-se voce possui "<<user->energia<<" pontos de energia!"<<endl;
		}

		while (true){
	   		cin>>numUser;
				if(numUser > 7 || numUser < 0){
					cout<<"Indice invalido!"<<endl;
					cout<<"Digite o numero correspondente para ir ate o lugar."<<endl;
				}
				else{
					break;
				}	
		}

		if(numUser == 1 || numUser == 2 || numUser == 0){
			if(user->energia < 5){
				cout<<"Voce nao possui energia suficiente!"<<endl;
			}else if(numUser == 1){
	  			user->lugar = *dados[i].ant;
			   	user->energia -=5;
			   	cout<<"Seu lugar atual foi atualizado: "<<user->lugar<<endl;
				cout<<"Agora voce possui "<<user->energia<<endl;
			}else if(numUser == 0){
				user->lugar = *dados[i].prox;
				user->energia -=5;
				cout<<"Seu lugar atual foi atualizado: "<<user->lugar<<endl;
				cout<<"Agora voce possui "<<user->energia<<endl;
			}else{
				user->lugar = "SENAI";
				user->energia -=5;
				cout<<"Seu lugar atual foi atualizado: "<<user->lugar<<endl;
				cout<<"Agora voce possui "<<user->energia<<endl;
			}
		
		}else if(numUser == 2 || numUser == 3){
			if(user->energia < 7){
				cout<<"Voce nao possui energia suficiente!"<<endl;
			}
		
		}else if(numUser == 3){
			user->lugar = *dados[i+1].prox;
			user->energia -=7;
			cout<<"Seu lugar atual foi atualizado: "<<user->lugar<<endl;
			cout<<"Agora voce possui "<<user->energia<<endl;
		}else if(numUser == 4){
			user->lugar = *dados[i-1].ant;
			user->energia -=7;
			cout<<"Seu lugar atual foi atualizado: "<<user->lugar<<endl;
			cout<<"Agora voce possui "<<user->energia<<endl;
		
		}else{
			if(user->energia < 5){
				cout<<"Voce nao possui energia suficiente!"<<endl;
			}else{
				cout<<"Voce pode ir para: "<<endl;
				for(int i =0; i< vetorLugares.size(); i++){
				   	cout<<"["<<i<<"] "<<vetorLugares[i]<<endl;
				}
			
				while (true){
			   	   	cin>>numUser;
					if(numUser > 7 || numUser < 0){
						cout<<"Indice invalido!"<<endl;
						cout<<"Digite o numero correspondente para ir ate o lugar."<<endl;
					}else{
						break;
		 		    }
				}
			
				if(numUser > 7 || numUser < 0){
					cout<<"Numero invalido!"<<endl;
				}else{
					user->lugar = vetorLugares[numUser];
			 		user->energia -=5;
					cout<<"Seu lugar atual foi atualizado: "<<user->lugar<<endl;
					cout<<"Agora voce possui "<<user->energia<<endl;
				}
			}
		}

	
    }
}	
