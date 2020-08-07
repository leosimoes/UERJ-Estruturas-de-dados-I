#ifndef PILHAENCADEADADEINTEIROS_H_INCLUDED
#define PILHAENCADEADADEINTEIROS_H_INCLUDED

#include <iostream>

#include "NoDeInteiro.h"
#include "Extremidade.h"

using namespace std;

class PilhaEncadeadaDeInteiros {
private:
	NoDeInteiro * inicioPtr;
	Extremidade extremidade;//
public:
	PilhaEncadeadaDeInteiros();
	PilhaEncadeadaDeInteiros(Extremidade extremidade);
	void pop();
	void push(NoDeInteiro *);
	int consultar();
	bool vazia();
	void imprimeLista();
	virtual ~PilhaEncadeadaDeInteiros();

};

PilhaEncadeadaDeInteiros::PilhaEncadeadaDeInteiros() {
	//A extremidade default será a esquerda
	this->inicioPtr = NULL;
	this->extremidade = esquerda;
}

PilhaEncadeadaDeInteiros::PilhaEncadeadaDeInteiros(Extremidade extremidade) {
	this->inicioPtr = NULL;
	this->extremidade = extremidade;
}

void PilhaEncadeadaDeInteiros::push(NoDeInteiro * no) {
	if (this->vazia()) {
		this->inicioPtr = no;
	} else if (this->extremidade == esquerda) {
		//Se a extremidade for esquerda inserir no inicio
		no->setProximo(this->inicioPtr);
		inicioPtr = no;
	} else if (this->extremidade == direita) {
		//Cria um no auxiliar
		NoDeInteiro * noAuxPtr;
		//O no auxiliar aponta para o ultimo elemento da lista
		for (noAuxPtr = this->inicioPtr; noAuxPtr->getProximo() != NULL; noAuxPtr
				= noAuxPtr->getProximo())
			;
		//Inserindo no final
		noAuxPtr->setProximo(no);
	}
}

void PilhaEncadeadaDeInteiros::pop() {
	if (this->vazia()) {
		cout << "Pilha Vazia - não houve remocao" << endl;
	} else {
		if (this->extremidade == esquerda) {
			//Cria um no auxiliar
			NoDeInteiro * noAuxPtr;
			//O no auxiliar aponta para o segundo elemento da lista
			noAuxPtr = this->inicioPtr->getProximo();
			//remove o primeiro elemento
			delete inicioPtr;
			//o inicio passa a comecar do "segundo" elemento
			this->inicioPtr = noAuxPtr;
		} else if (this->extremidade == direita) {
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
}

int PilhaEncadeadaDeInteiros::consultar() {
	if (this->vazia()) {
		cout << "Pilha Vazia - não ha elemento para consulta" << endl;
	} else {
		if (this->extremidade == esquerda) {
			return inicioPtr->getNumero();
		} else if (this->extremidade == direita) {
			NoDeInteiro * noAuxPtr;
			for (noAuxPtr = this->inicioPtr; noAuxPtr->getProximo() != NULL; noAuxPtr
					= noAuxPtr->getProximo())
				;
			return noAuxPtr->getNumero();

		}
	}
}

bool PilhaEncadeadaDeInteiros::vazia() {
	if (this->inicioPtr == NULL) {
		return true;
	} else {
		return false;
	}
}

void PilhaEncadeadaDeInteiros::imprimeLista() {
	if (this->vazia()) {
		cout << "Pilha Sequencial Vazia" << endl;
	} else {
		cout << "Pilha Encadeada:  " << endl;
		NoDeInteiro * noAuxPtr;
		for (noAuxPtr = this->inicioPtr; noAuxPtr != NULL; noAuxPtr
				= noAuxPtr->getProximo()) {
			cout << noAuxPtr->getNumero() << setw(5);
		}
		cout << endl;
	}
}

PilhaEncadeadaDeInteiros::~PilhaEncadeadaDeInteiros() {
}

#endif // PILHAENCADEADADEINTEIROS_H_INCLUDED
