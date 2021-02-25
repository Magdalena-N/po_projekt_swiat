#include "Lis.h"

Lis::Lis(Swiat& xswiat, POLOZENIE xwsp)
	: Zwierze(xswiat,3 ,7, xwsp, 0) {
}

Lis::Lis(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek)
	: Zwierze(xswiat, xsila, xinicjatywa, xwsp, xwiek) {

}

char Lis::rysowanie() {
	return LIS;
}
void Lis::akcja() {
	KIERUNEK gdzie;
	int szukaj = 1;
	POLOZENIE wsp2;
	Organizm** org;
	do {
		gdzie = losujKierunek(this);
		wsp2 = this->getWsp();
		switch (gdzie) {
		case GORA:
			wsp2.y--;
			break;
		case DOL:
			wsp2.y++;
			break;
		case LEWO:
			wsp2.x--;
			break;
		case PRAWO:
			wsp2.x++;
			break;
		default:
			break;
		}
		if (czyWolne(gdzie,this->getZasieg())) {
			ruch(this, gdzie);
			szukaj = 0;
		}
		else {
			org = swiat.getOrganizm(wsp2);
			if ((*org)->getSila() <= this->getSila()) {
				szukaj = 0;
				(*(swiat.getOrganizm(wsp2)))->kolizja(*this);
				if (*(swiat.getOrganizm(this->getWsp())) != NULL && this->getOdbity() == false) {
					ruch(this, gdzie);
				}
				else if (*(swiat.getOrganizm(this->getWsp())) != NULL) {
					this->setOdbity(false);
				}
				
			}
			
		}
	} while (szukaj == 1);
}

void Lis::dodaj(POLOZENIE wsp) {

	swiat.dodajOrganizm(new Lis(swiat, wsp), wsp);

}