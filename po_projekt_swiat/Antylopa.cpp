#include "Antylopa.h"

Antylopa::Antylopa(Swiat& xswiat, POLOZENIE xwsp)
	: Zwierze(xswiat, 4, 4, xwsp, 0) {
	this->setZasieg(2);
}
Antylopa::Antylopa(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek)
	: Zwierze(xswiat, xsila, xinicjatywa, xwsp, xwiek){
	this->setZasieg(2);
}

char Antylopa::rysowanie() {
	return ANTYLOPA;
}
void Antylopa::kolizja(Organizm& atakujacy) {

	int temp = rand() % 100;
	KIERUNEK gdzie;

	if (this->rysowanie() == atakujacy.rysowanie()) {
		gdzie = losujKierunek(this);
		rozmnoz(gdzie);
		string temp = "";
		temp += atakujacy.rysowanie();
		temp += " urodzily ";
		temp += this->rysowanie();
		swiat.setKomunikat(temp);
	}

	else if (temp < 50) {
		do {
			gdzie = losujKierunek(this);
		} while (!czyWolne(gdzie, 1));
		ucieknij(this, gdzie);
		string temp = "";
		temp += this->rysowanie();
		temp += " uciekla przed ";
		temp += atakujacy.rysowanie();
		swiat.setKomunikat(temp);
	}
	else {
		Zwierze::kolizja(atakujacy);
	}

}
void Antylopa::dodaj(POLOZENIE wsp) {
	swiat.dodajOrganizm(new Antylopa(swiat, wsp), wsp);
}
void Antylopa::ucieknij(Organizm* org, KIERUNEK gdzie) {
	POLOZENIE wsp1 = org->getWsp();
	POLOZENIE wsp2 = org->getWsp();
	

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
	org->setWsp(wsp2);
	swiat.dodajOrganizm(org, wsp2);
	swiat.dodajOrganizm(NULL, wsp1);
}