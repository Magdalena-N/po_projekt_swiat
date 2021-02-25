#pragma once
#include "stale.h"
#include "Swiat.h"

class Swiat;

class Organizm {
	friend Swiat;
private:
	KIERUNEK nastepny_kierunek;
	int sila;
	int inicjatywa;
	int wiek;
	POLOZENIE wsp;
	bool istnieje;
	bool odbity;
	int zasieg;
	bool rozmnozone;
	bool umiejetnosc;
protected:
	Swiat& swiat;
public:
	//Organizm();
	//Organizm(int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek);
	Organizm(Swiat& swiat, int xsila, int xinicjatywa, POLOZENIE xwsp, int xwiek);

	/////////////////////////////

	virtual void akcja() = 0; //okreœla zachowanie organizmu w trakcie tury,
	virtual void kolizja(Organizm& atakujacy) = 0; // okreœla zachowanie organizmu w trakcie kontaktu / zderzenia z innym organizmem,
	virtual char rysowanie() = 0; //powoduje narysowanie symbolicznej reprezentacji organizmu
	virtual bool czyOdbilAtak(Organizm& atakujacy) = 0;

	//////////////////////

	int getSila() const;
	void setSila(int xsila);

    int getInicjatywa() const;
	void setInicjatywa(int xinicjatywa);

	int getWiek() const;
	void setWiek(int xwiek);

	POLOZENIE getWsp() const;
	void setWsp(POLOZENIE xwsp);

	Swiat& getSwiat() const;

	KIERUNEK getNastepnyKierunek() const;
	void setNastepnyKierunek(KIERUNEK n_k);

	bool getIstnieje() const;
	void setIstnieje(bool xistnieje);

	bool getOdbity() const;
	void setOdbity(bool xodbity);

	int getZasieg() const;
	void setZasieg(int xzasieg);

	bool getRozmnozone() const;
	void setRozmnozone(bool czyRozmnozone);

	bool getUmiejetnosc();
	void setUmiejetnosc(bool aktywowac);
};