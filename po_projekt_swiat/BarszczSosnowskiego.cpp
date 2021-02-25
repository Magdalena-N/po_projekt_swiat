#include "BarszczSosnowskiego.h"

BarszczSosnowskiego::BarszczSosnowskiego(Swiat& xswiat, POLOZENIE xwsp)
	:Roslina(xswiat, xwsp) {
}
BarszczSosnowskiego::BarszczSosnowskiego(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek)
	: Roslina(xswiat, xsila, xinicjatywa, xwsp, xwiek) {

}

char BarszczSosnowskiego::rysowanie() {
	return BARSZCZ;
}

void BarszczSosnowskiego::dodaj(POLOZENIE wsp) {
	swiat.dodajOrganizm(new BarszczSosnowskiego(swiat, wsp), wsp);
}


void BarszczSosnowskiego::kolizja(Organizm& atakujacy) {

	swiat.dodajOrganizm(NULL, atakujacy.getWsp());
	string temp = "";
	temp += atakujacy.rysowanie();
	temp += " zjadl ";
	temp += this->rysowanie();
	temp += " i umarl.";
	swiat.setKomunikat(temp);
}

void BarszczSosnowskiego::akcja() {
	POLOZENIE pozycja = this->getWsp();

	if (pozycja.y != 0 && czyWolne(GORA) == false &&  (*swiat.getOrganizm({ pozycja.x,pozycja.y - 1 }))->rysowanie() != this->rysowanie()){
		swiat.dodajOrganizm(NULL, { pozycja.x,pozycja.y - 1 });
	}

	if (pozycja.y != SIZE - 1 && czyWolne(DOL) == false &&  (*swiat.getOrganizm({ pozycja.x,pozycja.y + 1 }))->rysowanie() != this->rysowanie()) {
		swiat.dodajOrganizm(NULL, { pozycja.x,pozycja.y + 1 });
	}

	if (pozycja.x != 0 && czyWolne(LEWO) == false &&  (*swiat.getOrganizm({ pozycja.x - 1,pozycja.y }))->rysowanie() != this->rysowanie()) {
		swiat.dodajOrganizm(NULL, { pozycja.x - 1,pozycja.y });
	}
	if (pozycja.x != SIZE - 1 && czyWolne(PRAWO) == false &&  (*swiat.getOrganizm({ pozycja.x + 1,pozycja.y}))->rysowanie() != this->rysowanie()) {
		swiat.dodajOrganizm(NULL, { pozycja.x + 1 ,pozycja.y });
	}
	Roslina::akcja();
	
}