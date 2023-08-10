#include <iostream>
#include <locale>
using namespace std;

main() {
	setlocale(LC_CTYPE, "");
	char nome[50];
	cout << "Digite seu nome: ";
	gets(nome);
	cout << "Nome digitado: ";
	puts(nome);
	cout << "Pimeira letra do nome: " << nome[0];
}
