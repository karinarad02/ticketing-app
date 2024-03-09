#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "Eveniment.h"
#pragma warning (disable:4996)

class Bilet
{
private:
	const int id;
	string nume;
	char* categorie;
	int rand = 0;
	int loc = 0;
	string tip; //elev/student -jumatate,pensionar-40%,copii=0
	string achizitie; //fizic -> la casa de bilete, online-10%
	static int nrTotalBilete;
	float pret;
	Eveniment e;

public:

	//CONSTRUCTOR FARA PARAMETRII
	Bilet() :id(nrTotalBilete++) {

		nume = "Anonim";
		categorie = nullptr;
		rand = 0;
		loc = 0;
		tip = "adult";
		achizitie = "fizic";
		pret = 80;
		Eveniment e;

	}

	//CONSTRUCTOR CU PARAMETRII
	Bilet(string nume,char* categorie, int rand, int loc,string tip,string achizitie,Eveniment e):Bilet() {

		this->nume=nume;
		if (categorie != nullptr) {
			this->categorie = new char[strlen(categorie) + 1];
			strcpy(this->categorie, categorie);
		}
		this->rand=rand;
		this->loc=loc;
		this->tip=tip;
		this->achizitie=achizitie;
		pret = 80;
		this->reducereTip();
		this->reducereAchizitie();
		this->e=e;

	}

	//CONSTRUCTOR DE COPIERE
	Bilet(const Bilet& b):id(b.id){
		if (b.nume != "")this->nume = b.nume;
		if (b.categorie != nullptr) {
			this->categorie = new char[strlen(b.categorie) + 1];
			strcpy_s(this->categorie, strlen(b.categorie) + 1, b.categorie);
		}
		else this->categorie = nullptr;
		if (b.rand!=0)this->rand = b.rand;
		if (b.loc!=0)this->loc = b.loc;
		if(b.tip!="")this->tip=b.tip;
		if (b.achizitie != "")this->achizitie = b.achizitie;
		if (b.pret != 0)this->pret = b.pret;
		this->e = b.e;

	}

	//DESTRUCTOR
	~Bilet() {
		if(categorie!=nullptr){
			delete[]categorie;
			categorie = nullptr;
		}
	}

	//SUPRAINCARCARE OPERATOR =
	Bilet& operator=(const Bilet& b) {

		if (this != &b)
		{
			if (b.nume != "")this->nume = b.nume;
			if (this->categorie != nullptr) {
				delete[]categorie;
			}
			if (b.categorie != nullptr){
				this->categorie = new char[strlen(b.categorie) + 1];
				strcpy_s(this->categorie, strlen(b.categorie) + 1, b.categorie);
			}
			if (b.rand != 0)this->rand = b.rand;
			if (b.loc != 0)this->loc = b.loc;
			if (b.tip != "")this->tip = b.tip;
			if (b.achizitie != "")this->achizitie = b.achizitie;
			if (b.pret != 0)this->pret = b.pret;
			this->e = b.e;

		}
		return *this;
	}

	//GETTERI
	string getNume() {
		return nume;
	}
	char* getCategorie() {
		char* copie = new char[strlen(categorie) + 1];
		strcpy(copie, categorie);
		return copie;
	}
	int getRand() {
		return rand;
	}
	int getLoc() {
		return loc;
	}
	string getTipBilet() {
		return tip;
	}
	string getMetodaAchizitie() {
		return achizitie;
	}
	int getPret() {
		return pret;
	}
	Eveniment getEveniment() {
		return e;
	}
	static int getNrTotalBilete() {
		return nrTotalBilete;
	}
	//SETTERI
	void setNume(string nume) {
		if (nume != "")
			this->nume = nume;
	}
	void setCategorie(const char* categorie) {
		if (categorie != nullptr) {
			this->categorie = new char[strlen(categorie) + 1];
			strcpy(this->categorie, categorie);
		}
	}
	void setRand(int rand) {
		if (rand != 0)
			this->rand = rand;
	}
	void setLoc(int loc) {
		if (loc != 0)
			this->loc = loc;
	}
	void setTipBilet(string tip) {
		if (tip != "")
			this->tip = tip;
	}
	void setMetodaAchizitie(string achizitie) {
		if (achizitie != "")
			this->achizitie = achizitie;
	}
	void setPret(float pret) {
		if (pret != 0)
			this->pret = pret;
	}
	void setEveniment(Eveniment e) {
		this->e = e;
	}

	//SUPRAINCARCARE operator - 
	Bilet operator-(int procent){
		this->pret = pret - pret * procent / 100;
		return *this;
	}

	//SUPRAINCARCARE operator /
	Bilet operator/(int valoare){
		this->pret = pret / valoare;
		return *this;
	}

	//METODA GENERICA: reducere de pret pt tip bilet
	void reducereTip() {
		if (tip == "elev" || tip == "student") pret = pret / 2;
		if (tip == "pensionar") pret = pret - pret * 40 / 100;
		if (tip == "copil")pret = 0;
	}

	//METODA GENERICA: reducere pret pt achizitie
	void reducereAchizitie() {
		if (achizitie == "online")pret = pret - pret * 10 / 100;
	}

	//SUPRAINCARCARE operatori << si >>
	friend ostream& operator<<(ostream& out, Bilet b) {
		out << "Id: " << b.id << endl;
		out << "Nume: " << b.nume<<endl;
		out << "Categorie: ";
		if (b.categorie!= nullptr){
			out << b.categorie;
		}
		out << endl;
		out<< "Rand: "<< b.rand <<endl;
		out << "Loc: "<< b.loc <<endl;
		out << "Tip bilet: " << b.tip << endl;
		out<<"Metoda de achizitie: "<< b.achizitie <<endl;
		out<<"Pret: "<<b.pret <<endl;

		return out;
	};
	friend istream& operator>>(istream& in, Bilet& b) {
		cout << "Nume: ";
		getline(in>>ws,b.nume);
		cout << endl << "Categorie: ";
		string buffer;
		in >> buffer;
		b.setCategorie(buffer.c_str());
		cout << endl << "Rand: ";
		in>> b.rand ;
		cout << endl << "Loc: ";
		in >> b.loc ;
		cout << endl << "Tip bilet (elev,student,pensionar,copil,adult): ";
		in >> b.tip ;	
		cout << endl << "Metoda de achizitie (fizic,online): ";
		in >> b.achizitie ;
		b.pret = 80;
		b.reducereTip();
		b.reducereAchizitie();
		cout << endl << "Pret: "<<b.pret;

		return in;
	};


};


