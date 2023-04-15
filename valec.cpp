//
// Created by pfleg on 15.04.2023.
//

#include <cmath>
#include "valec.h"

Valec::Valec() {
    this->polomer=1;
    this->vyska=1;
}

Valec::Valec(float polomer, float vyska) {
    setValec(polomer, vyska);
}

Valec::Valec(const Valec & o) {
    this->polomer = o.polomer;
    this->vyska = o.vyska;
}

bool Valec::kontrola(float polomer, float vyska) {
    if(polomer<0 or vyska<0){
        return false;
    }

    return true;
}

void Valec::setValec(float polomer, float vyska) {
    if(kontrola(polomer, vyska)) {
        this->polomer=polomer;
        this->vyska=vyska;
    }
}

float Valec::getPolomer() const {
    return this->polomer;
}

float Valec::getVyska() const {
    return this->vyska;
}

float Valec::objem() const {
    return M_PI*(this->polomer*this->polomer)*this->vyska; // V = π r2 h
}

float Valec::povrch() const {
    return 2*M_PI*this->polomer*(this->polomer+this->vyska); // S = 2 π r (r + h)
}

float Valec::obsahPlaste() const {
    return 2*M_PI*this->polomer*this->vyska; // Q = 2 π r h
}

float Valec::obsahPodstavy() const {
    return M_PI*(this->polomer*this->polomer); // P = π r2
}

float Valec::vyskaVody(float voda) const {
    voda = voda*100; // převod z decilitrů na cm3

    return (voda<=this->objem()) ? ((4*voda)/(M_PI*(2*this->polomer)*(2*this->polomer))) : 0; // h = 4 V / π d2
}

std::ostream & operator << (std::ostream & os, const Valec & v){
    os << v.getPolomer() << ", " << v.getVyska();
    return os;
}