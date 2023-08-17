#include <iostream>
#include <locale>
using namespace std;

main() {
	setlocale(LC_CTYPE, "");
	const int TAM_MAX_MATRIZ = 4;
	int matriz[TAM_MAX_MATRIZ][TAM_MAX_MATRIZ], i, j, temp = 0;
	for (i=0; i<TAM_MAX_MATRIZ; i++){
		for (j=0; j<TAM_MAX_MATRIZ; j++){
			cout << "Digite o elemento [" << i << "," << j << "]: ";
			cin >> matriz[i][j];
			if (matriz[i][j] == matriz[i][TAM_MAX_MATRIZ - 1]) {
				cout << "\n";
			}
		}
	}
	// cout << matriz // É exibido um endereço hexadecimal no console;
	cout << "Matriz formada: \n";
	for (i=0; i<TAM_MAX_MATRIZ; i++){
		cout << "[";
		for (j=0; j<TAM_MAX_MATRIZ; j++){
			if (j == TAM_MAX_MATRIZ - 1) {
				cout << matriz[i][j];
			} else {
				cout << matriz[i][j] << ", ";
			}
		}
		cout << "],\n";
	}
	cout << "\nElementos da DP: ";
	for (i=0; i<TAM_MAX_MATRIZ; i++){
		for (j=0; j<TAM_MAX_MATRIZ; j++){
			if (i == j){
				cout << matriz[i][j] << " ";
			}
		}
	}
	cout << "\nElementos da DS: ";
	for (i=0; i<TAM_MAX_MATRIZ; i++){
		for (j=0; j<TAM_MAX_MATRIZ; j++){
			if (i + j == TAM_MAX_MATRIZ - 1){
				cout << matriz[i][j] << " ";
			}
		}
	}
	for (i=0; i<TAM_MAX_MATRIZ; i++){
		for (j=0; j<TAM_MAX_MATRIZ; j++){
			if (i == j && matriz[i][j] % 2 == 1 ){
				temp += matriz[i][j];
			}
		}
	}
	cout << "\nSoma dos Impares da DP: " << temp;
	temp = 0;
	for (i=0; i<TAM_MAX_MATRIZ; i++){
		for (j=0; j<TAM_MAX_MATRIZ; j++){
			if ((i + j == TAM_MAX_MATRIZ - 1) && (matriz[i][j] % 2 == 0)) {
				temp += matriz[i][j];
			}
		}
	}
	cout << "\nSoma dos Pares da DS: " << temp;
	temp = 0;
}
