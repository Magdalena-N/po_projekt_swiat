#pragma once
#include "Zwierze.h"
class Zolw :public Zwierze {
public:
	Zolw(Swiat& xswiat, POLOZENIE xwsp);
	Zolw(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek);

	char rysowanie() override;
	void akcja() override;
	bool czyOdbilAtak(Organizm& atakujacy) override;
	void kolizja(Organizm& atakujacy);
	void dodaj(POLOZENIE wsp) override;
};
