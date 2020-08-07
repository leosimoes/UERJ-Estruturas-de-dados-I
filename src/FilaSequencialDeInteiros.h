#ifndef FILASEQUENCIALDEINTEIROS_H_INCLUDED
#define FILASEQUENCIALDEINTEIROS_H_INCLUDED

#define TAM_MAX 10 // Tamanho máximo do vetor //mudar para 100
#include<iostream>
#include "Extremidade.h"

using namespace std;

class FilaSequencialDeInteiros {
private:
	int vetor[TAM_MAX];
	int tamanho;//tamanho atual do vetor
	Extremidade extremidade;
public:
	FilaSequencialDeInteiros();
	FilaSequencialDeInteiros(Extremidade extremidade);
	void enqueue(int);//Insere
	void dequeue();//Remove
	bool vazia();
	bool cheio();
	int consulta();
	void imprimeLista();
	virtual ~FilaSequencialDeInteiros();
};

FilaSequencialDeInteiros::FilaSequencialDeInteiros() {
	this->tamanho = 0;
	this->extremidade = esquerda;
}

FilaSequencialDeInteiros::FilaSequencialDeInteiros(Extremidade extremidade) {
	this->tamanho = 0;
	this->extremidade = extremidade;
}

void FilaSequencialDeInteiros::enqueue(int numero) {
	if (this->cheio()) {
		cout << "Fila cheia - elemento nao inserido" << endl;
	} else if (this->vazia()) {
		this->vetor[0] = numero;
		this->tamanho = 1;
	} else if (this->extremidade == esquerda) {
		//Insere no inicio
		for (int i = this->tamanho; i > 0; --i) {
			this->vetor[i] = this->vetor[i - 1];
		}
		this->vetor[0] = numero;
		++this->tamanho;
	} else if (this->extremidade == direita) {
		//Insere no Final
		vetor[this->tamanho] = numero;
		++this->tamanho;
	}
}

void FilaSequencialDeInteiros::dequeue() {
	if (this->vazia()) {
		cout << "Fila vazia - elemento nao removido" << endl;
	} else if (this->extremidade == esquerda) {
		//Remove no final
		vetor[this->tamanho] = 0;//"removendo elemento"
		--this->tamanho;
	} else if (this->extremidade == direita) {
		//Remove no Inicio
		for (int i = 0; i <= this->tamanho - 2; ++i) {
			vetor[i] = vetor[i + 1];
		}
		--this->tamanho;
	}
}

bool FilaSequencialDeInteiros::vazia() {
	if (this->tamanho == 0) {
		return true;
	} else {
		return false;
	}
}

bool FilaSequencialDeInteiros::cheio() {
	if (this->tamanho >= TAM_MAX) {
		return true;
	} else {
		return false;
	}
}

int FilaSequencialDeInteiros::consulta() {
	if (this->vazia()) {
		cout << "Fila vazia - nao ha elemento para consultar" << endl;
		return 0;
	} else if (this->extremidade == direita) {
		return vetor[0];
	} else if (this->extremidade == esquerda) {
		return vetor[this->tamanho - 1];
	}
}

void FilaSequencialDeInteiros::imprimeLista() {
	if (this->vazia()) {
		cout << "Fila Sequencial Vazia" << endl;
	} else {
		cout << "Fila Sequencial:  " << endl;
		for (int i = 0; i < this->tamanho; ++i) {
			cout << this->vetor[i] << "    " << setw(5);
		}
		cout << endl;
	}
}

FilaSequencialDeInteiros::~FilaSequencialDeInteiros() {
}

#endif // FILASEQUENCIALDEINTEIROS_H_INCLUDED
