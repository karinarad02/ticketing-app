#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "SalaEveniment.h"
#pragma warning (disable:4996)

class Eveniment {
private:
	string data;
	int ora;
	string denumire;
	string locatie;
	int** locuriOcupate;
	//liber-0 , ocupat-1
	SalaEveniment se;

public:

	//CONSTRUCTOR FARA PARAMETRII
	Eveniment() {
		data = "";
		ora = 0;
		denumire = "";
		locatie = "";
		locuriOcupate = new int* [se.getMaxRanduri()];
		for (int i = 0; i < se.getMaxRanduri(); i++) {
			locuriOcupate[i] = new int[se.getMaxLocuri()];
		}
		for (int i = 0; i < se.getMaxRanduri(); i++) {
			for (int j = 0; j < se.getMaxLocuri(); j++) {
				locuriOcupate[i][j] = 0;
			}
		}
		SalaEveniment se;
	}

	//CONSTRUCTOR CU PARAMETRII
	Eveniment(string data, int ora, string denumire, string locatie,SalaEveniment se):Eveniment() {
		if (data != "")this->data = data;
		if (ora != 0)this->ora = ora;
		if (denumire != "")this->denumire = denumire;
		if (locatie != "")this->locatie = locatie;
		this->locuriOcupate = new int* [se.getMaxRanduri()];
		for (int i = 0; i < se.getMaxRanduri(); i++) {
			this->locuriOcupate[i] = new int[se.getMaxLocuri()];
		}
		for (int i = 0; i < se.getMaxRanduri(); i++) {
			for (int j = 0; j < se.getMaxLocuri(); j++) {
				this->locuriOcupate[i][j] = 0;
			}
		}
		this->se = se;
	}

	//CONSTRUCTOR DE COPIERE
	Eveniment(const Eveniment& e){
		if (e.data != "")this->data = e.data;
		if (e.ora != 0)this->ora = e.ora;
		if (e.denumire != "")this->denumire = e.denumire;
		if (e.locatie != "")this->locatie = e.locatie;
		this->se = e.se;
		if (e.locuriOcupate != nullptr) {
			this->locuriOcupate = new int* [se.getMaxRanduri()];
			for (int i = 0; i < se.getMaxRanduri(); i++)
			{
				this->locuriOcupate[i] = new int[se.getMaxLocuri()];
			}
			for (int i = 0; i < se.getMaxRanduri(); i++) {
				for (int j = 0; j < (se.getMaxLocuri()); j++){
					this->locuriOcupate[i][j] = e.locuriOcupate[i][j];
				}
			}
		}
		else this->locuriOcupate = nullptr;
		
	}

	//DESTRUCTOR
	~Eveniment() {
		if (locuriOcupate != nullptr) {
			for (int i = 0; i < se.getMaxRanduri(); i++) {
				delete[] locuriOcupate[i];
			}
			delete[] locuriOcupate;
			locuriOcupate = nullptr;
		}
	}

	//SUPRAINCARCARE OPERATOR =
	Eveniment& operator=(const Eveniment& e){
		if (this != &e){
			if (e.data != "")this->data = e.data;
			if (e.ora != 0)this->ora = e.ora;
			if (e.denumire != "")this->denumire = e.denumire;
			if (e.locatie != "")this->locatie = e.locatie;
			if (this->locuriOcupate != nullptr) {
				for (int i = 0; i < se.getMaxRanduri(); i++) {
					delete[] this->locuriOcupate[i];
				}
				delete[]this->locuriOcupate;
			}
			this->se = e.se;
			if (e.locuriOcupate != nullptr){
				this->locuriOcupate = new int* [se.getMaxRanduri()];
				for (int i = 0; i < se.getMaxRanduri(); i++)
				{
					this->locuriOcupate[i] = new int[se.getMaxLocuri()];
				}
				for (int i = 0; i < se.getMaxRanduri(); i++) {
					for (int j = 0; j < se.getMaxLocuri(); j++) {
						this->locuriOcupate[i][j] = e.locuriOcupate[i][j];
					}
				}
			}
		}
		return *this;
	}

	//GETTERI
	string getData() {
		return data;
	}
	int getOra() {
		return ora;
	}
	string getDenumire() {
		return denumire;
	}
	string getLocatie() {
		return locatie;
	}
	int** getLocuriOcupate() {
		int** copie = new int* [se.getMaxRanduri()];
		for (int i = 0; i < se.getMaxRanduri(); i++)
		{
			copie[i] = new int[se.getMaxLocuri()];
		}
		for (int i = 0; i < se.getMaxRanduri(); i++) {
			for (int j = 0; j < se.getMaxLocuri(); j++) {
				copie[i][j] = this->locuriOcupate[i][j];
			}
		}
		return copie;
	}
	SalaEveniment getSalaEveniment() {
		return se;
	}
	//SETTERI
	void setData(string data) {
		if (data != "")
			this->data = data;
	}
	void setOra(int ora) {
		if (ora != 0)
			this->ora = ora;
	}
	void setDenumire(string denumire) {
		if (denumire != "")
			this->denumire = denumire;
	}
	void setLocatie(string locatie) {
		if (locatie != "")
			this->locatie = locatie;
	}
	void setLocuriOcupate(int** locuriOcupate) {
		if (locuriOcupate != nullptr) {
			for (int i = 0; i < se.getMaxRanduri(); i++) {
				for (int j = 0; j < se.getMaxLocuri(); j++) {
					this->locuriOcupate[i][j] = locuriOcupate[i][j];
				}
			}
		}
	}
	void setSalaEveniment(SalaEveniment se) {
		this->se = se;
	}

	// SUPRAINCARCARE operator[] (pentru returnarea unui loc anume)

	int* operator[](int index){
		if (locuriOcupate != nullptr && index >= 0 && (index < se.getMaxRanduri()|| index < se.getMaxRanduri()))
		{
			return locuriOcupate[index];
		}
		else
			throw exception("indexInvalid");
	}

	//SUPRAINCARCARE operator++ 
	Eveniment operator++() {
		ora++;
		return *this;
	}

	friend Eveniment operator++(Eveniment e) {
		e.ora++;
		return e;
	}

	//METODA GENERICA: ocupare loc
	void ocupareLoc(int rand, int loc) {
		if (locuriOcupate[rand][loc] == 0) locuriOcupate[rand][loc] = 1;
	}

	//METODA GENERICA: verificare loc daca e ocupat
	bool locOcupat(int rand, int loc){
		if (locuriOcupate[rand][loc] == 0)return true;
		return false;
	}

	//SUPRAINCARCARE operatori << si >>
	friend ostream& operator<<(ostream& out, Eveniment e) {
		out << "Data: " << e.data << endl;
		out << "Ora: " << e.ora << endl;
		out << "Denumire: " << e.denumire << endl;
		out << "Locatie: " << e.locatie << endl;
		out << "Locuri: "<<endl;
		if (e.locuriOcupate != nullptr){
			for (int i = 0; i < e.se.getMaxRanduri(); i++) {
				for (int j = 0; j < e.se.getMaxLocuri(); j++) {
					if (e.locuriOcupate[i][j] == 0) out << "liber"<< " ";
					else out << "ocupat";
				}
				out << endl;
			}
		}
		out << endl;
		return out;

	};
	friend istream& operator>>(istream& in, Eveniment& e) {

		cout << "Data: ";
		in >> e.data ;
		cout << endl << "Ora (Introduceti un o ora fixa - un numar intreg): ";
		in >> e.ora ;
		cout << endl << "Denumire: ";
		in >> e.denumire ;
		cout << endl << "Locatie (Introduceti adresa): ";
		getline(in >>ws, e.locatie);
		//locurile se genereaza automat
		int** locuriOcupate = new int* [e.se.getMaxRanduri()];
		for (int i = 0; i < e.se.getMaxRanduri(); i++) {
			e.locuriOcupate[i] = new int[e.se.getMaxLocuri()];
		}
		for (int i = 0; i < e.se.getMaxRanduri(); i++) {
			for (int j = 0; j < e.se.getMaxLocuri(); j++) {
				e.locuriOcupate[i][j] = 0;
			}
		}
		return in;
	};
	
};