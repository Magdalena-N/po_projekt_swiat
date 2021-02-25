#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Wilk.h"
#include "Owca.h"
#include "Czlowiek.h"
#include "Trawa.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
using namespace std;


void gotoxy(int x, int y)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD CursorPosition;
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}


int main() {
	hidecursor();
	SetConsoleTitle("Magdalena Nagel 175741");
	srand((unsigned)time(NULL));

	Swiat swiat;

	
	Organizm* wilk[4];
	Organizm* owca[20];
	
	wilk[0] = new Wilk(swiat, 9, 5, { 1,2 },0);
	wilk[1] = new Wilk(swiat, 9, 5, { 18,5 },0);
	wilk[2] = new Wilk(swiat, 9, 5, { 3,9 },0);
	wilk[3] = new Wilk(swiat, 9, 5, { 5,7 },0);


	//owca[0] = new Owca(&swiat, 4, 4, { 5,10 },0);
	//owca[1] = new Owca(&swiat, 4, 4, { 16,1 },0);
	//owca[2] = new Owca(&swiat, 4, 4, { 5,19 },0);
	//owca[3] = new Owca(&swiat, 4, 5, { 8,9 },1);

	POLOZENIE wsp;
	wsp.x = 1;
	wsp.y = 1;

	for (int i = 0; i < 15; i++) {
		owca[i] = new Owca(swiat, 4, 4, { wsp.x++,wsp.y++ },0);
	}
	

	for (int i = 0; i < 4; i++) {
		swiat.dodajOrganizm(wilk[i], wilk[i]->getWsp());
		//swiat.dodajOrganizm(owca[i], owca[i]->getWsp());

	}
	for (int i = 0; i < 15; i++) {
		swiat.dodajOrganizm(owca[i], owca[i]->getWsp());
	}

	Organizm* czlowiek = new Czlowiek(swiat, 5, 4, { 0,6 }, 0);
	swiat.dodajOrganizm(czlowiek, czlowiek->getWsp());
	//swiat.setCzlowiekZyje(true);


	Organizm* trawa[SIZE];
	POLOZENIE wspt;
	wspt.x = 0; wspt.y = 0;
	for (int i = 0; i < SIZE; i++) {
		trawa[i] = new Trawa(swiat, 0, 0, { wspt.x++,wspt.y }, 0);
	}
	for (int i = 0; i < SIZE; i++) {
		swiat.dodajOrganizm(trawa[i], trawa[i]->getWsp());
	}


	Organizm* lis = new Lis(swiat, 3, 7, { 0,9 }, 0);
	swiat.dodajOrganizm(lis, lis->getWsp());

	Organizm* zolw = new Zolw(swiat, 2, 1, { 1,8 }, 0);
	swiat.dodajOrganizm(zolw, zolw->getWsp());

	Organizm* antylopa = new Antylopa(swiat, 4, 4, { 2,7 }, 0);
	swiat.dodajOrganizm(antylopa, antylopa->getWsp());

	Organizm* mlecz = new Mlecz(swiat, 0, 0, { 19,5 }, 0);
	swiat.dodajOrganizm(mlecz, mlecz->getWsp());

	Organizm* guarana = new Guarana(swiat, 0, 0, { 18,19 }, 0);
	swiat.dodajOrganizm(guarana, guarana->getWsp());

	Organizm* wilczejagody = new WilczeJagody(swiat,99, 0, { 7,19 }, 0);
	swiat.dodajOrganizm(wilczejagody, wilczejagody->getWsp());

	Organizm* wilczejagody2 = new WilczeJagody(swiat, 99, 0, { 8,19 }, 0);
	swiat.dodajOrganizm(wilczejagody2, wilczejagody2->getWsp());

	Organizm* barszcz= new BarszczSosnowskiego(swiat, 10 , 0, { 5,15 }, 0);
	swiat.dodajOrganizm(barszcz, barszcz->getWsp());

	swiat.rysujSwiat();




	char kierunek;
	KIERUNEK kierunek_cz;
	int tura = 1;
	char op ;
	do {
		op = _getch();
		switch (op) {
		case 'n':
		case 'N':
			cout << "Tura: " << tura << endl;
			if (swiat.getCzlowiekZyje()) {
				kierunek = _getch();
				if (kierunek == '\033')
					_getch();
				kierunek = _getch();
				switch (kierunek) {
				case GORA_K:
					kierunek_cz = GORA;
					break;
				case DOL_K:
					kierunek_cz = DOL;
					break;
				case LEWO_K:
					kierunek_cz = LEWO;
					break;
				case PRAWO_K:
					kierunek_cz = PRAWO;
					break;
				default:
					break;
				}
				czlowiek->setNastepnyKierunek(kierunek_cz);
			}
			swiat.setKomunikat("Tura: " + to_string(tura) + "\n");
			swiat.wykonajTure();

			break;

		case 'u':
		case 'U':
			if (swiat.getCzlowiekZyje() == true) {
				swiat.uruchomUmiejetnosc();
			}
			break;
		}
		
		
		tura++;
		Sleep(500);

	} while (op != 'e');

	system("pause");
	return 0;
}