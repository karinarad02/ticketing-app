#pragma once
#include <iostream>
using namespace std;
#include <fstream>
#include <string>

class SalaEveniment {
private:

	int** locuriInSala;
	int maxRanduri;
	int maxLocuriPerRand;
	string categorii;
	int nrCategorii;

public:

	//CONSTRUCTOR FARA PARAMETRII
	SalaEveniment() {

		maxRanduri=10;
		maxLocuriPerRand=10;
		locuriInSala = new int* [maxRanduri];
		for (int i = 0; i < maxRanduri; i++) {
			locuriInSala[i] = new int[maxLocuriPerRand];
		}
		for (int i = 0; i <maxRanduri; i++) {
			for (int j = 0; j < maxLocuriPerRand; j++) {
				locuriInSala[i][j] = (i+1) * 10 + (j+1);
			}
		}
		categorii = "Normal";
		nrCategorii = 1;
	}

	//CONSTRUCTOR CU PARAMETRII
	SalaEveniment(int maxRanduri,int maxLocuriPerRand, string categorii,int nrCategorii):SalaEveniment() {
		
		if (maxRanduri != 0 && maxLocuriPerRand != 0) {
			this->maxRanduri = maxRanduri;
			this->maxLocuriPerRand = maxLocuriPerRand;
			locuriInSala = new int* [maxRanduri];
			for (int i = 0; i < maxRanduri; i++) {
				locuriInSala[i] = new int[maxLocuriPerRand];
			}
			for (int i = 0; i < maxRanduri; i++) {
				for (int j = 0; j < maxLocuriPerRand; j++) {
					locuriInSala[i][j] = (i + 1) * 10 + (j + 1);
				}
			}
		}
		if(categorii!=""&&nrCategorii!=0){
			this->categorii = categorii;
			this->nrCategorii = nrCategorii;
		}
		
	}

	//CONSTRUCTOR DE COPIERE
	SalaEveniment(const SalaEveniment& se){
		if (se.locuriInSala != nullptr)
		{
			if (se.maxRanduri != 0 && se.maxLocuriPerRand != 0) {
				this->maxRanduri = se.maxRanduri;
				this->maxLocuriPerRand = se.maxLocuriPerRand;
			}
			this->locuriInSala = new int* [se.maxRanduri];
			for (int i = 0; i < se.maxRanduri; i++)
			{
				this->locuriInSala[i] = new int[se.maxLocuriPerRand];
			}
			for (int i = 0; i < se.maxRanduri; i++)
				for (int j = 0; j < (se.maxLocuriPerRand); j++)
					this->locuriInSala[i][j] = se.locuriInSala[i][j];
		}
		else this->locuriInSala = nullptr;
		if (se.nrCategorii != 0) {
			this->nrCategorii = se.nrCategorii;
			if (se.categorii != "") {
				this->categorii = se.categorii;
			}
		}
	}

	//DESTRUCTOR
	~SalaEveniment() {

		if (locuriInSala != nullptr) {
			for (int i = 0; i < maxRanduri; i++) {
				delete[] locuriInSala[i];
			}
			delete[]locuriInSala;
			locuriInSala = nullptr;
		}
	}

	//SUPRAINCARCARE OPERATOR =
	SalaEveniment& operator=(const SalaEveniment& se){
		if (this != &se)
		{
			if (se.locuriInSala != nullptr) {
				if (locuriInSala != nullptr) {
					for (int i = 0; i < maxRanduri; i++) {
						delete[]locuriInSala[i];
					}
					delete[]locuriInSala;
					locuriInSala = nullptr;
				}
				locuriInSala = new int* [se.maxRanduri];
				for (int i = 0; i < se.maxRanduri; i++) {
					locuriInSala[i] = new int[se.maxLocuriPerRand];
				}
				for (int i = 0; i < se.maxRanduri; i++) {
					for (int j = 0; j < se.maxLocuriPerRand; j++) {
						locuriInSala[i][j] = se.locuriInSala[i][j];
					}
				}
				maxRanduri = se.maxRanduri;
				maxLocuriPerRand = se.maxLocuriPerRand;
			}
			if (se.nrCategorii != 0) {
				this->nrCategorii = se.nrCategorii;
				if (se.categorii != "") {
					this->categorii = se.categorii;

				}
			}
		}
		return *this;
	}

	//GETTERI
	int** getLocuriInSala() {
		int** copie = new int* [maxRanduri];
		for (int i = 0; i < maxRanduri; i++) {
			copie[i] = new int[maxLocuriPerRand];
		}
		for (int i = 0; i < maxRanduri; i++) {
			for (int j = 0; j < maxLocuriPerRand; j++) {
				copie[i][j] = locuriInSala[i][j];
			}
		}
		return copie;
	}
	const int getMaxRanduri() {
		return maxRanduri;
	}
	const int getMaxLocuri() {
		return maxLocuriPerRand;
	}
	string getCategorii() {
		return categorii;
	}
	int getNrCategorii() {
		return nrCategorii;
	}
	//SETTERI
	void setLocuriInSala(const int**locuriInSala) {
		if (locuriInSala != nullptr&& maxRanduri!=0&&maxLocuriPerRand!=0) {
			for (int i = 0; i < maxRanduri; i++) {
				for (int j = 0; j < maxLocuriPerRand; j++) {
					this->locuriInSala[i][j] = locuriInSala[i][j];
				}
			}
		}
	}
	void setMaxRanduri(int randuri) {
		maxRanduri = randuri;
		//refacem matricea
		for (int i = 0; i < maxRanduri; i++) {
			delete[]locuriInSala[i];
		}
		delete[]locuriInSala;
		locuriInSala = new int* [maxRanduri];
		for (int i = 0; i < maxRanduri; i++) {
			locuriInSala[i] = new int[maxLocuriPerRand];
		}
		for (int i = 0; i < maxRanduri; i++) {
			for (int j = 0; j < maxLocuriPerRand; j++) {
				locuriInSala[i][j] = (i + 1) * 10 + (j + 1);
			}
		}
	}
	void setMaxLocuri(int locuri) {
		maxLocuriPerRand = locuri;
		//refacem matricea
		for (int i = 0; i < maxRanduri; i++) {
			delete[]locuriInSala[i];
		}
		delete[]locuriInSala;
		locuriInSala = new int* [maxRanduri];
		for (int i = 0; i < maxRanduri; i++) {
			locuriInSala[i] = new int[maxLocuriPerRand];
		}
		for (int i = 0; i < maxRanduri; i++) {
			for (int j = 0; j < maxLocuriPerRand; j++) {
				locuriInSala[i][j] = (i + 1) * 10 + (j + 1);
			}
		}
	}
	void setCategorii(string categorii,int nrCategorii) {
		if (nrCategorii != 0) {
			this->nrCategorii = nrCategorii;
			if (categorii != "") {
				this->categorii = categorii;
			}
		}
	}

	//SUPRAINCARCARE operator + (pentru marirea numarului de locuri in sala)
	SalaEveniment operator+(int val){

		for (int i = 0; i < maxRanduri; i++) {
			delete[]locuriInSala[i];
		}
		delete[]locuriInSala;
		locuriInSala = nullptr;
		maxRanduri += val;
		maxLocuriPerRand += val;
		locuriInSala = new int* [maxRanduri];
		for (int i = 0; i < maxRanduri; i++) {
			locuriInSala[i] = new int[maxLocuriPerRand];
		}
		for (int i = 0; i < maxRanduri; i++) {
			for (int j = 0; j < maxLocuriPerRand; j++) {
				locuriInSala[i][j] = (i + 1) * 10 + (j + 1);
			}
		}

		return *this;
	}
	friend SalaEveniment operator+(int val, SalaEveniment se)
	{

		for (int i = 0; i < se.maxRanduri; i++) {
			delete[]se.locuriInSala[i];
		}
		delete[]se.locuriInSala;
		se.locuriInSala = nullptr;
		se.maxRanduri += val;
		se.maxLocuriPerRand += val;
		se.locuriInSala = new int* [se.maxRanduri];
		for (int i = 0; i < se.maxRanduri; i++) {
			se.locuriInSala[i] = new int[se.maxLocuriPerRand];
		}
		for (int i = 0; i < se.maxRanduri; i++) {
			for (int j = 0; j < se.maxLocuriPerRand; j++) {
				se.locuriInSala[i][j] = (i + 1) * 10 + (j + 1);
			}
		}
		return se;
	}


	//SUPRAINCARCARE operator -- (pentru micsorarea numarului de locuri in sala)
	SalaEveniment& operator--() {

		for (int i = 0; i < maxRanduri; i++) {
			delete[]locuriInSala[i];
		}
		delete[]locuriInSala;
		locuriInSala = nullptr;
		maxRanduri--;
		maxLocuriPerRand--;
		locuriInSala = new int* [maxRanduri];
		for (int i = 0; i < maxRanduri; i++) {
			locuriInSala[i] = new int[maxLocuriPerRand];
		}
		for (int i = 0; i < maxRanduri; i++) {
			for (int j = 0; j < maxLocuriPerRand; j++) {
				locuriInSala[i][j] = (i + 1) * 10 + (j + 1);
			}
		}

		return *this;
	}
	SalaEveniment operator--(int x)
	{
		SalaEveniment copie = *this;
		maxRanduri--;
		maxLocuriPerRand--;
		locuriInSala = new int* [maxRanduri];
		for (int i = 0; i < maxRanduri; i++) {
			locuriInSala[i] = new int[maxLocuriPerRand];
		}
		for (int i = 0; i < maxRanduri; i++) {
			for (int j = 0; j < maxLocuriPerRand; j++) {
				locuriInSala[i][j] = (i + 1) * 10 + (j + 1);
			}
		}
		return copie;
	}
	
	//METODA GENERICA: scoatere categorie
	void scoateCategorie(string categorie) {
		
		int pos = categorii.find(categorie);
		string part1 = categorii.substr(0, pos);
		string part2 = categorii.substr(pos + categorie.length()+1);
		categorii = part1 + part2;
		nrCategorii--;
	}

	//METODA GENERICA: adaugare categorie
	void adaugaCategorie(string categorie) {
		if (categorie != "") {
			categorii =categorii +" "+ categorie;
			nrCategorii++;
		}
	}

	//METODE VIRTUALE
	virtual void afisareLocuri() {
		cout << "Capacitate Sala:  randuri:" << this->getMaxRanduri() 
			<<"locuri pe rand: "<<this->getMaxLocuri() <<endl;
		cout << "Locuri in Sala: " << this->getLocuriInSala() << endl;
	}
	virtual void afisareCategorii() {
		cout << "numar de Categorii: " << this->getNrCategorii() << endl;
		cout << "Categorii disponibile: " << this->getCategorii() << endl;
	}

	//SUPRAINCARCARE operatori << si >>
	friend ostream& operator<<(ostream& out, SalaEveniment se) {
		
		out << endl;
		out << "Randuri: " << se.maxRanduri << endl;
		out << "Locuri per rand: " << se.maxLocuriPerRand << endl;
		out << "Locuri in sala: " << endl;
		for (int i = 0; i < se.maxRanduri; i++) {
			out << "  " << i+1;
		}
		out << endl;
		if (se.locuriInSala != nullptr) {
			for (int i = 0; i < se.maxRanduri; i++) {
				out << i+1 << ' ';
				for (int j = 0; j < se.maxLocuriPerRand; j++) {
					out << se.locuriInSala[i][j];
					out << " ";
				}
				out << endl;
			}
		}
		out << "Categorii: " << se.categorii << endl;
		out << "Numar de categorii: " << se.nrCategorii << endl;
		return out;

	};
	friend ofstream& operator<<(ofstream& out, SalaEveniment se) {

		out << se.maxRanduri << endl;
		out << se.maxLocuriPerRand << endl;
		if (se.locuriInSala != nullptr) {
			for (int i = 0; i < se.maxRanduri; i++) {
				for (int j = 0; j < se.maxLocuriPerRand; j++) {
					out << se.locuriInSala[i][j];
					out << " ";
				}
				out << endl;
			}
		}
		out << se.categorii << endl;
		out << se.nrCategorii << endl;
		return out;

	};
	friend istream& operator>>(istream& in, SalaEveniment& se) {

		cout << "Randuri: ";
		in >> se.maxRanduri;
		cout << endl << "Locuri per rand: ";
		in >> se.maxLocuriPerRand;
		//locurile se genereaza automat
		int** locuriInSala = new int* [se.maxRanduri];
		for (int i = 0; i < se.maxRanduri; i++) {
			se.locuriInSala[i] = new int[se.maxLocuriPerRand];
		}
		for (int i = 0; i < se.maxRanduri; i++) {
			for (int j = 0; j < se.maxLocuriPerRand; j++) {
				se.locuriInSala[i][j] = (i + 1) * 10 + (j + 1);
			}
		}
		cout << endl << "Categorii(Introduceti categoriile cu spatii intre ele): ";
		getline(in>>ws,se.categorii);
		cout << endl << "Numar de categorii: ";
		in >> se.nrCategorii;

		return in;
	};
	friend ifstream& operator>>(ifstream& in, SalaEveniment& se) {

		in >> se.maxRanduri;
		in >> se.maxLocuriPerRand;
		//locurile se genereaza automat
		int** locuriInSala = new int* [se.maxRanduri];
		for (int i = 0; i < se.maxRanduri; i++) {
			se.locuriInSala[i] = new int[se.maxLocuriPerRand];
		}
		for (int i = 0; i < se.maxRanduri; i++) {
			for (int j = 0; j < se.maxLocuriPerRand; j++) {
				in >> se.locuriInSala[i][j];
			}
		}
		getline(in >> ws, se.categorii);
		in >> se.nrCategorii;

		return in;
	};

};