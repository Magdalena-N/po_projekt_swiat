#pragma once
#include "Zwierze.h"



 class Owca :public Zwierze {
public:
	Owca(Swiat& xswiat, POLOZENIE xwsp);
	Owca(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek);
	
	char rysowanie() override;
	void dodaj(POLOZENIE wsp) override;
};
