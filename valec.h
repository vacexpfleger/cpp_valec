//
// Created by pfleg on 15.04.2023.
//

#ifndef VALEC_VALEC_H
#define VALEC_VALEC_H
#include <iostream>

class Valec {
public:
    Valec();
    Valec(float, float);
    Valec(const Valec &);
    float getPolomer() const;
    float getVyska() const;
    float objem() const;
    float povrch() const;
    float obsahPlaste() const;
    float obsahPodstavy() const;
    void setValec(float, float);
    bool kontrola(float, float);
    float vyskaVody(float) const;
private:
    float polomer;
    float vyska;
};

std::ostream & operator << (std::ostream &, const Valec &);

#endif //VALEC_VALEC_H
