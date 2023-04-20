//
// Created by pfleg on 17.04.2023.
//

#include "valec.h"
#include <cmath>

Valec::Valec() { // konstruktor bez parametrů vytvoří válec s default parametry (1, 1)
    this->polomer=1;
    this->vyska=1;
}

Valec::Valec(double polomer, double vyska) { //konstruktor s parametry vytvoří válec po kontrole zadaných parametrů
    setValec(polomer, vyska);
}

Valec::Valec(const Valec & v) { //kopírovací konstruktor vytvoří válec z parametrů jiného válce (const Valec & = reference na neměnný objekt Valec)
    this->polomer=v.polomer;
    this->vyska=v.vyska;
}

double Valec::getPolomer() const { // veřejné metody pro získání private hodnot
    return this->polomer;
}

double Valec::getVyska() const {
    return this->vyska;
}

bool Valec::kontrola(double polomer, double vyska) const { // zkontroluje přípustnost zadaných hodnot před nastavením válce (nemůže být záporný)
    if(polomer<=0 or vyska<=0){
        return false;
    }

    return true;
}

void Valec::setValec(double polomer, double vyska) { // pokud je kontrola True, nastaví hodnoty válce
    if(kontrola(polomer,vyska)){
        this->polomer=polomer;
        this->vyska=vyska;
    }
}

double Valec::objem() const {
    return M_PI * pow(this->polomer, 2) * this->vyska; // V = π * r2 * v
}

double Valec::povrch() const {
    return 2 * M_PI * this->polomer * (this->polomer + this->vyska); // V = 2π * r * (r + v)
}

double Valec::obsahPlaste() const {
    return 2 * M_PI * this->polomer * this->vyska; // Spl = 2π * r * v
}

double Valec::obsahPodstavy() const {
    return M_PI * pow(this->polomer, 2); // Spod = π * r2
}

double Valec::vyskaVody(double voda) const {
    voda = voda*100; //převod z dl na cm3
    return (voda<=this->objem()) ? (voda/(M_PI*pow(this->polomer, 2))) : 0; //pokud se voda vejde do válce, vrať výšku vody, jinak pošli nulu
}


std::ostream & operator << (std::ostream & os, const Valec & v){ // přetížení operátoru << pro výpis hodnot válce
    os << v.getPolomer() << ", " << v.getVyska();
    return os;
}

//std::ostream & - reference na output stream

