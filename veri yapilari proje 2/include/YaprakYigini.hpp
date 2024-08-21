#ifndef YAPRAKYIGINI_HPP
#define YAPRAKYIGINI_HPP
#include "Dugum.hpp"
#include <iostream>


/**
* @file YaprakYigini.hpp
* @description Yigit kodu
* @course 1A
* @assignment 2
* @date -
* @author -
*/

using namespace std;


class YaprakYigini {
public:
    YaprakYigini();

    ~YaprakYigini();

    void ekle(Dugum* dugum);

    void cikar();

    bool bosmu() const;

    bool dolumu();

    Dugum* getir();

    void yazdir() const;
	
friend ostream& operator<<(ostream& os, YaprakYigini& yigin);

Dugum* enKucukDugumuBul() const;

    Dugum* enBuyukDugumuBul() const;

void cikarDugum(int deger);

private:
    void genislet(int boyut);

    int kapasite;
    int tepe;
    Dugum** veriler;
};
#endif