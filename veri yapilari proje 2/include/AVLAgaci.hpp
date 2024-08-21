#ifndef AVLAGACI_HPP
#define AVLAGACI_HPP
#include "Dugum.hpp"
#include "YaprakYigini.hpp"


/**
* @file AVLAgaci.hpp
* @description AVLAgaci kodu
* @course 1A
* @assignment 2
* @date -
* @author -
*/
using namespace std;

class AVLAgaci {
public:
Dugum* kok;
YaprakYigini yaprakYigin;

    AVLAgaci();

   ~AVLAgaci();

    Dugum* getKok() const;

    bool varmi(int veri);

    bool ekle(int veri);

        
    void sil(int veri);

Dugum* enKucukDugumuBul(Dugum* aktif);

    Dugum* enKucukYaprakDugumu(Dugum* aktif);

Dugum* enBuyukYaprakDugumu(Dugum* aktif);

Dugum* enBuyukDugumuBul(Dugum* aktif);

int yukseklik();

void preOrder();

void postOrder();

void inOrder();

void postorderYapYigina();

int yaprakOlmayanDugumleriToplam(Dugum* aktif);

friend ostream& operator<<(ostream& os, AVLAgaci& agac);
AVLAgaci olusturAVLAgaci(const string& satir);

private:
 

void postorderYapYigina(Dugum* aktif);


bool varmi(int aranan, Dugum* aktif);
Dugum* ekle(int veri, Dugum* aktifDugum);

Dugum* sil(int veri, Dugum* aktif);

int dengesizlikYonu(Dugum* aktif);

Dugum* solaDondur(Dugum* buyukEbeveyn);

Dugum* sagaDondur(Dugum* buyukEbeveyn);

int minDeger(Dugum* aktif);

int maxDeger(Dugum* aktif);

void preOrder(Dugum* aktif);

void postOrder(Dugum* aktif, ostream& os);

int yukseklik(Dugum* aktif);

void inOrder(Dugum* aktif, ostream& os);

    
};

#endif