#ifndef PILHASEQUENCIALDEINTEIROS_H_INCLUDED
#define PILHASEQUENCIALDEINTEIROS_H_INCLUDED

#define TAM_MAX 10 // Tamanho máximo do vetor //mudar para 100
#include<iostream>
#include "Extremidade.h"

using namespace std;

class PilhaSequencialDeInteiros {
private:
	int vetor[TAM_MAX];
	int tamanho;//tamanho atual do vetor
	Extremidade extremidade;
public:
	PilhaSequencialDeInteiros();
	PilhaSequencialDeInteiros(Extremidade extremidade);
	void push(int);//Insere
	void pop();//Remove
	bool vazia();
	bool cheio();
	int consultar();
	void imprimeLista();
	virtual ~PilhaSequencialDeInteiros();
};

PilhaSequencialDeInteiros::PilhaSequencialDeInteiros() {
	this->tamanho = 0;
	this->extremidade = esquerda;
}

PilhaSequencialDeInteiros::PilhaSequencialDeInteiros(Extremidade extremidade) {
	this->tamanho = 0;
	this->extremidade = extremidade;
}

void PilhaSequencialDeInteiros::push(int numero) {
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

void PilhaSequencialDeInteiros::pop() {
	if (this->vazia()) {
		cout << "Fila vazia - elemento nao removido" << endl;
	} else if (this->extremidade == direita) {
		//Remove no final
		vetor[this->tamanho] = 0;//"removendo elemento"
		--this->tamanho;
	} else if (this->extremidade == esquerda) {
		//Remove no Inicio
		for (int i = 0; i <= this->tamanho - 2; ++i) {
			vetor[i] = vetor[i + 1];
		}
		--this->tamanho;
	}
}

bool PilhaSequencialDeInteiros::vazia() {
	if (this->tamanho == 0) {
		return true;
	} else {
		return false;
	}
}

bool PilhaSequencialDeInteiros::cheio() {
	if (this->tamanho >= TAM_MAX) {
		return true;
	} else {
		return false;
	}
}

int PilhaSequencialDeInteiros::consultar() {
	if (this->vazia()) {
		cout << "Fila vazia - nao ha elemento para consultar" << endl;
		return 0;
	} else if (this->extremidade == esquerda) {
		return vetor[0];
	} else if (this->extremidade == direita) {
		return vetor[this->tamanho - 1];
	}
}

void PilhaSequencialDeInteiros::imprimeLista() {
	if (this->vazia()) {
		cout << "Pilha Sequencial Vazia" << endl;
	} else {
		cout << "Pilha Sequencial:  " << endl;
		for (int i = 0; i < this->tamanho; ++i) {
			cout << this->vetor[i] << "    " << setw(5);
		}
	}
}

PilhaSequencialDeInteiros::~PilhaSequencialDeInteiros() {
}

#endif // PILHASEQUENCIALDEINTEIROS_H_INCLUDED
