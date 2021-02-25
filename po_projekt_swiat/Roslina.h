#pragma once
#include "Organizm.h"

class Roslina :public Organizm {

public:
	Roslina(Swiat& xswiat, POLOZENIE xwsp);
	Roslina(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek);
	void akcja() override;
	KIERUNEK losujKierunek(Organizm* org);
	void kolizja(Organizm& atakujacy) override;
	char rysowanie() override;
	bool czyOdbilAtak(Organizm& atakujacy) override;
	void zasiej(Organizm* xorg,KIERUNEK gdzie);
	virtual void dodaj(POLOZENIE wsp) = 0 ;
	bool czyWolne(KIERUNEK gdzie);
};
