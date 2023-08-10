#include <iostream>
#include <locale>
using namespace std;

main(){
	setlocale(LC_CTYPE, "");
	const int TAM_MAX_VETOR = 4;
	int i, idade[TAM_MAX_VETOR], maior_idade = idade[0], pos_maior_idade = i;
	
	for (i=0; i<TAM_MAX_VETOR; i++){
		//std::cout
		cout<<"Digite "<<i+1<<"ª idade: ";
		cin>>idade[i];
	}
	cout<<"\nAs idades digitadas foram: ";
	for (i=0; i<TAM_MAX_VETOR; i++){
		cout<<idade[i]<<" ";
		if (idade[i] > maior_idade) {
			maior_idade = idade[i];
			pos_maior_idade = i;
		}
	}
	cout<<"\nA maior idade digitada foi: "<<maior_idade;
	cout<<"\nPosição da maior idade digitada: "<<pos_maior_idade<<"\n";
}
