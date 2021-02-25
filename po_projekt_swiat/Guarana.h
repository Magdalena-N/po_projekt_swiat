#pragma once
#include "Roslina.h"
class Guarana :public Roslina {
public:
	Guarana(Swiat& xswiat, POLOZENIE xwsp);
	Guarana(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek);

	char rysowanie() override;
	
	void dodaj(POLOZENIE wsp) override;
	void kolizja(Organizm& atakujacy) override;
};
