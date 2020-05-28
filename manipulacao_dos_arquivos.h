#include "MapaDet.h"


vector<JOGADOR> Ranking; //lista dos rankings
vector<JOGADOR>::iterator it; //percorrera essa lista
fstream arquivo; //arquivo de leitura e escrita

bool MenorTempo(const JOGADOR &a, const JOGADOR &b){
	return a.tempo < b.tempo;
}

void insereOrdenado(JOGADOR player){
	Ranking.push_back(player);
	sort( Ranking.begin(), Ranking.end(), MenorTempo);	
}

JOGADOR* vetorRanking(){ //retorna o vetor do ranking dos jogadores
	int tam = Ranking.size();
	JOGADOR *rankings = new JOGADOR[tam]; //alocando o tamanho do vetor
	for(int i = 0; i < tam && it != Ranking.end(); i++){
		rankings[i] = *it;
		it++;
	}
	return rankings;
}

vector<JOGADOR> RankingOrdenado(JOGADOR rankings[], int tam){
	for(int i = 0; i < tam; i++){
		Ranking.push_back(rankings[i]);
	}
	sort(Ranking.begin(), Ranking.end(), MenorTempo);
	return Ranking;
}

void criarSizeFile(JOGADOR rankings[], int tam){ //arquivo com o tamanho do vetor
	arquivo.open("sizeVetor.bin", ios::binary | ios::out);
	arquivo.write((char*)&tam, sizeof(int));
	arquivo.close();
}

int TamVetor(){
	int tam;
	arquivo.open("sizeVetor.bin", ios::binary | ios::in);
	arquivo.read((char*)&tam, sizeof(int));
	arquivo.close();
	return tam;
}

void criar_Arquivo_Ranking(int tam, JOGADOR rankings[]){ //rankings
	arquivo.open("ranking.bin", ios::binary);
	arquivo.write((char*)(&rankings), sizeof(JOGADOR)*tam);	
	arquivo.close();
}

JOGADOR* vetorArq(){ //retorna o vetor de jogadores obtidos no arquivo
	int tam = TamVetor();
	JOGADOR rankings[tam];
	arquivo.open("ranking.bin", ios::binary);
	for(int i = 0; i < tam; i++){
		arquivo.read((char*)&rankings[i], sizeof(JOGADOR));
	}
	arquivo.close();	
}

void printaRanking(){
	int tam = TamVetor();
	JOGADOR *jogadoresRanking = vetorArq();	
	Ranking = RankingOrdenado(jogadoresRanking, tam);
	arquivo.open("ranking.bin", ios::binary);
	if(Ranking.size() == 0 || !arquivo.is_open()){
		cout << "Ranking vazio!" << endl;
	}
	else{
		arquivo.close(); //fecha o arquivo caso esteja aberto
		cout << "\t\t\t\tRANKING DETETIVE SSA CITY" << endl << endl << endl;
		cout << "////////////////////////////////////////////////////////" << endl << endl;
		for(it = Ranking.begin(); it != Ranking.end(); it++){
			cout << it -> nome << endl;
			cout << "Tempo: " << it->tempo << endl;
			cout << "///////////////////////////////////////" << endl << endl;
		}	
	}	
}

