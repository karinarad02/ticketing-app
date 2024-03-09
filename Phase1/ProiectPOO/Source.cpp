#include <iostream>
using namespace std;
#include <string>
#pragma warning (disable:4996)
#include "Eveniment.h"
#include "SalaEveniment.h"
#include "Bilet.h"

int Bilet::nrTotalBilete = 1;

int main() {

	//SALAEVENIMENT
	//apelare costructor fara parametrii
	SalaEveniment s1;

	//apelare operator de citire
	SalaEveniment s2;
	cin >> s2;
	//apelare operator de afisare
	cout << endl << "Date despre sala 2: "<<endl<<s2<<endl;

	////apelare costructor cu parametrii
	SalaEveniment s3(5,5,"Categorie3 Categorie4 Categorie5", 2);
	cout << endl << "Date despre sala 3: " << endl << s3<<endl;

	//apelare operator de copiere
	SalaEveniment s4 = s3;

	//apelare operator=
	SalaEveniment s5;
	s5 = s3;
	cout << endl << "Date despre sala 4: " << endl << s5 << endl;

	//apelare getteri si setteri
	int** locuri = s3.getLocuriInSala();
	int nrRanduri = s3.getMaxRanduri();
	int nrLocuri = s3.getMaxLocuri();
	string categorii = s3.getCategorii();
	s4.setCategorii("Categorie6", 1);
	s4.setMaxRanduri(3);
	s4.setMaxLocuri(3);
	cout << s4<<endl;
	const int** matrice = new const int* [s3.getMaxRanduri()];
	for (int i = 0; i < s3.getMaxLocuri(); i++) {
		matrice[i] = new int[s3.getMaxLocuri()];
	}
	
	s4.setLocuriInSala(matrice);
	for (int i = 0; i < s3.getMaxRanduri(); i++) {
		delete[] matrice[i];
	}
	delete[]matrice;
	matrice = nullptr;

	//operator +
	s4 + 3;
	1 + s4;
	cout << s4 << endl;

	//operator--
	s4--;
	--s4;
	cout << s4 << endl;

	//metode generice
	s3.scoateCategorie("Categorie4");
	s3.adaugaCategorie("Categorie7");
	cout<<s3;
//-------------------------------------------------------------------------------
	//EVENIMENT
	//apelare costructor fara parametrii
	Eveniment e1;

	////apelare operator de citire
	Eveniment e2;
	cin >> e2;
	//apelare operator de afisare
	cout << endl << "Date despre evenimentul 2: " << endl << e2 << endl;

	//apelare costructor cu parametrii
	Eveniment e3("02.02.2002", 11, "Film1", "Cinema",s3);
	cout << endl << "Date despre evenimentul 3: " << endl << e3 << endl;

	//apelare operator de copiere
	Eveniment e4 = e3;
	cout << endl << "Date despre evenimentul 4: " << endl << e4 << endl;

	//apelare operator=
	Eveniment e5;       
	e5 = e3;
	cout << endl << "Date despre evenimentul 5: " << endl << e5 << endl;

	//getteri si setteri
	string data = e3.getData();
	int ora = e3.getOra();
	string denumire = e3.getDenumire();
	string locatie = e3.getLocatie();
	int** locuriOcupate = e3.getLocuriOcupate();

////-------------------------------------------------------------------------------
	//BILET
	//apelare costructor fara parametrii
	Bilet b1;

	//apelare operator de citire
	Bilet b2;
	cin >> b2;
	//apelare operator de afisare
	cout <<endl<< "Date despre biletul 2: " << endl << b2 << endl;

	//apelare costructor cu parametrii
	char* categorie = new char[strlen("Categorie3") + 1];
	strcpy(categorie, "Categorie3");
	Bilet b3("Ionescu", categorie, 2, 3, "student", "fizic",e3);
	//cout << endl << "Date despre biletul 3: " << endl << b3 << endl;

	//apelare operator de copiere
	Bilet b4 = b3;
	cout << endl << "Date despre biletul 4: " << endl << b4 << endl;
	b3 - 20;
	cout << b3<<endl;
	b3 / 3;
	cout << b3.getPret();

	//apelare operator=
	Bilet b5;
	b5 = b2;
	cout << endl << "Date despre biletul 5: " << endl << b5 << endl;
	
}