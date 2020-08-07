#ifndef NODEINTEIRO_H_INCLUDED
#define NODEINTEIRO_H_INCLUDED

#include <cstddef>

class NoDeInteiro {
private:
	int numero;
	NoDeInteiro * proximoPTR;
public:
	NoDeInteiro();
	NoDeInteiro(int);
	int getNumero();
	void setNumero(int);
	NoDeInteiro * getProximo();
	void setProximo(NoDeInteiro *);
	virtual ~NoDeInteiro();
};

NoDeInteiro::NoDeInteiro() {
	this->numero = 0;
	this->proximoPTR = NULL;
}

NoDeInteiro::NoDeInteiro(int numero) {
	this->numero = numero;
	this->proximoPTR = NULL;
}

int NoDeInteiro::getNumero() {
	return this->numero;
}

void NoDeInteiro::setNumero(int numero) {
	this->numero = numero;
}

NoDeInteiro * NoDeInteiro::getProximo() {
	return this->proximoPTR;
}

void NoDeInteiro::setProximo(NoDeInteiro * no) {
	this->proximoPTR = no;
}

NoDeInteiro::~NoDeInteiro() {
}

#endif // NODEINTEIRO_H_INCLUDED
