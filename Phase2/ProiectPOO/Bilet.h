#pragma once
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "Eveniment.h"
#include "MetodaAccesEveniment.h"

class Bilet : public MetodaAccesEveniment
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
		this->reducerePret();
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

	//SCRIERE IN FISIER
	void serialize()
	{
		ofstream f("bilete.bin", ios::binary);
		f.write((char*)&id, sizeof(id));

		short dim = this->nume.length();
		f.write((char*)&dim, sizeof(dim));
		f.write(nume.c_str(), dim + 1);

		dim = strlen(categorie);
		f.write((char*)&dim, sizeof(dim));
		f.write(categorie, dim + 1);

		f.write((char*)&rand, sizeof(rand));
		f.write((char*)&loc, sizeof(loc));

		dim = this->tip.length();
		f.write((char*)&dim, sizeof(dim));
		f.write(tip.c_str(), dim + 1);

		dim = this->achizitie.length();
		f.write((char*)&dim, sizeof(dim));
		f.write(achizitie.c_str(), dim + 1);

		f.write((char*)&nrTotalBilete, sizeof(nrTotalBilete));
		f.write((char*)&pret, sizeof(pret));

		f.close();
	}
	//CITIRE DIN FISIER
	void deserialize()
	{
		ifstream f("bilete.bin", ios::binary);
		f.read((char*)&id, sizeof(id));

		short dim = 0;
		f.read((char*)&dim, sizeof(dim));
		char* n = new char[dim + 1];
		f.read(n, dim + 1);
		nume = n;
		delete[] n;

		f.read((char*)&dim, sizeof(dim));
		char* m = new char[dim + 1];
		f.read(m, dim + 1);
		strcpy(categorie ,m);
		delete[] m;

		f.read((char*)&rand, sizeof(rand));
		f.read((char*)&loc, sizeof(loc));

		f.read((char*)&dim, sizeof(dim));
		char* p = new char[dim + 1];
		f.read(p, dim + 1);
		tip = p;
		delete[] p;

		f.read((char*)&dim, sizeof(dim));
		char* q = new char[dim + 1];
		f.read(q, dim + 1);
		achizitie = q;
		delete[] q;

		f.read((char*)&nrTotalBilete, sizeof(nrTotalBilete));
		f.read((char*)&pret, sizeof(pret));

		f.close();
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

	//FUNCTIE VIRTUALA SUPRADEFINITA
	void reducerePret() {
		this->reducereTip();
		this->reducereAchizitie();
	}

	//METODE VIRTUALE
	virtual void afisare() {
		cout << "Nume: " << this->nume << endl;
		cout << "Rand: " << this->rand << endl;
		cout << "Loc: " << this->loc << endl;
		cout << "Tip bilet: " << this->tip << endl;
		cout << "Pret: " << this->pret << endl;
	}
	virtual void event() {
		cout << this->e;
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
	friend ofstream& operator<<(ofstream& out, Bilet b) {
		out << b.id << endl;
		out << b.nume << endl;
		if (b.categorie != nullptr) {
			out << b.categorie;
		}
		out << endl;
		out << b.rand << endl;
		out << b.loc << endl;
		out << b.tip << endl;
		out << b.achizitie << endl;
		out << b.pret << endl;
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
	friend ifstream& operator>>(ifstream& in, Bilet& b) {
		getline(in >> ws, b.nume);
		string buffer;
		in >> buffer;
		b.setCategorie(buffer.c_str());
		in >> b.rand;
		in >> b.loc;
		in >> b.tip;
		in >> b.achizitie;
		b.pret = 80;
		b.reducereTip();
		b.reducereAchizitie();

		return in;
	};


};


