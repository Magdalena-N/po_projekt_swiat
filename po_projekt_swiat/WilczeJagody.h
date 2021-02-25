#pragma once
#include "Roslina.h"
class WilczeJagody :public Roslina {
public:
	WilczeJagody(Swiat& xswiat, POLOZENIE xwsp);
	WilczeJagody(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek);

	char rysowanie() override;
	void dodaj(POLOZENIE wsp) override;
	void kolizja(Organizm& atakujacy) override;
};
