//Includes de Bibliotecas do C++
#include <iostream>
#include <stdlib.h>
//Includes dos arquivos de cabecalhos das estruturas encadeadas e sequenciais
#include "NoDeInteiro.h"
#include "Extremidade.h"
//Includes das Estruturas Encadeadas
#include "ListaEncadeadaDeInteiros.h"
#include "FilaEncadeadaDeInteiros.h"
#include "PilhaEncadeadaDeInteiros.h"
#include "DequeEncadeadoDeInteiros.h"
//Includes das Estruturas Sequenciais
#include "ListaSequencialDeInteiros.h"
#include "FilaSequencialDeInteiros.h"
#include "PilhaSequencialDeInteiros.h"
#include "DequeSequencialDeInteiros.h"

using namespace std;

void manipulaListaEncadeada();
void manipulaFilaEncadeada();
void manipulaPilhaEncadeada();
void manipulaDequeEncadeado();

void manipulaListaSequencial();
void manipulaFilaSequencial();
void manipulaPilhaSequencial();
void manipulaDequeSequencial();

int main() {
	int opcao;
	cout << "Escolha a estrutura de dados:" << endl << endl << "Encadeadas:"
			<< endl << " 1 - Listas" << endl << " 2 - Fila" << endl
			<< " 3 - Pilha" << endl << " 4 - Deques" << endl << endl;
	cout << "Sequenciais:" << endl << " 5 - Listas" << endl << " 6 - Fila"
			<< endl << " 7 - Pilha" << endl << " 8 - Deques" << endl << endl;
	cin >> opcao;
	switch (opcao) {
	case 1:
		manipulaListaEncadeada();
		break;
	case 2:
		manipulaFilaEncadeada();
		break;
	case 3:
		manipulaPilhaEncadeada();
		break;
	case 4:
		manipulaDequeEncadeado();
		break;
	case 5:
		manipulaListaSequencial();
		break;
	case 6:
		manipulaFilaSequencial();
		break;
	case 7:
		manipulaPilhaSequencial();
		break;
	case 8:
		manipulaDequeSequencial();
		break;
	default:
		break;
	}
	return 0;
}

//Estruturas Sequenciais
//Lista Sequencial
void manipulaListaSequencial() {
	system("cls");
	ListaSequencialDeInteiros lista;
	int numero, opcao;
	do {
		cout << "--- Manipulando lista sequencial ---" << endl;
		cout << "\nEscolha a opcao:" << endl
				<< "1 - Inserir elemento no inicio" << endl
				<< "2 - Inserir elemento no final" << endl
				<< "3 - Remover elemento do inicio" << endl
				<< "4 - Remover elemento do final" << endl
				<< "5 - Remover elemento" << endl << "6 - Buscar elemento"
				<< endl << "7 - Imprimir lista" << endl;
		cout << endl << endl << "Opcao: " << endl;
		cin >> opcao;
		cout << endl;
		switch (opcao) {
		case 1:
			cout
					<< "Digite o numero (EOF - enquanto inserir um numero e diferente de 0): "
					<< endl;
			while (cin >> numero && numero != 0) {
				lista.inserirInicio(numero);
			}
			break;
		case 2:
			cout
					<< "Digite o numero (EOF - enquanto inserir um numero e diferente de 0): "
					<< endl;
			while (cin >> numero && numero != 0) {
				lista.inserirFinal(numero);
			}
			break;
		case 3:
			lista.removerInicio();
			break;
		case 4:
			lista.removerFinal();
			break;
		case 5:
			cout
					<< "Digite o numero (EOF - enquanto inserir um numero e diferente de 0): "
					<< endl;
			while (cin >> numero && numero != 0) {
				lista.removerElemento(numero);
			}
			break;
		case 6:
			cout
					<< "Digite o numero (EOF - enquanto inserir um numero e diferente de 0): "
					<< endl;
			while (cin >> numero && numero != 0) {
				if (lista.buscarElemento(numero)) {
					cout << "Elemento " << numero << " esta contido na lista"
							<< endl;
				} else {
					cout << "Elemento " << numero
							<< " nao esta contido na lista" << endl;
				}
			}
			system("pause");
			break;
		case 7:
			cout << endl;
			lista.imprimeLista();
			system("pause");
			break;
		default:
			break;
		}
		system("cls");
	} while (opcao != 0);
}

//Fila Sequencial
void manipulaFilaSequencial() {
	system("cls");
	int numero, opcao;
	Extremidade extremidade;
	char ext;
	cout << "Escolha a extremidade da fila:" << endl
			<< "E para esquerda e D para direita" << endl;
	cin >> ext;
	if (ext == 'D') {
		extremidade = direita;
	} else {
		extremidade = esquerda;
	}
	FilaSequencialDeInteiros fila(extremidade);
	system("cls");
	do {
		cout << "--- Manipulando fila sequencial ---" << endl;
		cout << "\nEscolha a opcao:" << endl
				<< "1 - Inserir elemento (enqueue)" << endl
				<< "2 - Remover elemento (dequeue)" << endl
				<< "3 - Consulta elemento na extremidade" << endl
				<< "4 - Imprime" << endl;
		cout << endl << endl << "Opcao: " << endl;
		cin >> opcao;
		cout << endl;
		switch (opcao) {
		case 1:
			cout
					<< "Digite o numero (EOF - enquanto inserir um numero e diferente de 0): "
					<< endl;
			while (cin >> numero && numero != 0) {
				fila.enqueue(numero);
			}
			break;
		case 2:
			fila.dequeue();
			break;
		case 3:
			cout << "Numero na extremidade: " << fila.consulta() << endl;
			system("pause");
			break;
		case 4:
			cout << endl;
			fila.imprimeLista();
			system("pause");
			break;
		default:
			break;
		}
		system("cls");
	} while (opcao != 0);
}

//Pilha Sequencial
void manipulaPilhaSequencial() {
	system("cls");
	int numero, opcao;
	Extremidade extremidade;
	char ext;
	cout << "Escolha a extremidade da pilha:" << endl
			<< "E para esquerda e D para direita" << endl;
	cin >> ext;
	if (ext == 'D') {
		extremidade = direita;
	} else {
		extremidade = esquerda;
	}
	PilhaSequencialDeInteiros pilha(extremidade);
	system("cls");
	do {
		cout << "--- Manipulando pilha sequencial ---" << endl;
		cout << "\nEscolha a opcao:" << endl << "1 - Inserir elemento (push)"
				<< endl << "2 - Remover elemento (pop)" << endl
				<< "3 - Consulta elemento na extremidade" << endl
				<< "4 - Imprime" << endl;
		cout << endl << endl << "Opcao: " << endl;
		cin >> opcao;
		cout << endl;
		switch (opcao) {
		case 1:
			cout
					<< "Digite o numero (EOF - enquanto inserir um numero e diferente de 0): "
					<< endl;
			while (cin >> numero && numero != 0) {
				pilha.push(numero);
			}
			break;
		case 2:
			pilha.pop();
			break;
		case 3:
			cout << "Numero na extremidade: " << pilha.consultar() << endl;
			system("pause");
			break;
		case 4:
			cout << endl;
			pilha.imprimeLista();
			system("pause");
			break;
		default:
			break;
		}
		system("cls");
	} while (opcao != 0);
}

//Deque Sequencial
void manipulaDequeSequencial() {
	system("cls");
	DequeSequencialDeInteiros Deque;
	int numero, opcao;
	do {
		cout << "--- Manipulando deque sequencial ---" << endl;
		cout << "\nEscolha a opcao:" << endl
				<< "1 - Inserir elemento na esquerda" << endl
				<< "2 - Inserir elemento na direita" << endl
				<< "3 - Remover elemento da esquerda" << endl
				<< "4 - Remover elemento da direita" << endl
				<< "5 - Consultar elemento Esquerda" << endl
				<< "6 - Consultar elemento direita" << endl
				<< "7 - Imprimir lista" << endl;
		cout << endl << endl << "Opcao: " << endl;
		cin >> opcao;
		cout << endl;
		switch (opcao) {
		case 1:
			cout
					<< "Digite o numero (EOF - enquanto inserir um numero e diferente de 0): "
					<< endl;
			while (cin >> numero && numero != 0) {
				Deque.inserirEsquerda(numero);
			}
			break;
		case 2:
			cout
					<< "Digite o numero (EOF - enquanto inserir um numero e diferente de 0): "
					<< endl;
			while (cin >> numero && numero != 0) {
				Deque.inserirDireita(numero);
			}
			break;
		case 3:
			Deque.removerEsquerda();
			break;
		case 4:
			Deque.removerDireita();
			break;
		case 5:
			cout << "Elemento a esquerda: " << Deque.consultarEsquerda();
			system("pause");
			break;
		case 6:
			cout << "Elemento a direita: " << Deque.consultarDireita();
			system("pause");
			break;
		case 7:
			Deque.imprimeLista();
			system("pause");
			break;
		default:
			break;
		}
		system("cls");
	} while (opcao != 0);
}

//Estruturas Encadeadas
//Lista Encadeada
void manipulaListaEncadeada() {
	system("cls");
	ListaEncadeadaDeInteiros lista;
	int numero, opcao;
	do {
		cout << "--- Manipulando lista encadeada ---" << endl;
		cout << "\nEscolha a opcao:" << endl
				<< "1 - Inserir elemento no inicio" << endl
				<< "2 - Inserir elemento no final" << endl
				<< "3 - Remover elemento do inicio" << endl
				<< "4 - Remover elemento do final" << endl
				<< "5 - Remover elemento" << endl << "6 - Buscar elemento"
				<< endl << "7 - Imprimir lista" << endl;
		cout << endl << endl << "Opcao: " << endl;
		cin >> opcao;
		cout << endl;
		switch (opcao) {
		case 1:
			cout
					<< "Digite o numero (EOF - enquanto inserir um numero e diferente de 0): "
					<< endl;
			while (cin >> numero && numero != 0) {
				lista.inserirInicio(new NoDeInteiro(numero));
			}
			break;
		case 2:
			cout
					<< "Digite o numero (EOF - enquanto inserir um numero e diferente de 0): "
					<< endl;
			while (cin >> numero && numero != 0) {
				lista.inserirFinal(new NoDeInteiro(numero));
			}
			break;
		case 3:
			lista.removerInicio();
			break;
		case 4:
			lista.removerFinal();
			break;
		case 5:
			cout
					<< "Digite o numero (EOF - enquanto inserir um numero e diferente de 0): "
					<< endl;
			while (cin >> numero && numero != 0) {
				lista.removerElemento(new NoDeInteiro(numero));
			}
			break;
		case 6:
			cout
					<< "Digite o numero (EOF - enquanto inserir um numero e diferente de 0): "
					<< endl;
			while (cin >> numero && numero != 0) {
				if (lista.buscarElemento(new NoDeInteiro(numero))) {
					cout << "Elemento " << numero << " esta contido na lista"
							<< endl;
				} else {
					cout << "Elemento " << numero
							<< " nao esta contido na lista" << endl;
				}
			}
			break;
		case 7:
			cout << endl;
			lista.imprimeLista();
			system("pause");
			break;
		default:
			break;
		}
		system("cls");
	} while (opcao != 0);
}

void manipulaFilaEncadeada() {
	system("cls");
	int numero, opcao;
	Extremidade extremidade;
	char ext;
	cout << "Escolha a extremidade da fila:" << endl
			<< "E para esquerda e D para direita" << endl;
	cin >> ext;
	if (ext == 'D' || ext == 'd') {
		extremidade = direita;
	} else {
		extremidade = esquerda;
	}
	FilaEncadeadaDeInteiros fila(extremidade);
	system("cls");
	do {
		cout << "--- Manipulando fila encadeada ---" << endl;
		cout << "\nEscolha a opcao:" << endl
				<< "1 - Inserir elemento (enqueue)" << endl
				<< "2 - Remover elemento (dequeue)" << endl
				<< "3 - Consulta elemento na extremidade" << endl
				<< "4 - Imprime" << endl;
		cout << endl << endl << "Opcao: " << endl;
		cin >> opcao;
		cout << endl;
		switch (opcao) {
		case 1:
			cout
					<< "Digite o numero (EOF - enquanto inserir um numero e diferente de 0): "
					<< endl;
			while (cin >> numero && numero != 0) {
				fila.enqueue(new NoDeInteiro(numero));
			}
			break;
		case 2:
			fila.dequeue();
			break;
		case 3:
			cout << "Numero na extremidade: " << fila.consultar() << endl;
			system("pause");
			break;
		case 4:
			cout << endl;
			fila.imprimeLista();
			system("pause");
			break;
		default:
			break;
		}
		system("cls");
	} while (opcao != 0);
}

void manipulaPilhaEncadeada() {
	system("cls");
	int numero, opcao;
	Extremidade extremidade;
	char ext;
	cout << "Escolha a extremidade da pilha:" << endl
			<< "E para esquerda e D para direita" << endl;
	cin >> ext;
	if (ext == 'D') {
		extremidade = direita;
	} else {
		extremidade = esquerda;
	}
	PilhaEncadeadaDeInteiros pilha(extremidade);
	system("cls");
	do {
		cout << "--- Manipulando pilha encadeada ---" << endl;
		cout << "\nEscolha a opcao:" << endl << "1 - Inserir elemento (push)"
				<< endl << "2 - Remover elemento (pop)" << endl
				<< "3 - Consulta elemento na extremidade" << endl
				<< "4 - Imprime" << endl;
		cout << endl << endl << "Opcao: " << endl;
		cin >> opcao;
		cout << endl;
		switch (opcao) {
		case 1:
			cout
					<< "Digite o numero (EOF - enquanto inserir um numero e diferente de 0): "
					<< endl;
			while (cin >> numero && numero != 0) {
				pilha.push(new NoDeInteiro(numero));
			}
			break;
		case 2:
			pilha.pop();
			break;
		case 3:
			cout << "Numero na extremidade: " << pilha.consultar() << endl;
			system("pause");
			break;
		case 4:
			cout << endl;
			pilha.imprimeLista();
			system("pause");
			break;
		default:
			break;
		}
		system("cls");
	} while (opcao != 0);
}

void manipulaDequeEncadeado() {
	system("cls");
	DequeEncadeadoDeInteiros Deque;
	int numero, opcao;
	do {
		cout << "--- Manipulando deque encadeada ---" << endl;
		cout << "\nEscolha a opcao:" << endl
				<< "1 - Inserir elemento na esquerda" << endl
				<< "2 - Inserir elemento na direita" << endl
				<< "3 - Remover elemento da esquerda" << endl
				<< "4 - Remover elemento da direita" << endl
				<< "5 - Consultar elemento esquerda" << endl
				<< "6 - Consultar elemento direita" << endl
				<< "7 - Imprimir lista" << endl;
		cout << endl << endl << "Opcao: " << endl;
		cin >> opcao;
		cout << endl;
		switch (opcao) {
		case 1:
			cout
					<< "Digite o numero (EOF - enquanto inserir um numero e diferente de 0): "
					<< endl;
			while (cin >> numero && numero != 0) {
				Deque.inserirEsquerda(new NoDeInteiro(numero));
			}
			break;
		case 2:
			cout
					<< "Digite o numero (EOF - enquanto inserir um numero e diferente de 0): "
					<< endl;
			while (cin >> numero && numero != 0) {
				Deque.inserirDireita(new NoDeInteiro(numero));
			}
			break;
		case 3:
			Deque.removerEsquerda();
			break;
		case 4:
			Deque.removerDireita();
			break;
		case 5:
			cout << "Elemento a direita : " << Deque.consultarEsquerda()
					<< endl;
			system("pause");
			break;
		case 6:
			cout << "Elemento a esquerda: " << Deque.consultarDireita() << endl;
			system("pause");
			break;
		case 7:
			Deque.imprimeLista();
			system("pause");
			break;
		default:
			break;
		}
		system("cls");
	} while (opcao != 0);
}

