#ifndef DEQUEENCADEADODEINTEIROS_H_INCLUDED
#define DEQUEENCADEADODEINTEIROS_H_INCLUDED

#include <iostream>
#include <iomanip>

#include "NoDeInteiro.h"

using namespace std;

class DequeEncadeadoDeInteiros {
private:
	NoDeInteiro * inicioPtr;
public:
	DequeEncadeadoDeInteiros();
	void inserirEsquerda(NoDeInteiro *);
	void inserirDireita(NoDeInteiro *);
	void removerEsquerda();
	void removerDireita();
	int consultarEsquerda();
	int consultarDireita();
	bool vazia();
	void imprimeLista();
	virtual ~DequeEncadeadoDeInteiros();
};

//Implementacoes dos metodos da classe
DequeEncadeadoDeInteiros::DequeEncadeadoDeInteiros() {
	this->inicioPtr = NULL;
}

void DequeEncadeadoDeInteiros::inserirEsquerda(NoDeInteiro * novoNoPtr) {
	if (this->vazia()) {
		this->inicioPtr = novoNoPtr;
	} else {
		novoNoPtr->setProximo(this->inicioPtr);
		this->inicioPtr = novoNoPtr;
	}
}

void DequeEncadeadoDeInteiros::inserirDireita(NoDeInteiro * novoNoPtr) {
	if (this->vazia()) {
		this->inicioPtr = novoNoPtr;
	} else {
		NoDeInteiro * noAuxPtr;
		//Itera ate que noAtualPtr aponte para o ultimo elemento da lista
		for (noAuxPtr = this->inicioPtr; noAuxPtr->getProximo() != NULL; noAuxPtr
				= noAuxPtr->getProximo())
			;
		//Adiciona o novoNoPtr no final da lista
		noAuxPtr->setProximo(novoNoPtr);
	}
}

void DequeEncadeadoDeInteiros::removerEsquerda() {
	if (this->vazia()) {
		cout << "Deque Vazio - Elemento nao foi removido" << endl;
	} else {
		//Cria um no auxiliar
		NoDeInteiro * noAuxPtr;
		//O no auxiliar aponta para o segundo elemento da lista
		noAuxPtr = this->inicioPtr->getProximo();
		//remove o primeiro elemento
		delete inicioPtr;
		//o inicio passa a comecar do "segundo" elemento
		this->inicioPtr = noAuxPtr;
	}
}

void DequeEncadeadoDeInteiros::removerDireita() {
	if (this->vazia()) {
		cout << "Deque Vazia - Elemento nao foi removido" << endl;
	} else {
		//Cria um no auxiliar
		NoDeInteiro * noAuxPtr;
		//O no auxiliar aponta para o ultimo elemento da lista
		for (noAuxPtr = this->inicioPtr; noAuxPtr->getProximo()->getProximo()
				!= NULL; noAuxPtr = noAuxPtr->getProximo())
			;
		//remove o ultimo elemento
		delete noAuxPtr->getProximo();
		noAuxPtr->setProximo(NULL);
	}
}

int DequeEncadeadoDeInteiros::consultarEsquerda() {
	if (this->vazia()) {
		cout << "Deque vazio - nao ha elemento para ser consultado" << endl;
		return 0;
	} else {
		return this->inicioPtr->getNumero();
	}
}

int DequeEncadeadoDeInteiros::consultarDireita() {
	if (this->vazia()) {
		cout << "Deque vazio - nao ha elemento para ser consultado" << endl;
		return 0;
	} else {
		NoDeInteiro * noAuxPtr;
		for (noAuxPtr = this->inicioPtr; noAuxPtr->getProximo() != NULL; noAuxPtr
				= noAuxPtr->getProximo())
			;
		return noAuxPtr->getNumero();
	}
}

bool DequeEncadeadoDeInteiros::vazia() {
	if (this->inicioPtr == NULL) {
		return true;
	} else {
		return false;
	}
}

void DequeEncadeadoDeInteiros::imprimeLista() {
	if (this->vazia()) {
		cout << "Deque Encadeado Vazio" << endl;
	} else {
		cout << "Deque Encadeado:  " << endl;
		NoDeInteiro * noAuxPtr;
		for (noAuxPtr = this->inicioPtr; noAuxPtr != NULL; noAuxPtr
				= noAuxPtr->getProximo()) {
			cout << noAuxPtr->getNumero() << setw(5);
		}
		cout << endl;
	}
}

DequeEncadeadoDeInteiros::~DequeEncadeadoDeInteiros() {
}

#endif // DEQUEENCADEADODEINTEIROS_H_INCLUDED
