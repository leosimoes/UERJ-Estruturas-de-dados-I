#ifndef LISTAENCADEADADEINTEIROS_H_INCLUDED
#define LISTAENCADEADADEINTEIROS_H_INCLUDED

#include <iostream>
#include <iomanip>

#include "NoDeInteiro.h"

using namespace std;

class ListaEncadeadaDeInteiros {
private:
	NoDeInteiro * inicioPtr;
public:
	ListaEncadeadaDeInteiros();
	void inserirInicio(NoDeInteiro *);
	void inserirFinal(NoDeInteiro *);
	void removerInicio();
	void removerFinal();
	void removerElemento(NoDeInteiro *);
	bool buscarElemento(NoDeInteiro *);
	bool vazia();
	void imprimeLista();
	virtual ~ListaEncadeadaDeInteiros();
};

//Implementacoes dos metodos da classe
ListaEncadeadaDeInteiros::ListaEncadeadaDeInteiros() {
	this->inicioPtr = NULL;
}

void ListaEncadeadaDeInteiros::inserirInicio(NoDeInteiro * novoNoPtr) {
	if (this->vazia()) {
		this->inicioPtr = novoNoPtr;
	} else {
		novoNoPtr->setProximo(this->inicioPtr);
		this->inicioPtr = novoNoPtr;
	}
}

void ListaEncadeadaDeInteiros::inserirFinal(NoDeInteiro * novoNoPtr) {
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

void ListaEncadeadaDeInteiros::removerInicio() {
	if (this->vazia()) {
		cout << "Lista Vazia - Elemento nao foi removido" << endl;
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

void ListaEncadeadaDeInteiros::removerFinal() {
	if (this->vazia()) {
		cout << "Lista Vazia - Elemento nao foi removido" << endl;
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

void ListaEncadeadaDeInteiros::removerElemento(NoDeInteiro * novoNoPtr) {
	NoDeInteiro * noAuxPtr;
	NoDeInteiro * noAux2Ptr;
	if (this->inicioPtr->getNumero() == novoNoPtr->getNumero()) {
		this->removerInicio();
		return;
	}
	for (noAuxPtr = this->inicioPtr; noAuxPtr->getProximo() != NULL; noAuxPtr
			= noAuxPtr->getProximo()) {
		if (noAuxPtr->getProximo()->getNumero() == novoNoPtr->getNumero()) {
			noAux2Ptr = noAuxPtr->getProximo()->getProximo();
			delete noAuxPtr->getProximo();
			noAuxPtr->setProximo(noAux2Ptr);
			return;//Não há elementos repetidos na lista
		}
	}
	cout << "Nao houve remocao - Elemento nao estava contido na Lista" << endl;
}

bool ListaEncadeadaDeInteiros::buscarElemento(NoDeInteiro * novoNoPtr) {
	NoDeInteiro * noAuxPtr;
	for (noAuxPtr = this->inicioPtr; noAuxPtr->getProximo() != NULL; noAuxPtr
			= noAuxPtr->getProximo()) {
		if (noAuxPtr->getNumero() == novoNoPtr->getNumero()) {
			return true;
		}
	}
	return false;
}

bool ListaEncadeadaDeInteiros::vazia() {
	if (this->inicioPtr == NULL) {
		return true;
	} else {
		return false;
	}
}

void ListaEncadeadaDeInteiros::imprimeLista() {
	if (this->vazia()) {
		cout << "Lista vazia" << endl;
	} else {
		NoDeInteiro * noAuxPtr;
		cout << "Lista encadeada: " << endl;
		for (noAuxPtr = this->inicioPtr; noAuxPtr != NULL; noAuxPtr
				= noAuxPtr->getProximo()) {
			cout << noAuxPtr->getNumero() << setw(5);
		}
	}
	cout << endl;
}

ListaEncadeadaDeInteiros::~ListaEncadeadaDeInteiros() {
}

#endif // LISTAENCADEADADEINTEIROS_H_INCLUDED
