#ifndef FILAENCADEADADEINTEIROS_H_INCLUDED
#define FILAENCADEADADEINTEIROS_H_INCLUDED

#include <iostream>
#include <iomanip>

#include "NoDeInteiro.h"
#include "Extremidade.h"

using namespace std;

class FilaEncadeadaDeInteiros {
private:
	NoDeInteiro * inicioPtr;
	Extremidade extremidade;
public:
	FilaEncadeadaDeInteiros();
	FilaEncadeadaDeInteiros(Extremidade extremidade);
	void enqueue(NoDeInteiro *);
	void dequeue();
	int consultar();
	bool vazia();
	void imprimeLista();
	virtual ~FilaEncadeadaDeInteiros();
};

FilaEncadeadaDeInteiros::FilaEncadeadaDeInteiros() {

}

FilaEncadeadaDeInteiros::FilaEncadeadaDeInteiros(Extremidade extremidade) {
	this->inicioPtr = NULL;
	this->extremidade = extremidade;
}

void FilaEncadeadaDeInteiros::enqueue(NoDeInteiro * novoNo) {
	if (this->vazia()) {
		this->inicioPtr = novoNo;
	} else if (this->extremidade == esquerda) {
		//Se a extremidade for esquerda inserir no inicio
		novoNo->setProximo(this->inicioPtr);
		inicioPtr = novoNo;
	} else if (this->extremidade == direita) {
		//Cria um no auxiliar
		NoDeInteiro * noAuxPtr;
		//O no auxiliar aponta para o ultimo elemento da lista
		for (noAuxPtr = this->inicioPtr; noAuxPtr->getProximo() != NULL; noAuxPtr
				= noAuxPtr->getProximo())
			;
		//remove o ultimo elemento
		delete noAuxPtr;
	}

}

void FilaEncadeadaDeInteiros::dequeue() {
	if (this->vazia()) {
		cout << "Fila Vazia - não houve remocao" << endl;
	} else {
		if (this->extremidade == direita) {
			//Se a extremidade for direita excluir no inicio
			//Cria um no auxiliar
			NoDeInteiro * noAuxPtr;
			//O no auxiliar aponta para o segundo elemento da lista
			noAuxPtr = this->inicioPtr->getProximo();
			//remove o primeiro elemento
			delete inicioPtr;
			//o inicio passa a comecar do "segundo" elemento
			this->inicioPtr = noAuxPtr;
		} else if (this->extremidade == esquerda) {
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

int FilaEncadeadaDeInteiros::consultar() {
	if (this->vazia()) {
		cout << "Fila Vazia - não ha elemento para ser consultado" << endl;
		return 0;
	} else {
		if (this->extremidade == direita) {
			return this->inicioPtr->getNumero();
		} else if (this->extremidade == esquerda) {
			//Se a extremidade for esquerda retorna o final
			//Cria um no auxiliar
			NoDeInteiro * noAuxPtr;
			for (noAuxPtr = this->inicioPtr; noAuxPtr->getProximo() != NULL; noAuxPtr
					= noAuxPtr->getProximo())
				;
			return noAuxPtr->getNumero();
		}
	}

}

bool FilaEncadeadaDeInteiros::vazia() {
	if (this->inicioPtr == NULL) {
		return true;
	} else {
		return false;
	}
}

void FilaEncadeadaDeInteiros::imprimeLista() {
	if (this->vazia()) {
		cout << "Fila Encadeada Vazia" << endl;
	} else {
		NoDeInteiro * noAuxPtr;
		cout << "Fila Encadeada:  " << endl;
		for (noAuxPtr = this->inicioPtr; noAuxPtr != NULL; noAuxPtr
				= noAuxPtr->getProximo()) {
			cout << noAuxPtr->getNumero() << setw(5);
		}
		cout << endl;
	}
}

FilaEncadeadaDeInteiros::~FilaEncadeadaDeInteiros() {
}

#endif // FILAENCADEADADEINTEIROS_H_INCLUDED
