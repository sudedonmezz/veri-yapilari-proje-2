#include "BagilDugum.hpp"

/**
* @file BagilDugum.cpp
* @description AVLAgaclarini tutar
* @course 1A
* @assignment 2
* @date -
* @author -
*/
   BagilDugum:: BagilDugum(const AVLAgaci& agac) {
       this->agac = new AVLAgaci(agac);
        onceki = sonraki = nullptr;
    }
BagilDugum::~BagilDugum() {
       delete agac;
    }
  
