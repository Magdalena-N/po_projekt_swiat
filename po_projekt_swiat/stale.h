#pragma once
#include<Windows.h>
#include<iostream>
#include<conio.h> //obsluga klawiatury
#include<vector>
#include<time.h>
#include<algorithm>
#include <list>
#include<string>

#define SIZE 20

using namespace std;

//SYMBOLE

//KLAWISZE
#define GORA_K 72
#define DOL_K 80
#define LEWO_K 75
#define PRAWO_K 77
#define ESC 0x1b			
#define ENTER 0x0d 

//CZLOWIEK
#define CZLOWIEK '?'

//ZWIERZETA
#define ZWIERZE 'V'
#define WILK 'W'
#define OWCA 'O'
#define LIS 'L'
#define ZOLW 'Z'
#define ANTYLOPA 'A'

//ROSLINY
#define ROSLINA '+'
#define TRAWA ','
#define MLECZ '*'
#define GUARANA '~'
#define JAGODY '.'
#define BARSZCZ '#'

struct POLOZENIE {
	int x = 0;
	int y = 0;
};

//gora,dol,lewo,prawo
enum KIERUNEK {
	GORA,
	DOL,
	LEWO,
	PRAWO,
	BRAK
};




