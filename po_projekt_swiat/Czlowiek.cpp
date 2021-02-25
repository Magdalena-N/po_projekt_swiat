#include"Czlowiek.h"


Czlowiek::Czlowiek(Swiat& xswiat,POLOZENIE xwsp)
	: Zwierze(xswiat, 5,4, xwsp,0) {
	swiat.setCzlowiekZyje(true);
	this->czekaj = 0;
	this->pozostalyEliksir = 0;
}
Czlowiek::Czlowiek(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek)
	: Zwierze(xswiat, xsila, xinicjatywa, xwsp, xwiek) {
	swiat.setCzlowiekZyje(true);
	this->czekaj = 0;
	this->pozostalyEliksir = 0;
}
void Czlowiek::akcja() {
	if (this->getUmiejetnosc() == true) {
		this->uzyjUmiejetnosci();
		this->setUmiejetnosc(false);
	}
	Zwierze::akcja();
	if (*(swiat.getOrganizm(this->getWsp())) == NULL) {
		swiat.setCzlowiekZyje(false);
	}
	if (czekaj != 0) {
		czekaj--;
	}
	if (pozostalyEliksir > 0) {
		pozostalyEliksir--;
		this->setSila((this->getSila()) - 1);
		if (pozostalyEliksir == 0) {

			czekaj = 5;
		}
	}
	
	
}
void Czlowiek::kolizja(Organizm& atakujacy) {
	Zwierze::kolizja(atakujacy);
	
	if (*(swiat.getOrganizm(this->getWsp())) == NULL) {
		swiat.setCzlowiekZyje(false);
	}

	/*if (!(this->getSwiat()->czyIstnieje((this->getSwiat()->getOrganizm(this->getWsp()))))) {
		atakujacy.getSwiat()->setCzlowiekZyje(false);
	}*/
}

char Czlowiek::rysowanie() {
	return CZLOWIEK;
}
void Czlowiek::dodaj(POLOZENIE wsp) {
	swiat.dodajOrganizm(new Czlowiek(swiat, wsp), wsp);
}

void Czlowiek::uzyjEliksiru() {
	swiat.setKomunikat("Czlowiek wypil eliksir");
	
	this->setSila(this->getSila() + 10);
	pozostalyEliksir = 5;
	
}
void Czlowiek::uzyjUmiejetnosci() {
	if (czekaj == 0) {
		uzyjEliksiru();
	}
}
int Czlowiek::getCzekaj() {
	return czekaj;
}

