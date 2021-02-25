#pragma once
#include "Roslina.h"
class BarszczSosnowskiego :public Roslina {
public:
	BarszczSosnowskiego(Swiat& xswiat, POLOZENIE xwsp);
	BarszczSosnowskiego(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek);

	char rysowanie() override;
	void dodaj(POLOZENIE wsp) override;
	void kolizja(Organizm& atakujacy) override;
	void akcja() override;
};
