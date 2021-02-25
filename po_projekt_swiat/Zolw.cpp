#include "Zolw.h"


Zolw::Zolw(Swiat& xswiat,POLOZENIE xwsp)
	: Zwierze(xswiat,2,1, xwsp, 0) {

}
Zolw::Zolw(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek)
	: Zwierze(xswiat, xsila, xinicjatywa, xwsp, xwiek) {

}

bool Zolw::czyOdbilAtak(Organizm& atakujacy) {
	if (this->rysowanie() == atakujacy.rysowanie()) {
		return false;
	}
	if (atakujacy.getSila() < 5) {
		return true;
	}
	else
		return false;
}

char Zolw::rysowanie() {
	return ZOLW;
}

void Zolw::akcja() {
	int temp = rand() % 100;
	if (temp < 25) {
		KIERUNEK gdzie;
		POLOZENIE wsp2 = this->getWsp();
		gdzie = losujKierunek(this);
		if (czyWolne(gdzie,this->getZasieg())) {
			ruch(this, gdzie);
		}
		else {
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

			(*(swiat.getOrganizm(wsp2)))->kolizja(*this);
			if (*(swiat.getOrganizm(this->getWsp())) != NULL && this->getOdbity() == false) {
				ruch(this, gdzie);

			}
			else if (*(swiat.getOrganizm(this->getWsp())) != NULL) {
				this->setOdbity(false);
			}

		
		}
	}
}
void Zolw::kolizja(Organizm& atakujacy) {

	if (czyOdbilAtak(atakujacy)) {
		string temp = "";
		temp += this->rysowanie();
		temp += " odbil atak ";
		temp += atakujacy.rysowanie();
		swiat.setKomunikat(temp);
		atakujacy.setOdbity(true);
	}
	else {
		Zwierze::kolizja(atakujacy);
	}


}
void Zolw::dodaj(POLOZENIE wsp) {
	swiat.dodajOrganizm(new Zolw(swiat, wsp), wsp);
}