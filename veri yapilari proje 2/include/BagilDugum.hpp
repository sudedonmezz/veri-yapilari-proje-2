#ifndef BAGILDUGUM_HPP
#define BAGILDUGUM_HPP
#include "AVLAgaci.hpp"


/**
* @file BagilDugum.hpp
* @description AVLAgaclarini tutar
* @course 1A
* @assignment 2
* @date -
* @author -
*/
class BagilDugum {
public:
    BagilDugum(const AVLAgaci& agac);
~BagilDugum();

    AVLAgaci* agac;
    BagilDugum* onceki;
    BagilDugum* sonraki;
};

#endif