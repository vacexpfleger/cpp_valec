//
// Created by pfleg on 17.04.2023.
//

#ifndef BEASMRDI_VALEC_H
#define BEASMRDI_VALEC_H
#include <iostream>

class Valec{
public:
    Valec();
    Valec(double, double);
    Valec(const Valec &);
    double getPolomer() const;
    double getVyska() const;
    void setValec(double, double);
    bool kontrola(double, double) const;
    double objem() const;
    double povrch() const;
    double obsahPlaste() const;
    double obsahPodstavy() const;
    double vyskaVody(double) const;
private:
    double polomer;
    double vyska;
};

std::ostream & operator << (std::ostream &, const Valec &);

#endif //BEASMRDI_VALEC_H
