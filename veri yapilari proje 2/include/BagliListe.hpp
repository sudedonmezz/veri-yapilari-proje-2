#ifndef BAGLILISTE_HPP
#define BAGLILISTE_HPP
#include "BagilDugum.hpp"



/**
* @file BagliListe.hpp
* @description BagliListe kodu
* @course 1A
* @assignment 2
* @date -
* @author -
*/

using namespace std;
class BagliListe
{
private:
BagilDugum* ilk;
BagilDugum* son;

int yaprakOlmayanDugumleriSay(Dugum* aktif);

 
public:
BagliListe();

~BagliListe();

void temizleBosAgacDugumleri(BagliListe& liste);


int yaprakOlmayanDugumleriToplam();

void ekle(const AVLAgaci& agac);

void gezYaprakOlmayan();
void yazdirYaprakYiginlari();



void temizle();


AVLAgaci* bulIlkBosYigini(BagliListe& liste);

Dugum* enKucukYaprakDugumuGenel(BagliListe& bagliListe);
 
void cikarAgac(AVLAgaci* agac);
Dugum* enBuyukYaprakDugumuGenel(BagliListe& bagliListe);





};

#endif