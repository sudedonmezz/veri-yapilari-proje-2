#include "YaprakYigini.hpp"
#include <iostream>


/**
* @file YaprakYigini.cpp
* @description Yigit kodu
* @course 1A
* @assignment 2
* @date -
* @author -
*/

using namespace std;

    YaprakYigini::YaprakYigini() {
        tepe = -1;
        veriler = nullptr;
        kapasite = 5;
        genislet(kapasite);
    }

    YaprakYigini::~YaprakYigini() {
        
    }

    void YaprakYigini:: ekle(Dugum* dugum) {
        if (tepe == kapasite - 1)
            genislet(kapasite);

        tepe++;
        veriler[tepe] = dugum;
    }

    void YaprakYigini:: cikar() {
        if (tepe != -1) {
            tepe--;
        }
    }

    bool YaprakYigini:: bosmu() const {
    for (int i = 0; i <= tepe; i++) {
        if (veriler[i] != nullptr) {
            return false; 
        }
    }
    return true; 
}

    bool YaprakYigini:: dolumu() {
        return (tepe == kapasite - 1);
    }

    Dugum* YaprakYigini:: getir() {
        if (tepe != -1)
            return veriler[tepe];
        throw std::out_of_range("Yigin Bos");
    }

    void YaprakYigini:: yazdir() const {
    cout << "Yigin: ";
    for (int i = tepe; i >= 0; i--) {
        cout << veriler[i]->veri << " ";
    }
    cout << endl;
}
ostream& operator<<(ostream& os, YaprakYigini& yigin) {
    os << "Yigin: ";
    for (int i = yigin.tepe; i >= 0; i--) {
        os << yigin.veriler[i]->veri << " ";
    }
    os << endl;
    return os;
}

Dugum* YaprakYigini:: enKucukDugumuBul() const {
        if (tepe == -1) {
            return nullptr; 
        }

        Dugum* enKucukDugum = veriler[0];
        for (int i = 1; i <= tepe; ++i) {
            if (veriler[i]->veri < enKucukDugum->veri) {
                enKucukDugum = veriler[i];
            }
        }

        return enKucukDugum;
    }

    Dugum* YaprakYigini:: enBuyukDugumuBul() const {
    if (tepe != -1) {
        Dugum* enBuyukDugum = veriler[0];

        for (int i = 1; i <= tepe; i++) {
            if (veriler[i]->veri > enBuyukDugum->veri) {
                enBuyukDugum = veriler[i];
            }
        }

        return enBuyukDugum;
    }

    return nullptr; 
}

void YaprakYigini:: cikarDugum(int deger) {
    int cikarilanIndex = -1;

    
    for (int i = 0; i <= tepe; i++) {
        if (veriler[i]->veri == deger) {
            cikarilanIndex = i;
            break;
        }
    }

    
    if (cikarilanIndex != -1) {
        for (int i = cikarilanIndex; i < tepe; i++) {
            veriler[i] = veriler[i + 1];
        }
        tepe--;
    }
}

    void YaprakYigini:: genislet(int boyut) {
        Dugum** yeniAlan = new Dugum*[boyut + kapasite];
        for (int i = 0; i <= tepe; i++) {
            yeniAlan[i] = veriler[i];
        }
        if (veriler)
            delete[] veriler;
        veriler = yeniAlan;
        kapasite += boyut;
    }

   

