#pragma once
#include "Zwierze.h"
class Wilk :public Zwierze {
public:
	Wilk(Swiat& xswiat, POLOZENIE xwsp);
	Wilk(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek);
	//void akcja() override;
	//void kolizja() override;
	char rysowanie() override;
	void dodaj(POLOZENIE wsp) override;
 };