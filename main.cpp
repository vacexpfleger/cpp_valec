#include <iostream>
#include "valec.h"
using namespace std;

int main (){
    Valec v1;
    Valec v2(5.6, 5.6);
    Valec v3(v2);
    cout << "Objekt vytvoreny vychozim konstruktorem (polomer, vyska): " << v1 << endl;
    cout << "Objekt vytvoreny konstruktorem s parametry (polomer, vyska): " << v2 << endl;
    cout << "Objekt vytvoreny kopirovacim konstruktorem (polomer, vyska): " << v3 << endl;

    char input = 'k';
    while(input=='k') {
        float polomer, vyska, voda;
        cout << "\nZadej polomer v cm: ";
        cin >> polomer;
        cout << "Zadej vysku v cm: ";
        cin >> vyska;
        cout << "Zadej objem vody v dl: ";
        cin >> voda;

        v1.setValec(polomer, vyska);
        float hladina = v1.vyskaVody(voda);

        cout << "\nPolomer po zmene: " << v1.getPolomer() << " cm" << endl;
        cout << "Vyska po zmene: " << v1.getVyska() << " cm" << endl;
        cout << "Objem valce je: " << v1.objem() << " cm3" << endl;
        cout << "Povrch valce je: " << v1.povrch() << " cm2" << endl;
        cout << "Obsah plaste je: " << v1.obsahPlaste() << " cm2" << endl;
        cout << "Obsah podstavy je: " << v1.obsahPodstavy() << " cm2" << endl;

        if(hladina!=0){
            cout << "Hladina vody je: " << hladina << "cm" << endl;
        }

        cout << "\nPro pokracovani stiskni 'k': ";
        cin >> input;
    }
    return 0;
}