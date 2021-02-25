#include "Swiat.h"


using namespace std;

Swiat::Swiat() {
	//swiat = new Organizm**[SIZE];
	for (int i = 0; i < SIZE; i++) organizmy.push_back(NULL);
	for (int i = 0; i < SIZE; i++) {
		worganizmy.push_back(organizmy);
	}
	this->czlowiekZyje = false;
}
void Swiat::setCzlowiekZyje(bool zyje) {
	this->czlowiekZyje = zyje;
}
bool Swiat::getCzlowiekZyje() {
	return czlowiekZyje;
}

struct OrganizmComparator
{

	bool operator ()(Organizm* org1, Organizm* org2)
	{
		if (org1->getInicjatywa() == org2->getInicjatywa()) {

			
				return org1->getWiek() > org2->getWiek();
			
		}
		else {
			return org1->getInicjatywa() > org2->getInicjatywa();
		}
		

	}
};
bool Swiat::czyIstnieje(Organizm* org) {
	/*if (*org == NULL) {
		return false;
	}*/
	if (org != NULL) {
		return true;
	}
	else 
		return false;

}
void Swiat::wykonajTure() {

	doUsuniecia.clear();

	list<Organizm*>kolejnosc_ruchow;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (worganizmy[i][j] != NULL)
				kolejnosc_ruchow.push_back(worganizmy[i][j]);
			
		}
	}

	kolejnosc_ruchow.sort(OrganizmComparator());
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (worganizmy[i][j] != NULL) {
				worganizmy[i][j]->setWiek(worganizmy[i][j]->getWiek() + 1);
			}

		}
	}
	for (auto it : kolejnosc_ruchow) {
		if (it->getIstnieje()) {
			it->akcja();
			//it->akcja();
			//piszKomunikat();
		}
	}

	for (auto it : doUsuniecia) {
		delete it;
	}

	this->rysujSwiat();
	Sleep(500);

	while (kolejnosc_ruchow.size() != 0) kolejnosc_ruchow.pop_back();
	

}
void Swiat::rysujSwiat() {
	system("cls");
	
	
	for (int i = 0; i < SIZE; i++) {
		
		for (int j = 0; j < SIZE; j++) {
			if (worganizmy[i][j] == NULL)
				_putch(' ');
			else {
				_putch(worganizmy[i][j]->rysowanie());
			}
		}
		_putch('|');
		_putch('\n');
	}
	cout << "-------------------" << endl;
	piszKomunikat();

}
Organizm** Swiat::getOrganizm(POLOZENIE pozycja) {
	return &worganizmy[pozycja.y][pozycja.x];
}
void Swiat::dodajOrganizm(Organizm* xorgan, POLOZENIE pozycja) {
	worganizmy[pozycja.y][pozycja.x] = xorgan;
}

void Swiat::setKomunikat(string xlog) {
	this->komunikat += xlog;
	this->komunikat += "\n";
}
string Swiat::getKomunikat() {
	return komunikat;
}
void Swiat::piszKomunikat() {
	cout << komunikat;
	komunikat = "";
}

void Swiat::uruchomUmiejetnosc() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (worganizmy[i][j] != NULL && worganizmy[i][j]->rysowanie() == CZLOWIEK) {
				worganizmy[i][j]->setUmiejetnosc(true);
			}
			
		}
	}

}
void Swiat::dodajdoUsuniecia(Organizm* obiekt) {
	doUsuniecia.push_back(obiekt);
}

Swiat::~Swiat() {
	
}