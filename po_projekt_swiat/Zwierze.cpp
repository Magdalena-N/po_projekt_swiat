#include "Zwierze.h"
//
//Zwierze::Zwierze(Swiat& xswiat, POLOZENIE xwsp)
//	:Organizm(xswiat, 0, 0, xwsp, 0) {
//
//}
Zwierze::Zwierze(Swiat& xswiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek)
	: Organizm(xswiat,xsila, xinicjatywa, xwsp,xwiek){
	
}


void Zwierze::akcja(){
	bool czyRuchMozliwy = true;
	KIERUNEK gdzie;
	POLOZENIE wsp2 = this->getWsp();
	if (this->getNastepnyKierunek() == BRAK) {
		gdzie = losujKierunek(this);
	}
	else {
		gdzie = this->getNastepnyKierunek();
		if ((gdzie == GORA && wsp2.y - 1 < 0) ||
			(gdzie == DOL && wsp2.y + 1 > SIZE - 1) ||
			(gdzie == LEWO && wsp2.x - 1 < 0) ||
			(gdzie == PRAWO && wsp2.x + 1 > SIZE - 1))
			czyRuchMozliwy = false;
	}
	if(czyRuchMozliwy){


		if (czyWolne(gdzie,this->getZasieg())) {
			ruch(this, gdzie);
		}
		else {
			switch (gdzie) {
			case GORA:
				wsp2.y-= this->getZasieg();
				break;
			case DOL:
				wsp2.y+= this->getZasieg();
				break;
			case LEWO:
				wsp2.x-= this->getZasieg();
				break;
			case PRAWO:
				wsp2.x+= this->getZasieg();
				break;
			default:
				break;
			}


			(*(swiat.getOrganizm(wsp2)))->kolizja(*this);
			if (*(swiat.getOrganizm(this->getWsp())) != NULL && this->getOdbity() == false && this->getRozmnozone() == false) {
				ruch(this, gdzie);
			}
			else if (*(swiat.getOrganizm(this->getWsp())) != NULL){
				this->setOdbity(false);
				this->setRozmnozone(false);
			}

		}
	}
}
bool Zwierze::czyWolne(KIERUNEK gdzie,int zasieg) {
	POLOZENIE pozycja = this->getWsp();
	//Swiat& swiat = swiat;
	switch (gdzie) {
	case GORA:
		pozycja.y-=zasieg;
		break;
	case DOL:
		pozycja.y+=zasieg;
		break;
	case LEWO:
		pozycja.x-=zasieg;
		break;
	case PRAWO:
		pozycja.x+=zasieg;
		break;
	}
	if (*(swiat.getOrganizm(pozycja)) == NULL) {
		return true;
	}
	else
		return false;
}
KIERUNEK Zwierze::losujKierunek(Organizm* org) {
	int temp;
	KIERUNEK gdzie;
	POLOZENIE obecna_pozycja;
	obecna_pozycja = org->getWsp();
	//obiekt calkiem z lewej
	if (obecna_pozycja.x == 0 || obecna_pozycja.x == org->getZasieg() - 1) {
		//lewy gorny rog(PRAWO,DOL)
		if (obecna_pozycja.y == 0 || obecna_pozycja.y == org->getZasieg() - 1) {
			temp = rand() % 2;
			gdzie = temp == 0 ? PRAWO : DOL;

		}
		//lewy dolny rog (GORA,PRAWO)
		else if (obecna_pozycja.y == SIZE - 1 || obecna_pozycja.y == SIZE - org->getZasieg() - 1) {
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
	else if (obecna_pozycja.x == SIZE - 1 || obecna_pozycja.x == SIZE - org->getZasieg() - 1) {
		//prawy gorny rog
		if (obecna_pozycja.y == 0 || obecna_pozycja.y == org->getZasieg() - 1) {
			temp = rand() % 2;
			gdzie = temp == 0 ? LEWO : DOL;
		}
		//prawy dolny rog
		else if (obecna_pozycja.y == SIZE - 1 || obecna_pozycja.y == SIZE - org->getZasieg() - 1) {
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
	else if (obecna_pozycja.y == 0 || obecna_pozycja.y == org->getZasieg() - 1) {
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
	else if (obecna_pozycja.y == SIZE - 1 || obecna_pozycja.y == SIZE - org->getZasieg() - 1) {
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

bool Zwierze::czyOdbilAtak(Organizm& atakujacy){
	return false;
}
void Zwierze::rozmnoz(KIERUNEK gdzie) {
	POLOZENIE wsp2 = this->getWsp();
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
	

	if (czyWolne(gdzie, 1)) {

		this->dodaj(wsp2);
		
	}
	/*else {
		gdzie = losujKierunek(this);
		rozmnoz(gdzie);
	}*/
	
}
void Zwierze::kolizja(Organizm& atakujacy) {
	KIERUNEK gdzie;
	if (this->rysowanie() == atakujacy.rysowanie()) {
		gdzie = losujKierunek(this);
		rozmnoz(gdzie);
		/*string temp = "";
		temp += atakujacy.rysowanie();
		temp += " urodzily ";
		temp += this->rysowanie();
		swiat.setKomunikat(temp);*/
		atakujacy.setRozmnozone(true);
		
	}
	else {
		//sila zaatakowanego mniejsza/rowna od atakujacego ginie zaatakowany
		if (this->getSila() <= atakujacy.getSila()) {
			string temp = "";
			temp += atakujacy.rysowanie();
			temp += " zabil/a ";
			temp += this->rysowanie();
			swiat.setKomunikat(temp);
			this->setIstnieje(false);
			
			swiat.dodajOrganizm(NULL, this->getWsp());
			swiat.dodajdoUsuniecia(this);
			
		}
		
		//w przeciwnym wypadku sila zaatakowanego wieksza ginie atakujacy
		else {
			string temp = "";
			temp += this->rysowanie();
			temp += " zabil/a ";
			temp += atakujacy.rysowanie();
			swiat.setKomunikat(temp);
			atakujacy.setIstnieje(false);
			
			swiat.dodajOrganizm(NULL, atakujacy.getWsp());
			swiat.dodajdoUsuniecia(&atakujacy);
			
		}
	}
	
}

void Zwierze::ruch(Organizm* org, KIERUNEK gdzie) {
	POLOZENIE wsp1 = org->getWsp();
	POLOZENIE wsp2 = org->getWsp();
	//Organizm** temp = org->getSwiat()->getOrganizm(wsp2);

	switch (gdzie) {
	case GORA:
		wsp2.y-=org->getZasieg();
		break;
	case DOL:
		wsp2.y+= org->getZasieg();
		break;
	case LEWO:
		wsp2.x-= org->getZasieg();
		break;
	case PRAWO:
		wsp2.x+= org->getZasieg();
		break;
	default:
		break;
	}
	org->setWsp(wsp2);
	swiat.dodajOrganizm(org, wsp2);
	swiat.dodajOrganizm(NULL, wsp1);

}