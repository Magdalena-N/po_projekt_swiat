#pragma once
#include<Windows.h>
#include<iostream>
#include <conio.h> //obsluga klawiatury
#include<vector>
#include "stale.h"

using namespace std;



class Swiat;

class Organizm {
private:
	int sila;
	int inicjatywa;
	POLOZENIE wsp;
	char symbol;
	Swiat* swiat;
protected:
	friend Swiat;
public:
	Organizm();
	Organizm(int xsila, int xinicjatywa, POLOZENIE xwsp, char xsymbol);
	Organizm(Swiat* swiat,int xsila, int xinicjatywa, POLOZENIE xwsp, char xsymbol);
	virtual void akcja() = 0; //okreœla zachowanie organizmu w trakcie tury,
	virtual void kolizja() = 0; // okreœla zachowanie organizmu w trakcie kontaktu / zderzenia z innym organizmem,
	virtual void rysowanie() = 0; //powoduje narysowanie symbolicznej reprezentacji organizmu
	virtual bool czyOdbilAtak(Organizm& atakujacy) = 0;
};

class Swiat {
private:
	vector<vector<Organizm*>> worganizmy;
	vector<Organizm*>organizmy;
public:
	Organizm*** swiat;
	Swiat();
	void wykonajTure();
	void rysujSwiat();
	void dodajOrganizm(Organizm* organ);
	~Swiat();
};
