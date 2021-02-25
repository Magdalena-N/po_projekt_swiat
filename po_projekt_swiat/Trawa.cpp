#include "Trawa.h"

Trawa::Trawa(Swiat& xswiat, POLOZENIE xwsp)
	:Roslina(xswiat, xwsp) {
}
Trawa::Trawa(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek)
	: Roslina(xswiat, xsila, xinicjatywa, xwsp, xwiek) {

}

char Trawa::rysowanie() {
	return TRAWA;
}

void Trawa::dodaj(POLOZENIE wsp) {
	swiat.dodajOrganizm(new Trawa(swiat, wsp), wsp);
}