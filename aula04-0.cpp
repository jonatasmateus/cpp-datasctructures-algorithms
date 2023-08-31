#include <iostream>
#include <string.h>
#include <conio.h>
#include <locale>
#define MAX_FILA 5 // Tamanho Máximo da Fila

using namespace std;
struct DADOS_ALUNO{
	int CodAluno;
	char Nome[100];
	int Turma;
};

// Protótipos das funções
bool Enfileirar(DADOS_ALUNO Fila[], int CodAluno, char Nome[], int Turma, int &FimFila);
bool ExibirPrimeiro(DADOS_ALUNO Fila[], int IniFila, int FimFila);
bool Desenfileirar(DADOS_ALUNO Fila[], int &PosicaoFim);

main(){
	setlocale(LC_CTYPE, "");
	struct DADOS_ALUNO FilaAlunos[MAX_FILA]; // Fila
	int IniFila = 0; // Início da fila
	int FimFila = 0; // Fim da fila
	bool Ret; int CodAluno, Turma;
	char Nome[100];
	bool ContinuarMenu = true; int Op;
	
	do {
		system("cls");
		cout << "Menu de operações acionado" << endl << endl;
		cout << "1 - Enfileirar" << endl;
		cout << "2 - Exibir primeiro" << endl;
		cout << "3 - Desenfileirar" << endl;
		cout << "4 - Sair" << endl;
		cout << "\nDigite a operação desejada: ";
		cin >> Op;
		
		switch(Op) {
			case 1: 
				cout << "\n>> Inserção" << endl;
				cout << "Digite o código do aluno: ";
				cin >> CodAluno;
				cout << "Digite o nome do aluno: ";
				cin >> Nome;
				cout << "Digite a turma: ";
				cin >> Turma;
				Ret = Enfileirar(FilaAlunos, CodAluno, Nome, Turma, FimFila);
					if(Ret == true){
						cout << ">> Inserção efetuada com sucesso!" << endl;
					}
				cout << "\nPressione qualquer tecla para continuar...";
				getch();
				system("cls");
				break;
			case 2: 
				Ret = ExibirPrimeiro(FilaAlunos, IniFila, FimFila);
				if(Ret == false){
					cout << "\n>> Não foi possível exibir a fila.";
				}
				cout << "\nPressione qualquer tecla para continuar...";
				getch();
				system("cls");
				break;
			case 3: 
				Ret = Desenfileirar(FilaAlunos, FimFila);
				if(Ret == false){
					cout << "\n>> Não foi possível desenfileirar a fila.";
				} else {
					cout << "\n>> Desenfileirando a fila..." << endl;
					cout << ">> Primeiro da fila desenfileirado com sucesso!";
				}
				cout << "\nPressione qualquer tecla para continuar...";
				getch();
				system("cls");
				break;
			case 4: 
				cout << "\n>> Menu encerrado com sucesso." << endl;
				ContinuarMenu = false;
				break;
			default:
				cout << "\n>> Operação digitada desconhecida. \n>> Menu encerrado." << endl;
				ContinuarMenu = false;
		}
	} while (ContinuarMenu);
	
}

// Enfileirar
bool Enfileirar(DADOS_ALUNO Fila[], int CodAluno, char Nome[], int Turma, int &FimFila){
	if (FimFila == MAX_FILA){
		cout << "ERRO: Fila cheia.";
		return false;
	}
	else{
		Fila[FimFila].CodAluno = CodAluno;
		strcpy(Fila[FimFila].Nome, Nome);
		Fila[FimFila].Turma = Turma;
		FimFila++;
	}
	return true;
}
// Exibe o primeiro elemento da fila
bool ExibirPrimeiro(DADOS_ALUNO Fila[], int IniFila, int FimFila){
	if(FimFila == 0){
		cout << "ERRO: Fila vazia";
		return false;
	}
	cout << "\n>> Exibindo o primeiro registro" << endl;
	cout << "Código do Aluno: " << Fila[IniFila].CodAluno << endl;
	cout << "Nome: " << Fila[IniFila].Nome << endl;
	cout << "Turma: " << Fila[IniFila].Turma << endl;
	return true;
}
// Desenfileirar
bool Desenfileirar(DADOS_ALUNO Fila[], int &PosicaoFim){
	int ind;
	if (PosicaoFim == 0) {
		cout << "ERRO: Lista vazia.";
		return false;
	}
	// Desloca a fila sobrepondo o primeiro elemento
	for(ind = 0; ind < PosicaoFim; ind++){
		Fila[ind] = Fila[ind+1];
	}
	PosicaoFim--;
	return true;
}


