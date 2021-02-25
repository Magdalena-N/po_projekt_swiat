#pragma once
#include "Roslina.h"
class Trawa :public Roslina {
public:
	Trawa(Swiat& xswiat, POLOZENIE xwsp);
	Trawa(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek);

	char rysowanie() override;
	//void akcja() override;
	void dodaj(POLOZENIE wsp) override;
};
