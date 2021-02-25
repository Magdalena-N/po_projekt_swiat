#include "Organizm.h"
//
//Organizm::Organizm(){
//
//}
//Organizm::Organizm(int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek) {
//	this->sila = xsila;
//	this->inicjatywa = xinicjatywa;
//	this->wsp = xwsp;
//	this->wiek = xwiek;
//}

Organizm::Organizm(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek):swiat(xswiat) {
	this->nastepny_kierunek = BRAK;
	this->sila = xsila;
	this->inicjatywa = xinicjatywa;
	this->wsp = xwsp;
	this->wiek = xwiek;
	this->istnieje = true;
	this->odbity = false;
	this->zasieg = 1;
	this->rozmnozone = false;
	this->umiejetnosc = false;
}

/////////////////////////////////////////////


int Organizm::getSila() const{
	return sila;
}
void Organizm::setSila(int xsila) {
	this->sila = xsila;
}
int Organizm::getInicjatywa() const {
	return inicjatywa;
}
void Organizm::setInicjatywa(int xinicjatywa) {
	this->inicjatywa = xinicjatywa;
}
int Organizm::getWiek() const {
	return wiek;
}
void Organizm::setWiek(int xwiek) {
	this->wiek = xwiek;
}
POLOZENIE Organizm::getWsp() const {
	return wsp;
}
void Organizm::setWsp(POLOZENIE xwsp) {
	this->wsp = xwsp;
}
Swiat& Organizm::getSwiat() const {
	return swiat;
}
KIERUNEK Organizm::getNastepnyKierunek() const{
	return nastepny_kierunek;
}
void Organizm::setNastepnyKierunek(KIERUNEK n_k) {
	this->nastepny_kierunek = n_k;
}
bool Organizm::getIstnieje() const{
	return istnieje;
}
void Organizm::setIstnieje(bool xistnieje) {
	this->istnieje = xistnieje;
}
bool Organizm::getOdbity() const {
	return odbity;
}
void Organizm::setOdbity(bool xodbity) {
	this->odbity = xodbity;
}

int Organizm::getZasieg() const {
	return zasieg;
}
void Organizm::setZasieg(int xzasieg) {
	this->zasieg = xzasieg;
}
bool Organizm::getRozmnozone() const {
	return rozmnozone;
}
void Organizm::setRozmnozone(bool czyRozmnozone) {
	this->rozmnozone = czyRozmnozone;
}

void Organizm::setUmiejetnosc(bool aktywowac) {
	this->umiejetnosc = aktywowac;
}

bool Organizm::getUmiejetnosc() {
	return umiejetnosc;
}
