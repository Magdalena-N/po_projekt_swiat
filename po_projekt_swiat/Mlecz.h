#pragma once
#include "Roslina.h"
class Mlecz :public Roslina {
public:
	Mlecz(Swiat& xswiat, POLOZENIE xwsp);
	Mlecz(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek);

	char rysowanie() override;
	void dodaj(POLOZENIE wsp) override;
	void akcja() override;
};
