#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <fstream>
#include <string>
#pragma warning (disable:4996)
#include "Eveniment.h"
#include "EvenimentPrivat.h"
#include "SalaEveniment.h"
#include "MetodaAccesEveniment.h"
#include "Bilet.h"

int Bilet::nrTotalBilete = 1;


void afisareEvenimente(string locatie) {

	int exista = 0;
	ifstream g;
	g.open("evenimente.txt", ios::in);
	Eveniment e;
	int i = 1;
	while(g >> e){
		if (e.getLocatie() == locatie) {
			if (exista == 0) {
				cout << "\t\t\t\tAlegeti evenimentul la care doriti sa participati: " << endl
					<< endl << "\t\t\t\t  ***********************  " << endl
					<< "In locatia "<< locatie <<" au loc:" << endl;
			}
			exista = 1;
			cout<<"===============" << i << "================" << endl << e << endl;
			i++;
		}
	}
	g.close();
	ifstream h;
	h.open("evenimentePrivate.txt", ios::in);
	EvenimentPrivat ep;
	while (h >> ep) {
		if (ep.getLocatie() == locatie) {
			if (exista != 2)cout << "In locatia" << locatie << "sunt si evenimente private:" << endl;
			exista = 2;
			cout << "\t\t\t\t" << i << "=> " << endl << ep << endl;
			i++;
		}
	}
	h.close();
}

void Init() {

	cout << "\t\t\t\tAlegeti la ce tip de eveniment doriti sa participati: " << endl
		<< endl << "\t\t\t\t  ***********************  " << endl
		<< "\t\t\t\t================================" << endl
		<< "\t\t\t\t Locuri in care au loc Evenimente" << endl
		<< "\t\t\t\t================================" << endl
		<< "\t\t\t\tMeniu: " << endl
		<< "\t\t\t\t1 => Stadion" << endl
		<< "\t\t\t\t2 => Teatru" << endl
		<< "\t\t\t\t3 => Cinema" << endl;

	int optiune;
	string locatie;
	do {
		cout << endl << "\t\t\t\tVa rugam selectati una dintre optiunile de mai sus: ";
		cin >> optiune;
		switch (optiune)
		{
		case 1:
			locatie="Stadion";
			break;
		case 2:
			locatie ="Teatru";
			break;
		case 3:
			locatie = "Cinema";
			break;
		default:
			cout << "\t\t\t\tVa rugam selectati una dintre optiunile de mai sus:" << endl
				<< "\t\t\t\t===================================================" << endl;
			cin.ignore();
		}
	} while (optiune != 1 && optiune != 2 && optiune != 3);

	afisareEvenimente(locatie);

	cout << endl << "\t\t\t\tVa rugam evenimentul care va intereseaza(introduceti numarul aferent): ";
	cin >> optiune;
	ifstream g;
	g.open("evenimente.txt", ios::in);
	Eveniment evAles;
	int i = 1;
	while (g >> evAles) {
		if (evAles.getLocatie() == locatie && i == optiune) {
			break;
		}
		i++;
	}
	g.close();

	cout << endl << "\t\t\t\tAlegeti o actiune pe care doriti sa o faceti: " << endl
		<< endl << "\t\t\t\t  ***********************  " << endl
		<< "\t\t\t\t================================" << endl
		<< "\t\t\t\t Actiuni posibile" << endl
		<< "\t\t\t\t================================" << endl
		<< "\t\t\t\tMeniu: " << endl
		<< "\t\t\t\t1 => Cumpara bilet" << endl
		<< "\t\t\t\t2 => Inapoi la locatii" << endl;

	do {

		cout << endl << "\t\t\t\tVa rugam selectati una dintre optiunile de mai sus: ";
		cin >> optiune;
		switch (optiune)
		{

		case 1:
		{
			Bilet temp;
			cin >> temp;
			while (evAles.locOcupat(temp.getRand(), temp.getLoc())) {
				cout << "Locul ales este ocupat sau nu mai avem locuri disponibile" << endl <<
					"Va rugam verificati grila afisata anterior";
					cin >> temp;
			}
			Bilet b(temp.getNume(), temp.getCategorie(), temp.getRand(), temp.getLoc(), temp.getTipBilet(), temp.getMetodaAchizitie(), temp.getEveniment());
			evAles.ocupareLoc(b.getRand(), b.getLoc());
			ofstream f("bilete.bin", ios::binary);
			f.write((char*)&b, sizeof(b));
			f.close();

			cout <<endl<< "\t\t\t\tBilet rezervat cu succes!";
			break;
		}
		case 2:
			Init();
			break;

		default:

			cout << "Va rugam selectati una dintre optiunile de mai sus:" << endl
				<< "===================================================" << endl;
			cin.ignore();

		}
	} while (optiune != 1 && optiune != 2);
	
}

int main() {

	//Valori initiale
	
	/*SalaEveniment s1(10, 10, "Categoria1 Categoria2 Loja", 3);
	SalaEveniment s2(10, 10, "Normal VIP", 2);
	SalaEveniment s3(10, 10, "Normal VIP", 2);
	SalaEveniment s4(100, 100, "Tribuna1 Tribuna2", 2);
	SalaEveniment s5(10, 10, "Categoria1 Categoria2 Loja", 3);

	Eveniment e1("01.02.2002", 11, "Piesa1", "Teatru", s1);
	Eveniment e2("03.03.2003", 15, "Film1", "Cinema", s2);
	Eveniment e3("04.06.2006", 9, "Film2", "Cinema", s3);
	Eveniment e4("07.07.2009", 19, "Film1", "Stadion", s4);
	Eveniment e5("11.10.2013", 14, "Piesa2", "Teatru", s1);

	char* categorie1 = new char[strlen("Categoria1") + 1];
	strcpy(categorie1, "Categoria1");
	Bilet b1("Popescu", categorie1, 1, 1, "student", "fizic", e1);
	e1.ocupareLoc(1, 1);
	char* categorie2 = new char[strlen("Normal") + 1];
	strcpy(categorie2, "Normal");
	Bilet b2("Ionescu", categorie2, 2, 2, "elev", "fizic", e2);
	e2.ocupareLoc(2,2);
	char* categorie3 = new char[strlen("Tribuna2") + 1];
	strcpy(categorie3, "Tribuna2");
	Bilet b3("Ionescu", categorie3, 3, 3, "adult", "online", e4);
	Bilet b4("Ionescu", categorie3, 3, 4, "copil", "fizic", e4);
	e4.ocupareLoc(3,3);
	e4.ocupareLoc(3,4);
	char* categorie4 = new char[strlen("Loja") + 1];
	strcpy(categorie4, "Loja");
	Bilet b5("Frimescu", categorie4, 4, 4, "pensionar", "online", e5);
	e5.ocupareLoc(4,4);

	ofstream f("sali.txt");
	f << s1 << endl;
	f << s2 << endl;
	f << s3 << endl;
	f << s4 << endl;
	f << s5 << endl;
	f.close();
	
	ofstream g("evenimente.txt");
	g << e1<<endl;
	g << e2 << endl;
	g << e3 << endl;
	g << e4 << endl;
	g.close();

	ofstream j("evenimentePrivate.txt");
	j << e5 << endl;
	j.close();

	ofstream h("bilete.bin", ios::binary);
	h.write((char*)&b1, sizeof(b1));
	h.write((char*)&b2, sizeof(b2));
	h.write((char*)&b3, sizeof(b3));
	h.write((char*)&b4, sizeof(b4));
	h.write((char*)&b5, sizeof(b5));
	h.close();*/

	Init();
	
}