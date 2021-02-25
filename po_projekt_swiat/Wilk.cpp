#include "Wilk.h"

Wilk::Wilk(Swiat& xswiat, POLOZENIE xwsp)
	: Zwierze(xswiat, 9,5, xwsp, 0) {

}
Wilk::Wilk(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek)
	:Zwierze(xswiat,xsila, xinicjatywa, xwsp, xwiek) {
	
}

//void Wilk::akcja() {}
//void Wilk::kolizja() {}
char Wilk::rysowanie() {
	return WILK;
}
void Wilk::dodaj(POLOZENIE wsp) {
	swiat.dodajOrganizm(new Wilk(swiat, wsp), wsp);
}