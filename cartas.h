#include "palpites.h"


typedef struct {
	string tipo; //arma, lugar ou personagem
	string nome; 
} CARTAS;

typedef struct {
	CARTAS arma;
	CARTAS lugar;
	CARTAS personagem;
} CONFIDENCIAL;

CARTAS criaCarta(string nome, string tipo){
	cout << "criando carta..." << endl;
	CARTAS carta;
	carta.nome = nome;
	carta.tipo = tipo;
	return carta;
}

vector<CARTAS> insereEmbaralhado(CARTAS c, vector<CARTAS> lista, int tamanho){ //funcao geral para criacao das listas embaralhadas iniciais
	//listas com comportamento de pilhas ap�s embaralh�-las
	cout << "entrou na funcao insereEmbaralhado" << endl;
	int tLista = lista.size();
	
	if(tLista < tamanho){ //nao esta totalmente preenchido
		cout << "vetor nao preenchido" << endl;
		vector<CARTAS> ::iterator it; //iterator para percorrer a lista
		int i, sorteado;
		srand(time(NULL));
		sorteado = (rand() % tamanho - 1); //sorteia entre 0 e 7 -- 8 armas
		do{
			it = lista.begin();
			for(i = 0; i < sorteado; i++){
				it++; //percorre enquanto it nao chega ao valor sorteado
			   	cout << "iterator de boa" << endl << endl;	
		   	}
		} while( it->nome != ""); //sorteia enquanto a posicao sorteada estah preenchida
		
	//	cout << "saiu do laco" << endl << endl;
		lista.insert(it, c); //esse it vai ser o index para colocar na lista jah sorteado
		
			
	}
	cout << "fim do insere" << endl;	
	return lista;
}

CONFIDENCIAL insereEnvelopeConf(vector<CARTAS> armas, vector<CARTAS> personagens, vector<CARTAS> lugares){
	CONFIDENCIAL envelope; //envelope confidencial
	vector<CARTAS>:: iterator it = armas.end();
	
	envelope.arma = *it; //ponteiro que aponta para o ultimo elemento de cada lista
	armas.pop_back(); //retira da  pilha
	
	it=lugares.end();
	envelope.lugar = *it;
	lugares.pop_back();
	
	it=personagens.end();
	envelope.personagem = *it;
	personagens.pop_back();

		return envelope;
}


vector<CARTAS> pilhaDeDistribuicao(vector<CARTAS> armas, vector<CARTAS> personagens, vector<CARTAS> lugares){
	vector<CARTAS> geral; //pilha geral para distribuicao dos jogadores
	for(int i =0; i< 8 ; i++){
		insereEmbaralhado(armas[i], geral, 24);
	}

	for(int i =0; i< 8 ; i++){
		insereEmbaralhado(personagens[i], geral, 24);
	}

	for(int i =0; i< 8 ; i++){
		insereEmbaralhado(lugares[i], geral, 24);
	}

	return geral;
}



