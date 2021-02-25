#pragma once
#include "Organizm.h"

class Zwierze :public Organizm {
	
public:
	//Zwierze(Swiat& xswiat, POLOZENIE xwsp);
	Zwierze(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek);
	void akcja() override;
	KIERUNEK losujKierunek(Organizm* org);
	void kolizja(Organizm& atakujacy) override;
	//void rysowanie() override;
	bool czyOdbilAtak(Organizm& atakujacy) override;
	void ruch(Organizm* org, KIERUNEK gdzie);
	bool czyWolne(KIERUNEK gdzie, int zasieg);
	void rozmnoz(KIERUNEK gdzie);
	virtual void dodaj(POLOZENIE wsp) = 0;
	
	

};
