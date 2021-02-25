#include "Mlecz.h"

Mlecz::Mlecz(Swiat& xswiat, POLOZENIE xwsp)
	:Roslina(xswiat, xwsp) {
}
Mlecz::Mlecz(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek)
	: Roslina(xswiat, xsila, xinicjatywa, xwsp, xwiek) {

}

char Mlecz::rysowanie() {
	return MLECZ;
}

void Mlecz::dodaj(POLOZENIE wsp) {
	swiat.dodajOrganizm(new Mlecz(swiat, wsp), wsp);
}
void Mlecz::akcja() {
	for (int i = 0; i < 3; i++) {
		Roslina::akcja();
	}
}