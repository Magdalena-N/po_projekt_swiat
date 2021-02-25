#pragma once
#include "Zwierze.h"
class Lis :public Zwierze {
public:
	Lis(Swiat& xswiat, POLOZENIE xwsp);
	Lis(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek);

	char rysowanie() override;
	void akcja() override;
	void dodaj(POLOZENIE xwsp) override;
};
