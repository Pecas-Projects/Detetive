#include "cartas.h"

typedef struct{
	vector<CARTAS> cartas;
	string nome; //nome da pessoa que joga
	string personagem; //nome do personagem
	string lugar; //nome do lugar que se encontra
	vector<item>lista; //"comanda" de palpites do jogador
	int posicao; //posicao na ordem das jogadas
	int energia; //energia que possui para se locomover 
	double tempo; //caso ganhe o jogo, o tempo em que conseguiu isso
} JOGADOR;


//CRIA O JOGADOR 
JOGADOR criarJogador(string nome, string personagem, int posicao){
	JOGADOR jogador;
	jogador.nome = nome;
	jogador.personagem = personagem;
	jogador.energia = 10;
	jogador.posicao = posicao;
	
	if(personagem == "Lapinha"){
		   jogador.lugar = "SENAI";
	}
	else if(personagem == "Mariazinha"){
		   jogador.lugar = "UFBA";
	}
	else if(personagem == "GRAOZINHO"){
		   jogador.lugar = "Rio Vermelho";
	}
	else if(personagem == "Aninha"){
		   jogador.lugar = "Abrantes";
	}
	else if(personagem == "Biazinha"){
		   jogador.lugar = "Alphaville";
	}
	else if(personagem == "Veganinho"){
		   jogador.lugar = "Alagoinhas";
	}
	
	else if(personagem == "Fernandinha"){
		   jogador.lugar = "Pelourinho";
	}
	
	return jogador;
}




bool personagemValido(vector<JOGADOR>jogadores, int tam, string nome){
	if( (nome != "Biazinha") && (nome != "Lapinha") && (nome != "Mariazinha") && (nome != "Veganinho") && (nome != "Joazinho") && (nome != "Graozinho") && (nome != "Aninha") && (nome != "Fernandinha") ){
		cout << "Nome invalido! Digite o nome de um dos personagens disponiveis";
		cout << endl;
		return false; //nome invalido
	}
	for(int i = 0; i <= tam; i++){
		if(jogadores[i].personagem != nome){
			return true; //valido
		}
		else{
			cout << "Esse nome ja foi escolhido! Digite o nome de um dos personagens disponiveis";
			cout << endl;
			return false;
			//personagem ja selecionado
		}
	}
}



void calculoDeEnergia(){
	
}


void mostrarPersonagens(){
	cout << "\t\t[1] Biazinha\t\t[5] Veganinho" << endl;
	cout << "\t\t[2] Aninha\t\t[6] Graozinho" << endl;
	cout << "\t\t[3] Lapinha\t\t[7] Joaozinho" << endl;
	cout << "\t\t[4] Fernandinha\t\t[8] Mariazinha" << endl;	
	cout << endl;
}


void palpitar(JOGADOR player, int n, vector<JOGADOR>jogadores, CONFIDENCIAL envelope){ //bia e fernanda sao mt brabas
 	
 	char x;
 	string assassino, arma, mostrar;
 	JOGADOR *prox;
 	int aux, cont;
 	vector<string>opcoes;
 	bool blefe = false;
 	CARTAS cartaAux;
 	cout<<"Se deseja dar um palpite digite a letra S, se nao, digite a letra N"<<endl;
 	cin>>x;
 	
 	while(true){
 		
 		if(x != 'N' || 'n' || 'S' || 's'){ //checagem de erro
 			cout<<"Opcao invalida! Digite novamente"<<endl;
 			cin>>x;
 			if(x == 'N' || 'n' || 'S' || 's') break;
	 	}
	}
	
	if( x == 'N'|| 'n'){ 
		system("cls");
	}
	else {
		cout<<"Para palpitar digite o nome do assassino e o nome da arma, respectivamente:"<<endl;
		cin>>assassino>>arma;
		
		while (true){ //checagem de erro
				if( assassino != "Lapinha" || "Mariazinha" || "Veganinho" || "Graozinho" || "Joazinho" || "Aninha" || "Fernandinha" || "Biazinha"){
					cout<<"Nome invalido, digite outro:"<<endl;
					cin>>assassino;
					if( assassino == "Lapinha" || "Mariazinha" || "Veganinho" || "Graozinho" || "Joazinho" || "Aninha" || "Fernandinha" || "Biazinha") break;
				}
			}
				
		while (true){ //checagem de erro
			if(arma != "Chumbinho" || "Pe de cabra" || "Pedra" || "Fuzil" || "Canudo" || "Tesoura" || "Estilingue" || "Pa"){
				cout<<"Arma inválida, digite outra:"<<endl;
				cin>>arma;
				if(arma == "Chumbinho" || "Pe de cabra" || "Pedra" || "Fuzil" || "Canudo" || "Tesoura" || "Estilingue" || "Pa") break;		
			}
		}	
		
		aux = player.posicao;
	
		for(int i = 1; i < n; ++i){ // implementando no vector uma lista circular
			vector<CARTAS> ::iterator it; //iterator que percorre a lista de cartas de cada jogador
			
			if( aux == n){
			prox = &jogadores[0];
			aux = 0;
			}
			else{
			prox = &jogadores[aux + 1];
			aux = aux + 1;
			}
			
			
			for(it = prox->cartas.begin(); it != prox->cartas.end(); it++){ // procuarando se o proximo jogador tem alguma carta do palpite
				
				if(player.lugar == it->nome){
					opcoes.push_back(it->nome);
				}
				if(assassino == it->nome){
					opcoes.push_back(it->nome);
				}
				if(arma == it->nome){
					opcoes.push_back(it->nome);
				}
				
			}
			
			if(opcoes.size() != 0) break;
		}
	
		if(opcoes.size() == 0){ //fim de jogo
			for(vector<CARTAS>::iterator it2 = player.cartas.begin(); it2< player.cartas.end()+1; it2++ ){
				
				cartaAux= *it2;
				
				if((cartaAux.nome == player.lugar)||(cartaAux.nome == arma)||(cartaAux.nome == assassino)){
					cout<<"Nao foi achada nenhuma carta do seu palpite com os outros jogadores, BLEFE DECTECTADO!"<<endl;
					blefe = true;
					break;
					}
				}
			
			
			if(!blefe){			
			
			envelope.arma.nome = "";
			envelope.lugar.nome = "";
			envelope.personagem.nome = "";
			
			system("cls");
			cout<<"-------GAME OVER------"<<endl;
			cout<<player.nome + " ganhou o DETETIVE SSA CITY!"<<endl;
			cout<<assassino + " matou fulado com o(a) " + arma + " em " + player.lugar;
			}
		}
		
		else{
		
			system("cls");
			cout<<"O jogador " + prox->nome + " tem uma ou mais cartas que voce deu o palpite, agora ele devera escolher qual deseja te mostrar"<<endl;
			cout<<"Pressione qualquer tecla para continuar..."<<endl;
			getch();
			system("cls");
		
			cout<<"-------------- CARTAS DISPONÍVEIS -------------"<<endl;
			for(int i = 0; i < opcoes.size(); ++i){
				cout<<opcoes[i]<<endl;
			}
			
			cout<<prox->nome + " digite o nome da carta que deseja mostrar ao jogador " + player.nome<<endl;
			cin>>mostrar;
		
		while (true){ // checagem de erro
			for(int i = 0; i < opcoes.size(); ++i){
				if(mostrar != opcoes[i]) ++cont;
			}
			if(opcoes.size() == cont){
				cout<<"Carta inválida, digite outra:";
				cin>>mostrar;
			}
			
		}
		
		system("cls");
		
		cout<<player.nome + "pressione qualquer tecla para ver a carta..."<<endl;
		getch();
		cout<<mostrar<<endl;
		
		for(int i = 0; i < 25; ++i){ //mudar na lista de palpites do jogador o item mostrar pra ficar vermelho
			if(player.lista[i].nome == mostrar){
				player.lista[i].cor = 4;
			}
		}
				}
		
			}
		}
	

    void distribuir(vector<CARTAS> geralzao, int nJogadores, vector<JOGADOR> jogadores){ //pilha de cartas totais apos colocadas no envelope Confidencial, numero de jogadores, vetor de jogadores
		while(!geralzao.empty()){ 
			vector<CARTAS> ::iterator it = geralzao.end();
			vector<JOGADOR> ::iterator jog = jogadores.begin();
		
			for(; jog != jogadores.end(); jog++){ //percorre o vetor de jogadores e insere a carta na sua lista de cartas que ele possui
				it = geralzao.end();
				jog->cartas.push_back(*it);  //insere na lista de cartas que cada jogador 
				geralzao.pop_back(); //tira da pillha de todas as cartas o ultimo elemento, o qual ja foi distribuido entre os jogadores
			}
		}
	}
