#include <iostream>
#include "valec.h"

int main() {
    Valec v1;
    Valec v2(5.6, 5.2);
    Valec v3(v2);
    std::cout << "Objekt vytvoreny vychozim konstruktorem(polomer, vyska): " << v1 << std::endl;
    std::cout << "Objekt vytvoreny konstruktorem s parametry(polomer, vyska): " << v2 << std::endl;
    std::cout << "Objekt vytvoreny kopirovacim konstruktorem(polomer, vyska): " << v3 << std::endl;

    char input = 'k';
    while(input=='k'){
        double polomer, vyska, voda;
        std::cout << "\nZadej polomer v cm: ";
        std::cin >> polomer;
        std::cout << "Zadej vysku v cm: ";
        std::cin >> vyska;
        std::cout << "Zadej objem vody v dl: ";
        std::cin >> voda;

        v1.setValec(polomer, vyska);
        double hladina = v1.vyskaVody(voda);
        std::cout << "\nPolomer po zmene: " << v1.getPolomer() << " cm" << std::endl;
        std::cout << "Vyska po zmene: " << v1.getVyska() << " cm" << std::endl;
        std::cout << "Objem valce je: " << v1.objem() << " cm3" << std::endl;
        std::cout << "Povrch valce je: " << v1.povrch() << " cm2" << std::endl;
        std::cout << "Obsah plaste valce je: " << v1.obsahPlaste() << " cm2" << std::endl;
        std::cout << "Obsah podstavy valce je: " << v1.obsahPodstavy() << " cm2" << std::endl;

        if(hladina!=0){
            std::cout << "Hladina vody je: " << hladina << " cm" << std::endl;
        }

        std::cout << "\nPro pokracovani zadej 'k': ";
        std::cin >> input;
    }

    return 0;
}
