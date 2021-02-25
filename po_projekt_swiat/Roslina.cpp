#include "Roslina.h"


Roslina::Roslina(Swiat& xswiat, POLOZENIE xwsp)
	:Organizm(xswiat,0,0,xwsp,0){
	
}
Roslina::Roslina(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek)
	: Organizm(xswiat, xsila, xinicjatywa, xwsp, xwiek) {

}

void Roslina::akcja() {
	//bool czyRuchMozliwy = true;
	int temp = rand() % 10;
	if (temp < 2) {
		KIERUNEK gdzie;
		POLOZENIE wsp2 = this->getWsp();
		gdzie = losujKierunek(this);
		zasiej(this, gdzie);
	}
}
bool Roslina::czyWolne(KIERUNEK gdzie) {
	POLOZENIE pozycja = this->getWsp();
	//Swiat* swiat = swiat;
	switch (gdzie) {
	case GORA:
		pozycja.y--;
		break;
	case DOL:
		pozycja.y++;
		break;
	case LEWO:
		pozycja.x--;
		break;
	case PRAWO:
		pozycja.x++;
		break;
	}
	if (*(swiat.getOrganizm(pozycja)) == NULL) {
		return true;
	}
	else
		return false;
}
void Roslina::zasiej(Organizm* xorg, KIERUNEK gdzie) {
	POLOZENIE wsp2 = xorg->getWsp();
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
	if (czyWolne(gdzie)) {
		
		this->dodaj(wsp2);
	}
}
KIERUNEK Roslina::losujKierunek(Organizm* org) {
	int temp;
	KIERUNEK gdzie;
	POLOZENIE obecna_pozycja;
	obecna_pozycja = org->getWsp();
	//obiekt calkiem z lewej
	if (obecna_pozycja.x == 0) {
		//lewy gorny rog(PRAWO,DOL)
		if (obecna_pozycja.y == 0) {
			temp = rand() % 2;
			gdzie = temp == 0 ? PRAWO : DOL;

		}
		//lewy dolny rog (GORA,PRAWO)
		else if (obecna_pozycja.y == SIZE - 1) {
			temp = rand() % 2;
			gdzie = temp == 0 ? GORA : PRAWO;
		}
		//tylko w lewo nie moze
		else {
			temp = rand() % 3;
			switch (temp)
			{
			case 0:
				gdzie = GORA;
				break;
			case 1:
				gdzie = PRAWO;
				break;
			case 2:
				gdzie = DOL;
				break;
			default:
				break;
			}
		}
	}
	//obiekt calkiem z prawej
	else if (obecna_pozycja.x == SIZE - 1) {
		//prawy gorny rog
		if (obecna_pozycja.y == 0) {
			temp = rand() % 2;
			gdzie = temp == 0 ? LEWO : DOL;
		}
		//prawy dolny rog
		else if (obecna_pozycja.y == SIZE - 1) {
			temp = rand() % 2;
			gdzie = temp == 0 ? LEWO : GORA;
		}
		//tylko w prawo nie moze
		else {
			temp = rand() % 3;
			switch (temp)
			{
			case 0:
				gdzie = GORA;
				break;
			case 1:
				gdzie = LEWO;
				break;
			case 2:
				gdzie = DOL;
				break;
			default:
				break;
			}
		}

	}
	//calkiem u gory bez rogow
	else if (obecna_pozycja.y == 0) {
		temp = rand() % 3;
		switch (temp)
		{
		case 0:
			gdzie = PRAWO;
			break;
		case 1:
			gdzie = LEWO;
			break;
		case 2:
			gdzie = DOL;
			break;
		default:
			break;
		}
	}
	//calkiem na dole bez rogow
	else if (obecna_pozycja.y == SIZE - 1) {
		temp = rand() % 3;
		switch (temp)
		{
		case 0:
			gdzie = PRAWO;
			break;
		case 1:
			gdzie = LEWO;
			break;
		case 2:
			gdzie = GORA;
			break;
		default:
			break;
		}
	}
	else {
		temp = rand() % 4;
		gdzie = (KIERUNEK)temp;
	}
	return gdzie;
}


void Roslina::kolizja(Organizm& atakujacy) {
	POLOZENIE wsp1 = this->getWsp();
	string temp = "";
	temp += atakujacy.rysowanie();
	temp += " zjadl ";
	temp += this->rysowanie();
	swiat.setKomunikat(temp);
	this->setIstnieje(false);
	swiat.dodajdoUsuniecia(this);
	swiat.dodajOrganizm(NULL, wsp1);

}
bool Roslina::czyOdbilAtak(Organizm& atakujacy) {
	return false;
}
char Roslina::rysowanie() {
	return ROSLINA;
}