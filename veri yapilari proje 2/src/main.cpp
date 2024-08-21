#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "BagliListe.hpp"
#include "AVLAgaci.hpp"
#include "Dugum.hpp"
#include "YaprakYigini.hpp"
#include "BagilDugum.hpp"

/**
* @file main.cpp
* @description ana kod
* @course 1A
* @assignment 2
* @date -
* @author -
*/


using namespace std;

int main()
{
	
	
     ifstream dosya("src/Veri.txt");

    if (!dosya.is_open()) {
        cerr << "Dosya açılamadı." << endl;
        return 1;
    }

    BagliListe bagliListe;

    string satir;
    while (getline(dosya, satir)) {
        if (!satir.empty()) {
             AVLAgaci agac;
        agac = agac.olusturAVLAgaci(satir);
            agac.postorderYapYigina();
            bagliListe.ekle(agac);
        } else {
            cerr << "Satır boş!" << endl;
        }
    }
    dosya.close();

    bagliListe.gezYaprakOlmayan();
    //bagliListe.yazdirYaprakYiginlari();
cout<<endl<<"-----------------------"<<endl;
 
    Dugum* enKucukYaprakDugum = bagliListe.enKucukYaprakDugumuGenel(bagliListe);

 
Dugum* enBuyukYaprakDugum = bagliListe.enBuyukYaprakDugumuGenel(bagliListe);
if (enKucukYaprakDugum != nullptr) {
        cout << "en kucuk yaprak dugumu " << enKucukYaprakDugum->veri << endl;
    } else {
        cout << "En küçük yaprak düğümü bulunamadı." << endl;
    }

    if (enBuyukYaprakDugum != nullptr) {
        cout << "en buyuk yaprak dugumu " << enBuyukYaprakDugum->veri << endl;
    } else {
        cout << "En küçük yaprak düğümü bulunamadı." << endl;
    }



    
    bagliListe.temizle();

    return 0;

}