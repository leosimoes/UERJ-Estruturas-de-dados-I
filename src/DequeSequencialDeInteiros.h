#ifndef DEQUESEQUENCIALDEINTEIROS_H_INCLUDED
#define DEQUESEQUENCIALDEINTEIROS_H_INCLUDED

#define TAM_MAX 10 // Tamanho máximo do vetor //mudar para 100
#include<iostream>
using namespace std;

class DequeSequencialDeInteiros {
private:
	int vetor[TAM_MAX];
	int tamanho;//tamanho atual do vetor
	Extremidade extremidade;
public:
	DequeSequencialDeInteiros();
	DequeSequencialDeInteiros( Extremidade);
	void inserirEsquerda(int);
	void inserirDireita(int);
	void removerDireita();
	void removerEsquerda();
	int consultarEsquerda();
	int consultarDireita();
	bool vazia();
	bool cheio();
	void imprimeLista();
	virtual ~DequeSequencialDeInteiros();
};

DequeSequencialDeInteiros::DequeSequencialDeInteiros() {
	this->tamanho = 0;
}

DequeSequencialDeInteiros::DequeSequencialDeInteiros(Extremidade extremidade) {
	this->tamanho = 0;
	this->extremidade = extremidade;
}

void DequeSequencialDeInteiros::inserirEsquerda(int numero) {
	if (this->vazia()) {
		this->vetor[0] = numero;
		this->tamanho = 1;
	} else if (!this->cheio()) {
		for (int i = this->tamanho; i > 0; --i) {
			this->vetor[i] = this->vetor[i - 1];
		}
		this->vetor[0] = numero;
		++this->tamanho;
	} else if (this->cheio()) {
		cout << "Deque cheia - elemento nao inserido" << endl;
	}
}

void DequeSequencialDeInteiros::inserirDireita(int numero) {
	if (this->cheio()) {
		cout << "Lista cheia - elemento nao inserido" << endl;
	} else {
		vetor[this->tamanho] = numero;
		++this->tamanho;
	}
}

void DequeSequencialDeInteiros::removerEsquerda() {
	if (!vazia()) {
		for (int i = 0; i <= this->tamanho - 2; ++i) {
			vetor[i] = vetor[i + 1];
		}
		--this->tamanho;
	} else if (this->vazia()) {
		cout << "Lista vazia - nao houve remocao" << endl;
	}
}

void DequeSequencialDeInteiros::removerDireita() {
	if (!vazia()) {
		vetor[this->tamanho] = 0;//"removendo elemento"
		--this->tamanho;
	} else { //se esta vazia
		cout << "Lista vazia - nao houve remocao" << endl;
	}
}

int DequeSequencialDeInteiros::consultarEsquerda() {
	if (this->vazia()) {
		return 0;
	} else {
		return this->vetor[0];
	}
}

int DequeSequencialDeInteiros::consultarDireita() {
	if (this->vazia()) {
		return 0;
	} else {
		return this->vetor[this->tamanho - 1];
	}
}

bool DequeSequencialDeInteiros::vazia() {
	if (this->tamanho == 0) {
		return true;
	} else {
		return false;
	}
}

bool DequeSequencialDeInteiros::cheio() {
	if (this->tamanho >= TAM_MAX) {
		return true;
	} else {
		return false;
	}
}

void DequeSequencialDeInteiros::imprimeLista() {
	if (this->vazia()) {
		cout << "Deque Sequencial Vazio" << endl;
	} else {
		cout << "Deque Sequencial:  " << endl;
		for (int i = 0; i < this->tamanho; ++i) {
			cout << this->vetor[i] << "    " << setw(5);
		}
		cout << endl;
	}

}

DequeSequencialDeInteiros::~DequeSequencialDeInteiros() {
}

#endif // DEQUESEQUENCIALDEINTEIROS_H_INCLUDED
