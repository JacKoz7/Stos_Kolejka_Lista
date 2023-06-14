#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Element {
    int liczba;
    Element* nastepny;
};

struct ListaJednokierunkowa {
    Element* poczatek;
    Element* koniec;
    int licznik;
};


bool czyPusta(const ListaJednokierunkowa& lista) {
    return lista.poczatek == nullptr;
}

void dodajNaPoczatek(ListaJednokierunkowa& lista) {
    int num = rand() % 50 + 1;
    Element* nowyElement = new Element;
    nowyElement->liczba = num;
    nowyElement->nastepny = lista.poczatek;

    if (lista.koniec == nullptr) {
        lista.koniec = nowyElement;
    }

    lista.poczatek = nowyElement;
    lista.licznik++;
}

void dodajNaKoniec(ListaJednokierunkowa& lista) {
    int num = rand() % 50 + 1;
    Element* nowyElement = new Element;
    nowyElement->liczba = num;
    nowyElement->nastepny = nullptr;

    if (lista.poczatek == nullptr) {
        lista.poczatek = nowyElement;
    } else {
        lista.koniec->nastepny = nowyElement;
    }

    lista.koniec = nowyElement;
    lista.licznik++;
}

void usunZPoczatku(ListaJednokierunkowa& lista) {
    if (czyPusta(lista)) {
    cout << endl << "Lista jest pusta. Brak elementow do wyswietlenia." << endl;
    return;
    }
    if (lista.poczatek != nullptr) {
        Element* doUsuniecia = lista.poczatek;
        lista.poczatek = lista.poczatek->nastepny;

        if (lista.poczatek == nullptr) {
            lista.koniec = nullptr;
        }

        delete doUsuniecia;
        lista.licznik--;
    }
}

void usunZKonca(ListaJednokierunkowa& lista) {
    if (czyPusta(lista)) {
    cout << endl << "Lista jest pusta. Brak elementów do wyœwietlenia." << endl;
    return;
    }
    if (lista.koniec != nullptr) {
        if (lista.poczatek == lista.koniec) {
            delete lista.koniec;
            lista.poczatek = lista.koniec = nullptr;
        } else {
            Element* temp = lista.poczatek;
            while (temp->nastepny != lista.koniec) {
                temp = temp->nastepny;
            }

            delete lista.koniec;
            lista.koniec = temp;
            lista.koniec->nastepny = nullptr;
        }

        lista.licznik--;
    }
}

void wyswietlListe(const ListaJednokierunkowa& lista) {
    if (czyPusta(lista)) {
    cout << endl << "Lista jest pusta. Brak elementów do wyœwietlenia." << endl;
    return;
    }
    Element* temp = lista.poczatek;

    while(temp != nullptr) {
        cout << endl;
        cout << temp->liczba << " ";
        temp = temp->nastepny;
    }

    cout << "\n";
}

void dodajNaPozycje(ListaJednokierunkowa& lista, int pozycja) {
    if (pozycja < 0 || (pozycja > lista.licznik && lista.licznik != 0)) {
        cout << "Nieprawidlowa pozycja." << endl;
        return;
    }

    int num = rand() % 50 + 1;
    Element* nowyElement = new Element;
    nowyElement->liczba = num;

    if (pozycja == 0 || czyPusta(lista)) {
        nowyElement->nastepny = lista.poczatek;
        lista.poczatek = nowyElement;

        if (lista.koniec == nullptr) {
            lista.koniec = nowyElement;
        }
    } else {
        Element* aktualny = lista.poczatek;
        for (int i = 0; i < pozycja - 1; i++) {
            aktualny = aktualny->nastepny;
        }

        nowyElement->nastepny = aktualny->nastepny;
        aktualny->nastepny = nowyElement;

        if (nowyElement->nastepny == nullptr) {
            lista.koniec = nowyElement;
        }
    }

    lista.licznik++;
}


void usunZPozycji(ListaJednokierunkowa& lista, int pozycja) {
    if (pozycja  < 0 || pozycja >= lista.licznik) {
        cout << "Nieprawidlowa pozycja. Pozycja musi byc wieksza lub rowna 0 i mniejsza od liczby elementow." << endl;
        return;
    }

    Element* aktualny = lista.poczatek;
    Element* doUsuniecia = nullptr;

    if (pozycja == 0) {
        lista.poczatek = aktualny->nastepny;
        doUsuniecia = aktualny;
    } else {
        for (int i = 0; i < pozycja - 1; i++) {
            aktualny = aktualny->nastepny;
        }

        doUsuniecia = aktualny->nastepny;
        aktualny->nastepny = doUsuniecia->nastepny;
    }

    delete doUsuniecia;
    lista.licznik--;
}

void pobierzPierwszyElement(ListaJednokierunkowa& lista) {
    if (czyPusta(lista)) {
        cout << "Lista jest pusta. Nie mo¿na pobrac pierwszego elementu." << endl;
        return;
    }

    cout << endl << "Pierwszy element listy to: " << lista.poczatek->liczba << endl;
}

void pobierzOstatniElement(ListaJednokierunkowa& lista) {
    if (czyPusta(lista)) {
        cout << "Lista jest pusta. Nie mo¿na pobrac ostatniego elementu." << endl;
        return;
    }

    cout << endl << "Ostatni element listy to: " << lista.koniec->liczba << endl;
}

void usunListe(ListaJednokierunkowa& lista) {
    while (!czyPusta(lista)) {
        usunZPoczatku(lista);
    }
}

void sredniaArytmetyczna(ListaJednokierunkowa& lista) {
    if (czyPusta(lista)) {
        cout << endl << "Lista jest pusta. Nie mozna obliczyc sredniej arytmetycznej." << endl;
        return;
    }

    int suma = 0;
    Element* aktualny = lista.poczatek;
    while (aktualny != nullptr) {
        suma += aktualny->liczba;
        aktualny = aktualny->nastepny;
    }

    double srednia = (double)(suma) / lista.licznik;
    cout << endl << "Srednia arytmetyczna elementow listy wynosi: " << srednia << endl;
}

void znajdzMaksimum(const ListaJednokierunkowa& lista) {
    if (czyPusta(lista)) {
        cout << endl << "Lista jest pusta. Nie mozna znalezc elementu maksymalnego." << endl;
        return;
    }

    int maxElement = lista.poczatek->liczba;
    int maxPozycja = 0;
    int pozycja = 0;
    Element* aktualny = lista.poczatek;

    while (aktualny != nullptr) {
        if (aktualny->liczba > maxElement) {
            maxElement = aktualny->liczba;
            maxPozycja = pozycja;
        }

        aktualny = aktualny->nastepny;
        pozycja++;
    }

    cout << endl << "Element maksymalny to " << maxElement << " na pozycji " << maxPozycja << endl;
}

int main() {
    srand(time(0));
    ListaJednokierunkowa mojaLista;
    mojaLista.poczatek = nullptr;
    mojaLista.koniec = nullptr;
    mojaLista.licznik = 0;

    while (1){
        int x;
        cout << endl << "jaka operacje chcesz wykonac? " << endl << endl;
        cout << "1 - dodaj element na poczatek listy " << endl;
        cout << "2 - dodaj element na koniec listy " << endl;
        cout << "3 - usun element z poczatku listy " << endl;
        cout << "4 - usun element z konca listy " << endl;
        cout << "5 - dodaj element na okreslona pozycje " << endl;
        cout << "6 - usun element z okreslonej pozycji " << endl;
        cout << "7 - pierwszy element listy " << endl;
        cout << "8 - ostatni element listy" << endl;
        cout << "9 - oblicz srednia arytmetyczna " << endl;
        cout << "10 - znajdz najwiekszy element i jego pozycje" << endl;
        cout << "11 - wyswietl liste" << endl;
        cout << "12 - Sprawdz czy lista jest pusta" <<endl;
        cout << "13 - wyjdz i usun liste" << endl << endl;
        cin >> x;
        if(x == 1){
            dodajNaPoczatek(mojaLista);
        }else if(x == 2){
            dodajNaKoniec(mojaLista);
        }else if(x == 3){
            usunZPoczatku(mojaLista);
        }else if(x == 4){
            usunZKonca(mojaLista);
        }else if(x == 5){
            int n;
            cout << "podaj pozycje " << endl;
            cin >> n;
            dodajNaPozycje(mojaLista, n);
        }else if(x == 6){
            int n;
            cout << "podaj pozycje " << endl;
            cin >> n;
            usunZPozycji(mojaLista, n);
        }else if(x == 7){
            pobierzPierwszyElement(mojaLista);
        }else if(x == 8){
            pobierzOstatniElement(mojaLista);
        }else if(x == 9){
            sredniaArytmetyczna(mojaLista);
        }else if(x == 10){
            znajdzMaksimum(mojaLista);
        }else if(x == 11){
            wyswietlListe(mojaLista);
        }else if(x == 13){
            usunListe(mojaLista);
            break;
        }else if(x == 12){
            if(czyPusta(mojaLista)){
                cout << endl << "lista jest pusta "<< endl;
            }else{
                cout << endl << "lista nie jest pusta " << endl;
            }
        }
        }
    return 0;
}
