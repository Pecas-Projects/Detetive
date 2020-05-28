#include "manipulacao_dos_arquivos.h"


bool respostaValida(char opcao){ 		
 	if(opcao != 'N' || 'n' || 'S' || 's' ){ //checagem de erro
 		cout<<"Opcao invalida! Digite novamente"<<endl;
 		return false;
	 }
	 return true;
}

bool resposta(char opcao){
	if(opcao == 'S' || 's' ){
		return true; //resposta positiva
	}
	return false; //resposta negativa
}


int main(){
	//------------------------------------------PREPARANDO O JOGO---------------------------------------------------	
	vector<CARTAS> armas;
	vector<CARTAS> lugares;	 
	vector<CARTAS> personagens;
	
	
	cout << "antes do insere" << endl;
	//criando armas
	CARTAS c;
	c = criaCarta("toxica", "arma");
	cout << c.nome << " " << c.tipo << endl;

	armas = insereEmbaralhado(criaCarta("Chumbinho", "arma") , armas, 8);
	armas = insereEmbaralhado(criaCarta("Pe de Cabra", "arma"), armas, 8);
	armas = insereEmbaralhado(criaCarta("Pedra", "arma"), armas, 8);
	armas = insereEmbaralhado(criaCarta("Pa", "arma"), armas, 8);
	armas = insereEmbaralhado(criaCarta("Fuzil", "arma"), armas, 8);
	armas = insereEmbaralhado(criaCarta("Canudo", "arma"), armas, 8);
	armas = insereEmbaralhado(criaCarta("Tesoura", "arma"), armas, 8);
	armas = insereEmbaralhado(criaCarta("Estilingue", "arma"), armas, 8);
	cout << endl << "durante o insere..." << endl << endl;
	//criando lugares
	lugares = insereEmbaralhado(criaCarta("Pelourinho", "lugar"), lugares, 9);
	lugares = insereEmbaralhado(criaCarta("Farol da Barra", "lugar"), lugares, 9);
	lugares = insereEmbaralhado(criaCarta("SENAI", "lugar"), lugares, 9);
	lugares = insereEmbaralhado(criaCarta("Rio Vermelho", "lugar"), lugares, 9);
	lugares = insereEmbaralhado(criaCarta("Abrantes", "lugar"), lugares, 9);
	lugares = insereEmbaralhado(criaCarta("SSA Shopping", "lugar"), lugares, 9);
	lugares = insereEmbaralhado(criaCarta("UFBA", "lugar"), lugares, 9);
	lugares = insereEmbaralhado(criaCarta("Alphaville", "lugar"), lugares, 9);
	lugares = insereEmbaralhado(criaCarta("Alagoinhas", "lugar"), lugares, 9);
	cout << "durante 2..." << endl;
	//criando personagens
	personagens = insereEmbaralhado(criaCarta("Lapinha","personagem"),personagens,8);
	personagens = insereEmbaralhado(criaCarta("Mariazinha","personagem"),personagens,8);
	personagens = insereEmbaralhado(criaCarta("Veganinho","personagem"),personagens,8);
	personagens = insereEmbaralhado(criaCarta("Graozinho","personagem"),personagens,8);
	personagens = insereEmbaralhado(criaCarta("Joaozinho","personagem"),personagens,8);
	personagens = insereEmbaralhado(criaCarta("Aninha","personagem"),personagens,8);
	personagens = insereEmbaralhado(criaCarta("Fernandinha","personagem"),personagens,8);
	personagens = insereEmbaralhado(criaCarta("Biazinha","personagem"),personagens,8);
	
	cout << "final do insere..." << endl;
	//envelope confidencial	
	cout << "confidencial inicio..." << endl;
	CONFIDENCIAL envelope = insereEnvelopeConf(armas, personagens, lugares);	
	cout << "\tenvelope confidencial\n" << envelope.arma.nome << endl << envelope.lugar.nome << endl << envelope.personagem.nome << endl << endl;
	//juntando todas as pilhas
	
	vector<CARTAS> Distribuicao = pilhaDeDistribuicao(armas, personagens, lugares); //pilha a qual sera distribuida entre jogadores
	
	
	
	//------------------------------------------------INICIO DO JOGO ---------------------------------------------------//
	
	int nJogadores;
	vector<JOGADOR> jogadores; //lista de jogadores
	cout<< "DETETIVE SSA CITY" <<endl<< "REGRAS, Pressione qualquer tecla para continuar..." <<endl;

	getch();
	system("cls");
	
	cout << "Digite o numero de jogadores, lembre-se que pode conter de 3 a 5 jogadores: ";
	while(true){
		cin>>nJogadores;
			if(nJogadores < 3 || nJogadores > 5)
				cout<<"Numero invalido!"<<endl;
			else
				break;
			
	}


	for(int i = 0; i < nJogadores; i++){
		do{
			cout << "Digite seu nome: "; //nome do jogador 
			cin.ignore();
			getline(cin, jogadores[i].nome);
			cout << endl << endl;
			jogadores[i].posicao = i;
			
			mostrarPersonagens(); //mostrar lista de personagens 			
	   		
			cout << jogadores[i].nome << ", voce eh o Player " << i+1 << "! Digite o nome do seu personagem agora: " <<endl;
			cin >> jogadores[i].personagem;
			//depois fazer uma verificacao de nomes iguais


			/*CONSERTAR ESSA FUNCAO*/
			if(!personagemValido(jogadores, i, jogadores[i].personagem)){
				cout << "ERRO! Personagem invalido! Por favor, tente novamente." << endl << endl;
			}
		} while( !personagemValido(jogadores, i, jogadores[i].personagem) );
		
	}

	for(int i = 0; i < nJogadores; i++){ //colocando os jogadores nos lugares corretos	
		
		jogadores[i] = criarJogador(jogadores[i].nome, jogadores[i].personagem, i);	

	}
	
	//----------------------------------------COMECANDO O JOGO --------------------------------//
	
	
	//distribuicao das cartas
	distribuir(Distribuicao, nJogadores, jogadores); 	
	clock_t tempoInicio, tempoFinal;
	char opcao; //para as escolhas realizadas pelo jogador durante o jogo

	tempoInicio = clock(); //marca o inicio do jogo;
	//repeticao do jogo
	do{
		vector<JOGADOR> :: iterator it;
		JOGADOR jogadorAux;
		for(it = jogadores.begin(); it != jogadores.end(); it++){
			cout << "Jogador " << &it << " ,eh a sua vez!" << endl;
			
			cout << "Deseja se movimentar? [S][N]" << endl; //MOVIMENTO
			do{
				cin >> opcao;	
			} while( !respostaValida(opcao));
			
			jogadorAux = *it;
			if( resposta(opcao)){ //resposta positiva
				desenharMapa();
				movimentar(&jogadorAux); //toda parte de movimentacao do jogador				
			}
			
			manipularLista(it->lista); //manipular lista tem parametos sim
			palpitar(jogadorAux, nJogadores, jogadores, envelope);
			manipularLista(it->lista);	
		
		}
		
	}while(envelope.arma.nome != "" && envelope.lugar.nome != "" && envelope.personagem.nome == "");
	
//	tempoFinal = clock(); //marca o final
	//pegara o jogador da vez - o que venceu
//	it->tempo = (tempoFinal - tempoInicial);
	
	//adicionando ao ranking
	return 0;
}



