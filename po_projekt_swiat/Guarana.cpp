#include "Guarana.h"

Guarana::Guarana(Swiat& xswiat, POLOZENIE xwsp)
	:Roslina(xswiat, xwsp) {
}
Guarana::Guarana(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek)
	: Roslina(xswiat, xsila, xinicjatywa, xwsp, xwiek) {

}

char Guarana::rysowanie() {
	return GUARANA;
}

void Guarana::dodaj(POLOZENIE wsp) {
	swiat.dodajOrganizm(new Guarana(swiat, wsp), wsp);
}
void Guarana::kolizja(Organizm& atakujacy) {
	Roslina::kolizja(atakujacy);
	atakujacy.setSila(atakujacy.getSila() + 3);
}