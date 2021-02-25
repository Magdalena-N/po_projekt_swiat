#pragma once
#include "Zwierze.h"
class Antylopa :public Zwierze {
public:
	Antylopa(Swiat& xswiat, POLOZENIE xwsp);
	Antylopa(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek);

	char rysowanie() override;
	void kolizja(Organizm& atakujacy) override;
	void ucieknij(Organizm* org, KIERUNEK gdzie);
	void dodaj(POLOZENIE wsp) override;
};
