//
// Created by pfleg on 17.04.2023.
//

#include "valec.h"
#include <cmath>

Valec::Valec() {
    this->polomer=1;
    this->vyska=1;
}

Valec::Valec(double polomer, double vyska) {
    setValec(polomer, vyska);
}

Valec::Valec(const Valec & v) {
    this->polomer=v.polomer;
    this->vyska=v.vyska;
}

double Valec::getPolomer() const {
    return this->polomer;
}

double Valec::getVyska() const {
    return this->vyska;
}

bool Valec::kontrola(double polomer, double vyska) const {
    if(polomer<=0 or vyska<=0){
        return false;
    }

    return true;
}

void Valec::setValec(double polomer, double vyska) {
    if(kontrola(polomer,vyska)){
        this->polomer=polomer;
        this->vyska=vyska;
    }
}

double Valec::objem() const {
    return M_PI * pow(this->polomer, 2) * this->vyska;
}

double Valec::povrch() const {
    return 2 * M_PI * this->polomer * (this->polomer + this->vyska);
}

double Valec::obsahPlaste() const {
    return 2 * M_PI * this->polomer * this->vyska;
}

double Valec::obsahPodstavy() const {
    return M_PI * pow(this->polomer, 2);
}

double Valec::vyskaVody(double voda) const {
    voda = voda*100;
    return (voda<=this->objem()) ? (voda/(M_PI*pow(this->polomer, 2))) : 0;
}


std::ostream & operator << (std::ostream & os, const Valec & v){
    os << v.getPolomer() << ", " << v.getVyska();
    return os;
}

// 1, 1