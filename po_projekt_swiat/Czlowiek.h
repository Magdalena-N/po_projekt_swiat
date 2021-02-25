#pragma once
#include "Zwierze.h"
class Czlowiek :public Zwierze {
private:
	//void uzyjEliksiru();
	//int ileEliksiruZostalo;
	int czekaj;
	int pozostalyEliksir;
public:
	Czlowiek(Swiat& xswiat, POLOZENIE xwsp);
	Czlowiek(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek);

	void akcja() override;
	void uzyjEliksiru();
	void kolizja(Organizm& atakujacy) override;
	char rysowanie() override;
	void dodaj(POLOZENIE wsp) override;
	void uzyjUmiejetnosci();
	int getCzekaj();
	
};
