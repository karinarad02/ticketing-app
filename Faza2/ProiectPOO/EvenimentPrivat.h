#pragma once
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "Eveniment.h"

class EvenimentPrivat:public Eveniment
{
private:
	string listaInvitatiSpeciali;
	int taxaSpeciala;
public:
	//CONSTRUCTOR FARA PARAMETRII
	EvenimentPrivat() {
		listaInvitatiSpeciali = "";
		taxaSpeciala = 200;
	}

	//CONSTRUCTOR CU PARAMETRII
	EvenimentPrivat(string data, int ora, string denumire, string locatie, SalaEveniment se, string listaInvitatiSpeciali, int taxaSpeciala):Eveniment(data,ora,denumire,locatie,se) {
		this->listaInvitatiSpeciali = listaInvitatiSpeciali;
		this->taxaSpeciala = taxaSpeciala;
	}

	//CONSTRUCTOR DE COPIERE
	EvenimentPrivat(const EvenimentPrivat& ep):Eveniment(ep) {
		if (ep.listaInvitatiSpeciali != "")this->listaInvitatiSpeciali = ep.listaInvitatiSpeciali;
		if (ep.taxaSpeciala != 0)this->taxaSpeciala = ep.taxaSpeciala;
	}

	//SUPRAINCARCARE OPERATOR =
	EvenimentPrivat& operator=(const EvenimentPrivat& ep) {
		if (this != &ep) {
			Eveniment::operator=(ep);
			if (ep.listaInvitatiSpeciali != "")this->listaInvitatiSpeciali = ep.listaInvitatiSpeciali;
			if (ep.taxaSpeciala != 0)this->taxaSpeciala = ep.taxaSpeciala;
		}
		return *this;
	}

	//GETTERI
	string getListaInvitatiSpeciali() {
		return listaInvitatiSpeciali;
	}
	int getTaxaSpeciala() {
		return taxaSpeciala;
	}
	//SETTERI
	void setListaInvitatiSpeciali(string listaInvitatiSpeciali) {
		if (listaInvitatiSpeciali != "")
			this->listaInvitatiSpeciali = listaInvitatiSpeciali;
	}
	void setTaxaSpeciala(int taxaSpeciala) {
		if (taxaSpeciala != 0)
			this->taxaSpeciala = taxaSpeciala;
	}

	//METODE VIRTUALE
	virtual void afisareInvitati() {
		cout << "Lista Invitati Speciali: " << this->getListaInvitatiSpeciali() << endl;
	}
	virtual void sala() {
		cout <<"Evenimentul are loc in sala: "<< this->getSalaEveniment();
	}

	//SUPRAINCARCARE operatori << si >>
	friend ostream& operator<<(ostream& out, EvenimentPrivat ep) {
		out << (Eveniment)ep << endl;
		out << "Lista Invitati Speciali: " << ep.listaInvitatiSpeciali << endl;
		out << "Taxa Speciala: " << ep.taxaSpeciala << endl;
		return out;

	};
	friend ofstream& operator<<(ofstream& out, EvenimentPrivat ep) {
		out << (Eveniment)ep << endl;
		out << ep.listaInvitatiSpeciali << endl;
		out << ep.taxaSpeciala << endl;
		return out;

	};
	friend istream& operator>>(istream& in, EvenimentPrivat& ep) {

		in >> (Eveniment&)ep;
		cout << "Lista Invitati Speciali: ";
		in >> ep.listaInvitatiSpeciali;
		cout << "Taxa Speciala: ";
		in >> ep.taxaSpeciala;
		return in;
	};
	friend ifstream& operator>>(ifstream& in, EvenimentPrivat& ep) {

		in >> (Eveniment&)ep;
		in >> ep.listaInvitatiSpeciali;
		in >> ep.taxaSpeciala;
		return in;
	};
	
};

