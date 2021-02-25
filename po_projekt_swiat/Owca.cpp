#include "Owca.h"
Owca::Owca(Swiat& xswiat, POLOZENIE xwsp)
	:Zwierze(xswiat, 4, 4, xwsp, 0) {

}
Owca::Owca(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek)
	: Zwierze(xswiat, xsila, xinicjatywa, xwsp,xwiek) {

}

char Owca::rysowanie() {
	return OWCA;
}

void Owca::dodaj(POLOZENIE wsp) {
	swiat.dodajOrganizm(new Owca(swiat, wsp), wsp);
}
