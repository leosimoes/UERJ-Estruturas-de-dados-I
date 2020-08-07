#ifndef LISTASEQUENCIALDEINTEIROS_H_INCLUDED
#define LISTASEQUENCIALDEINTEIROS_H_INCLUDED

#define TAM_MAX 10 // Tamanho máximo do vetor //mudar para 100
#include<iostream>
using namespace std;

class ListaSequencialDeInteiros {
private:
	int vetor[TAM_MAX];
	int tamanho;//tamanho atual do vetor
public:
	ListaSequencialDeInteiros();
	void inserirInicio(int);
	void inserirFinal(int);
	void removerInicio();
	void removerFinal();
	void removerElemento(int);
	bool buscarElemento(int);
	bool vazia();
	bool cheio();
	void imprimeLista();
	virtual ~ListaSequencialDeInteiros();
};

ListaSequencialDeInteiros::ListaSequencialDeInteiros() {
	this->tamanho = 0;
}

void ListaSequencialDeInteiros::inserirInicio(int numero) {
	if (this->vazia()) {
		this->vetor[0] = numero;
		this->tamanho = 1;
	} else if (this->buscarElemento(numero)) {
		cout << "Elemento não inserido - já estava contido" << endl;
	} else if (!this->cheio()) {
		for (int i = this->tamanho; i > 0; --i) {
			this->vetor[i] = this->vetor[i - 1];
		}
		this->vetor[0] = numero;
		++this->tamanho;
	} else if (this->cheio()) {
		cout << "Lista cheia - elemento nao inserido" << endl;
	}
}

void ListaSequencialDeInteiros::inserirFinal(int numero) {
	if (this->cheio()) {
		cout << "Lista cheia - elemento nao inserido" << endl;
	} else if (this->buscarElemento(numero)) {
		cout << "Elemento não inserido - já estava contido" << endl;
	} else {
		vetor[this->tamanho] = numero;
		++this->tamanho;
	}
}

void ListaSequencialDeInteiros::removerInicio() {
	if (!vazia()) {
		for (int i = 0; i <= this->tamanho - 2; ++i) {
			vetor[i] = vetor[i + 1];
		}
		--this->tamanho;
	} else if (this->vazia()) {
		cout << "Lista vazia - nao houve remocao" << endl;
	}
}

void ListaSequencialDeInteiros::removerFinal() {
	if (!vazia()) {
		vetor[this->tamanho] = 0;//"removendo elemento"
		--this->tamanho;
	} else { //se esta vazia
		cout << "Lista vazia - nao houve remocao" << endl;
	}
}

void ListaSequencialDeInteiros::removerElemento(int numero) {
	for (int i = 0; i < this->tamanho; ++i) {
		if (this->vetor[i] == numero) {
			for (int j = i; j < this->tamanho - 1; ++j) {
				this->vetor[j] = this->vetor[j + 1];
			}
			return;
		}
	}
	cout << "Nao houve remocao - Elemento nao estava contido na Lista" << endl;
}

bool ListaSequencialDeInteiros::buscarElemento(int numero) {
	for (int i = 0; i < this->tamanho; ++i) {
		if (this->vetor[i] == numero) {
			return true;
		}
	}
	return false;
}

bool ListaSequencialDeInteiros::vazia() {
	if (this->tamanho == 0) {
		return true;
	} else {
		return false;
	}
}

bool ListaSequencialDeInteiros::cheio() {
	if (this->tamanho >= TAM_MAX) {
		return true;
	} else {
		return false;
	}
}

void ListaSequencialDeInteiros::imprimeLista() {
	if (this->vazia()) {
		cout << "Lista Sequencial Vazia" << endl;
	} else {
		cout << "Lista Sequencial:  " << endl;
		for (int i = 0; i < this->tamanho; ++i) {
			cout << this->vetor[i] << setw(5);
		}
	}
	cout << endl;
}

ListaSequencialDeInteiros::~ListaSequencialDeInteiros() {
}

#endif // LISTASEQUENCIALDEINTEIROS_H_INCLUDED
