#pragma once
#include "stale.h"
#include "Organizm.h"


class Organizm;

class Swiat {
private:
	vector<vector<Organizm*>> worganizmy;
	vector<Organizm*>organizmy;
	string komunikat;
	bool czlowiekZyje;
	list<Organizm*> doUsuniecia;
public:
	//Organizm*** swiat;
	Organizm** getOrganizm(POLOZENIE pozycja);
	Swiat();
	void wykonajTure() ;
	void rysujSwiat() ;
	void dodajOrganizm(Organizm* organ,POLOZENIE pozycja);
	bool czyIstnieje(Organizm* org);

	string getKomunikat();
	void setKomunikat(string xlog);
	void piszKomunikat();

	bool getCzlowiekZyje();
	void setCzlowiekZyje(bool zyje);

	void uruchomUmiejetnosc();
	void dodajdoUsuniecia(Organizm* obiekt);
	~Swiat();
};