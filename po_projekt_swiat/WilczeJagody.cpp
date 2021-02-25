#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(Swiat& xswiat, POLOZENIE xwsp)
	:Roslina(xswiat, xwsp) {
}
WilczeJagody::WilczeJagody(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek)
	: Roslina(xswiat, xsila, xinicjatywa, xwsp, xwiek) {

}

char WilczeJagody::rysowanie() {
	return JAGODY;
}

void WilczeJagody::dodaj(POLOZENIE wsp) {
	swiat.dodajOrganizm(new WilczeJagody(swiat, wsp), wsp);
}

void WilczeJagody::kolizja(Organizm& atakujacy) {
	atakujacy.setIstnieje(false);
	swiat.dodajdoUsuniecia(&atakujacy);
	swiat.dodajOrganizm(NULL, atakujacy.getWsp());
	string temp = "";
	temp += atakujacy.rysowanie();
	temp += " zjadl ";
	temp += this->rysowanie();
	temp += " i umarl.";
	swiat.setKomunikat(temp);
}