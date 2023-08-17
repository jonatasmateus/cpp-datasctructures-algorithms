#include <iostream>
#include <locale>
using namespace std;

struct aluno {
	int matricula;
	float nota;
	char turma;
};

main() {
	setlocale(LC_CTYPE, "");
	
	const int TAM_VETOR = 3;
	struct aluno alunos[TAM_VETOR];
	int i, count = 0;
	float soma = 0, 
			media_nota_turma_A = 0, 
			maior_nota = 0, 
			maior_nota_turma_A = 0, 
			maior_nota_turma_B = 0;
	
	for (i = 0; i < TAM_VETOR; i++) {
		cout 	<< 	"Digite matrícula do aluno " << i + 1 << "\t: ";
		cin 	>> 	alunos[i].matricula;
		cout 	<< 	"Digite nota do aluno " << i + 1 << " (0/10)\t: ";
		cin 	>> 	alunos[i].nota;
		cout	<< 	"Digite turma do aluno " << i + 1 << " (A/B)\t: ";
		cin		>> 	alunos[i].turma;
		cout	<< 	"\n";
	}
	
	system("cls");
	cout << "--------------- Alunos cadastrados -----------------------------------------";
	cout << "\n\n\t\tMatrícula\tNota\t\tTurma\n";
	for (i = 0; i < TAM_VETOR; i++) {
		cout << "Aluno " << i + 1 << ":\t" 
		<< alunos[i].matricula 
		<< "\t\t" << alunos[i].nota 
		<< "\t\t" << alunos[i].turma 
		<< "\n";
	}
	
	cout << "\n--------------- Média das notas da turma A ---------------------------------\n";
	for (i = 0; i < TAM_VETOR; i++) {
		if (alunos[i].turma == 'A' || alunos[i].turma == 'a') {
			soma += alunos[i].nota;
			count++;
			media_nota_turma_A = soma / count;
			if (alunos[i].nota > maior_nota_turma_A) {
				maior_nota_turma_A = alunos[i].nota;
			}
		} else {
			if (alunos[i].nota > maior_nota_turma_B) {
				maior_nota_turma_B = alunos[i].nota;
			}
		}
	}
	cout << "\nMédia nota turma A: " << media_nota_turma_A;
	cout << "\nMaior nota turma A: " << maior_nota_turma_A;
	cout << "\nMaior nota turma B: " << maior_nota_turma_B << "\n";
	
	cout << "\n--------------- Maior nota das turmas registradas --------------------------\n";
	for (i = 0; i < TAM_VETOR; i++) {
		if (alunos[i].nota > maior_nota) {
			maior_nota = alunos[i].nota;
		}
	}
	cout << "\nMaior nota: " << maior_nota << "\n";
}
