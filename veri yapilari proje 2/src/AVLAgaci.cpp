#include "AVLAgaci.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

/**
* @file AVLAgaci.cpp
* @description AVLAgaci kodu
* @course 1A
* @assignment 2
* @date -
* @author -
*/

using namespace std;



    AVLAgaci::AVLAgaci() {
        kok = nullptr;
    }

   AVLAgaci::~AVLAgaci() {
        
    }

    Dugum* AVLAgaci:: getKok() const {
        return kok;
    }

    bool AVLAgaci:: varmi(int veri) {
        return varmi(veri, kok);
    }

     bool AVLAgaci:: ekle(int veri) {
        if (varmi(veri)) {
            return false; // Zaten var, eklenmedi
        }

        kok = ekle(veri, kok);
        return true; // Eklendi
    }
    void AVLAgaci:: sil(int veri) {
        kok = sil(veri, kok);
    }

Dugum* AVLAgaci:: enKucukDugumuBul(Dugum* aktif) {
    if (aktif == nullptr)
        return nullptr;

    while (aktif->sol != nullptr)
        aktif = aktif->sol;

    return aktif;
}

    Dugum* AVLAgaci:: enKucukYaprakDugumu(Dugum* aktif) {
        if (aktif == nullptr)
            return nullptr;

        
        while (aktif->sol != nullptr || aktif->sag != nullptr) {
            if (aktif->sol != nullptr)
                aktif = aktif->sol;
            else
                aktif = aktif->sag;
        }

        return aktif;
    }

Dugum* AVLAgaci:: enBuyukYaprakDugumu(Dugum* aktif) {
    if (aktif == nullptr)
        return nullptr;

    
    while (aktif->sol != nullptr || aktif->sag != nullptr) {
        if (aktif->sag != nullptr)
            aktif = aktif->sag;
        else
            aktif = aktif->sol;
    }

    return aktif;
}

Dugum* AVLAgaci:: enBuyukDugumuBul(Dugum* aktif) {
    if (aktif == nullptr)
        return nullptr;

    Dugum* enBuyukSol = enBuyukDugumuBul(aktif->sol);
    Dugum* enBuyukSag = enBuyukDugumuBul(aktif->sag);

    
    if (aktif->sol == nullptr && aktif->sag == nullptr) {
        return aktif;
    }

    Dugum* enBuyukDugum = aktif;

    
    if (enBuyukSol != nullptr && enBuyukSol->veri > enBuyukDugum->veri) {
        enBuyukDugum = enBuyukSol;
    }

    if (enBuyukSag != nullptr && enBuyukSag->veri > enBuyukDugum->veri) {
        enBuyukDugum = enBuyukSag;
    }

    return enBuyukDugum;
}
 


    int AVLAgaci:: yukseklik() {
        return yukseklik(kok);
    }

    void AVLAgaci:: preOrder() {
        preOrder(kok);
        cout << endl;
    }

    void AVLAgaci:: postOrder() {
        postOrder(kok, cout);
        cout << endl;
    }

    void AVLAgaci:: inOrder() {
        inOrder(kok, cout);
        cout << endl;
    }

   



void AVLAgaci:: postorderYapYigina() {
        postorderYapYigina(kok);
    }

int AVLAgaci:: yaprakOlmayanDugumleriToplam(Dugum* aktif) {
        if (aktif == nullptr) {
            return 0;
        }

        int solToplam = yaprakOlmayanDugumleriToplam(aktif->sol);
        int sagToplam = yaprakOlmayanDugumleriToplam(aktif->sag);

        
        if (aktif->sol || aktif->sag) {
            return aktif->veri + solToplam + sagToplam;
        } else {
            return solToplam + sagToplam;
        }
    }


void AVLAgaci:: postorderYapYigina(Dugum* aktif) {
        if (aktif) {
            postorderYapYigina(aktif->sol);
            postorderYapYigina(aktif->sag);

            
            if (aktif->sol == nullptr && aktif->sag == nullptr) {
                yaprakYigin.ekle(aktif);
            }
        }
    }


    bool AVLAgaci:: varmi(int aranan, Dugum* aktif) {
        if (aktif == nullptr)
            return false;

        if (aranan < aktif->veri) {
            return varmi(aranan, aktif->sol);
        } else if (aranan > aktif->veri) {
            return varmi(aranan, aktif->sag);
        } else {
            return true;
        }
    }

    Dugum* AVLAgaci:: ekle(int veri, Dugum* aktifDugum) {
        if (aktifDugum == nullptr)
            return new Dugum(veri);

        else if (aktifDugum->veri < veri) {
            aktifDugum->sag = ekle(veri, aktifDugum->sag);
            if (yukseklik(aktifDugum->sag) - yukseklik(aktifDugum->sol) > 1) {
                if (veri > aktifDugum->sag->veri)
                    aktifDugum = solaDondur(aktifDugum);
                else {
                    aktifDugum->sag = sagaDondur(aktifDugum->sag);
                    aktifDugum = solaDondur(aktifDugum);
                }
            }
        } else if (aktifDugum->veri > veri) {
            aktifDugum->sol = ekle(veri, aktifDugum->sol);
            if (yukseklik(aktifDugum->sol) - yukseklik(aktifDugum->sag) > 1) {
                if (veri < aktifDugum->sol->veri)
                    aktifDugum = sagaDondur(aktifDugum);
                else {
                    aktifDugum->sol = solaDondur(aktifDugum->sol);
                    aktifDugum = sagaDondur(aktifDugum);
                }
            }
        }

        return aktifDugum;
    }

    Dugum* AVLAgaci:: sil(int veri, Dugum* aktif) {
        if (aktif == 0)
            return 0;

        if (veri < aktif->veri) {
            aktif->sol = sil(veri, aktif->sol);
        } else if (veri > aktif->veri) {
            aktif->sag = sil(veri, aktif->sag);
        } else {
            if (aktif->sol == 0 && aktif->sag == 0) {
                delete aktif;
                aktif = 0;
            } else if (aktif->sol == 0) {
                Dugum* sil = aktif->sag;
                *aktif = *aktif->sag;
                delete sil;
            } else if (aktif->sag == 0) {
                Dugum* sil = aktif->sol;
                *aktif = *aktif->sol;
                delete sil;
            } else {
                aktif->veri = minDeger(aktif->sag);
                sil(aktif->veri, aktif->sag);
            }
        }

        int denge = dengesizlikYonu(aktif);

        if (denge > 1) //sol tarafta dengesizlik
        {
            //sol sol dengesizliği
            if (dengesizlikYonu(aktif->sol) >= 0) {
                return sagaDondur(aktif);
            }
            //sol sag durumu
            if (dengesizlikYonu(aktif->sol) < 0) {
                aktif->sol = solaDondur(aktif->sol);
                return sagaDondur(aktif);
            }
        } else if (denge < -1) //sag tarafta dengesizlik
        {
            //sağ sağ durumu
            if (dengesizlikYonu(aktif->sag) <= 0) {
                return solaDondur(aktif);
            }
            //sağ sol durumu
            if (dengesizlikYonu(aktif->sag) > 0) {
                aktif->sag = sagaDondur(aktif->sag);
                return solaDondur(aktif);
            }
        }
        return aktif;
    }

    int AVLAgaci:: dengesizlikYonu(Dugum* aktif) {
        if (aktif == 0)
            return 0;
        return yukseklik(aktif->sol) - yukseklik(aktif->sag);
    }

    Dugum* AVLAgaci:: solaDondur(Dugum* buyukEbeveyn) {
        Dugum* sagcocuk = buyukEbeveyn->sag;
        buyukEbeveyn->sag = sagcocuk->sol;
        sagcocuk->sol = buyukEbeveyn;
        return sagcocuk;
    }

    Dugum* AVLAgaci:: sagaDondur(Dugum* buyukEbeveyn) {
        Dugum* solcocuk = buyukEbeveyn->sol;
        buyukEbeveyn->sol = solcocuk->sag;
        solcocuk->sag = buyukEbeveyn;
        return solcocuk;
    }

    int AVLAgaci:: minDeger(Dugum* aktif) {
        if (aktif->sol)
            return minDeger(aktif->sol);
        return aktif->veri;
    }

    int AVLAgaci:: maxDeger(Dugum* aktif) {
        if (aktif->sag)
            return maxDeger(aktif->sag);
        return aktif->veri;
    }

    void AVLAgaci:: preOrder(Dugum* aktif) {
        if (aktif) {
            cout << aktif->veri << "  ";
            preOrder(aktif->sol);
            preOrder(aktif->sag);
        }
    }

    void AVLAgaci:: postOrder(Dugum* aktif, ostream& os) {
        if (aktif) {
            postOrder(aktif->sol, os);
            postOrder(aktif->sag, os);
            os << aktif->veri << "  ";
        }
    }

    int AVLAgaci:: yukseklik(Dugum* aktif) {
        if (aktif == nullptr)
            return 0;

        int solYukseklik = yukseklik(aktif->sol);
        int sagYukseklik = yukseklik(aktif->sag);

        return 1 + max(solYukseklik, sagYukseklik);
    }

    void AVLAgaci:: inOrder(Dugum* aktif, ostream& os) {
        if (aktif) {
            inOrder(aktif->sol, os);
            os << aktif->veri << "  ";
            inOrder(aktif->sag, os);
        }
    }
	
	ostream& operator<<(ostream& os, AVLAgaci& agac) {
    os << "Inorder: ";
    agac.inOrder(agac.kok, os);
    os << endl << "Preorder: ";
    agac.preOrder(agac.kok);
    os << endl << "Postorder: ";
    agac.postOrder(agac.kok, os);
    return os;
}

AVLAgaci AVLAgaci:: olusturAVLAgaci(const string& satir) {
    AVLAgaci agac;
    istringstream ss(satir);
    int sayi;
    while (ss >> sayi) {
        agac.ekle(sayi);
    }
    return agac;
}

    
