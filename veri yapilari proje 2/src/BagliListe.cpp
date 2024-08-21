#include "BagliListe.hpp"
#include <iostream>
#include <cstring>


/**
* @file BagliListe.cpp
* @description BagliListe kodu
* @course 1A
* @assignment 2
* @date -
* @author -
*/

using namespace std;

 int BagliListe::yaprakOlmayanDugumleriSay(Dugum* aktif) {
    if (aktif == nullptr) {
        return 0;
    }

    if (aktif->sol == nullptr && aktif->sag == nullptr) {
        return 0;
    }

    return 1 + yaprakOlmayanDugumleriSay(aktif->sol) + yaprakOlmayanDugumleriSay(aktif->sag);
}

 

BagliListe::BagliListe()
{
    ilk=son=nullptr;
}
BagliListe::~BagliListe() {
        temizle();
    }

   void BagliListe:: temizleBosAgacDugumleri(BagliListe& liste) {
    BagilDugum* gecici = liste.ilk;
    while (gecici != nullptr) {
        BagilDugum* silinecek = gecici;
        gecici = gecici->sonraki;

        
        if (silinecek->agac->getKok() == nullptr) {
            delete silinecek->agac;
            delete silinecek;

            
            if (silinecek->onceki != nullptr) {
                silinecek->onceki->sonraki = silinecek->sonraki;
            } else {
                liste.ilk = silinecek->sonraki;
            }

            if (silinecek->sonraki != nullptr) {
                silinecek->sonraki->onceki = silinecek->onceki;
            } else {
                liste.son = silinecek->onceki;
            }
        }
    }
}


int BagliListe:: yaprakOlmayanDugumleriToplam() {
        BagilDugum* gecici = ilk;
        int toplam = 0;
        while (gecici != nullptr) {
            toplam += gecici->agac->yaprakOlmayanDugumleriToplam(gecici->agac->getKok());
            gecici = gecici->sonraki;
        }
        return toplam;
    }

void BagliListe:: ekle(const AVLAgaci& agac) {
        BagilDugum* yeniDugum = new BagilDugum(agac);
        if (ilk == nullptr) {
            ilk = son = yeniDugum;
        } else {
            son->sonraki = yeniDugum;
            yeniDugum->onceki = son;
            son = yeniDugum;
        }
    }

void BagliListe:: gezYaprakOlmayan() {
    BagilDugum* gecici = ilk;
    while (gecici != nullptr) {
      

        
        int yaprakOlmayanDugumToplam = gecici->agac->yaprakOlmayanDugumleriToplam(gecici->agac->getKok());
        int ascii = yaprakOlmayanDugumToplam % (90 - 65 + 1) + 65;
cout << char(ascii);

      

        gecici = gecici->sonraki;
    }
    cout << flush;
}
void BagliListe:: yazdirYaprakYiginlari() {
        BagilDugum* gecici = ilk;
        while (gecici != nullptr) {
            cout << "Yaprak Yigini Dugumleri: ";
            gecici->agac->yaprakYigin.yazdir();
            gecici = gecici->sonraki;
        }
    }



void BagliListe:: temizle() {
        BagilDugum* gecici = ilk;
        while (gecici != nullptr) {
            BagilDugum* silinecek = gecici;
            gecici = gecici->sonraki;
            delete silinecek->agac;
            delete silinecek;
        }

        ilk = son = nullptr;
    }


    AVLAgaci* BagliListe:: bulIlkBosYigini(BagliListe& liste) {
    BagilDugum* gecici = liste.ilk;

    while (gecici != nullptr) {
        if (gecici->agac->yaprakYigin.bosmu()) {
            return gecici->agac;
        }

        gecici = gecici->sonraki;
    }

    return nullptr; 
}

Dugum* BagliListe:: enKucukYaprakDugumuGenel(BagliListe& bagliListe) {
    BagilDugum* gecici = bagliListe.ilk;
    Dugum* enKucukDugum = nullptr;

    while (gecici != nullptr) {
        AVLAgaci* agac = gecici->agac;

        
        agac->postorderYapYigina();

        
        Dugum* kucukDugum = agac->yaprakYigin.enKucukDugumuBul();

        
        if (enKucukDugum == nullptr || (kucukDugum != nullptr && kucukDugum->veri < enKucukDugum->veri)) {
            enKucukDugum = kucukDugum;
        }

        gecici = gecici->sonraki;
    }

    return enKucukDugum;
}

    void BagliListe:: cikarAgac(AVLAgaci* agac) {
        BagilDugum* gecici = ilk;
        while (gecici != nullptr) {
            if (gecici->agac == agac) {
                if (gecici->onceki != nullptr) {
                    gecici->onceki->sonraki = gecici->sonraki;
                } else {
                    ilk = gecici->sonraki;
                }

                if (gecici->sonraki != nullptr) {
                    gecici->sonraki->onceki = gecici->onceki;
                } else {
                    son = gecici->onceki;
                }

                delete gecici;
                break;
            }

            gecici = gecici->sonraki;
        }
    }

Dugum* BagliListe:: enBuyukYaprakDugumuGenel(BagliListe& bagliListe) {
    BagilDugum* gecici = bagliListe.ilk;
    Dugum* enBuyukDugum = nullptr;

    while (gecici != nullptr) {
        AVLAgaci* agac = gecici->agac;

        
        agac->postorderYapYigina();

        
        Dugum* buyukDugum = agac->yaprakYigin.enBuyukDugumuBul();

        
        if (enBuyukDugum == nullptr || (buyukDugum != nullptr && buyukDugum->veri > enBuyukDugum->veri)) {
            enBuyukDugum = buyukDugum;
        }

        gecici = gecici->sonraki;
    }

    return enBuyukDugum;
}





