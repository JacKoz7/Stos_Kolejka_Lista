/*
Stwórz strukturę zawierającą wskaźnik na kolejny element stosu oraz liczbę całkowitą
w celu zaimplementowania stosu.
W programie głównym należy stworzyć wskaźnik na strukturę, menu wielokrotnego
wyboru oraz zaimplementować funkcje:
1) sprawdzenie czy stos jest pusty,
powinien zostać wyświetlony odpowiedni komunikat.
2) dodanie elementu na stos,
liczbę, która powinna być dodana do stosu, należy wylosować z zakresu 1 - 10.
3) usunięcie elementu ze stosu,
jeśli na stosie nie ma żadnego elementu należy wyświetlić stosowny komunikat, na
przykład: "Stos jest pusty".
4) pobranie elementu ze stosu,
należy wyświetlić ostatni element, który znajduje się na stosie.
5) usunięcie wszystkich elementów ze stosu,
należy usunąć wszystkie elementy na stosie poprzez zdejmowanie kolejnych
6) elementów ze stosu.
7) wyjście z programu.
*/






#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

struct element {
    int wartosc; //liczba calkowita
    element * nastepny;
};

element* wierzcholek = nullptr;

void wyswietl_stos()
{
    cout << endl;
    cout << "----------------" << endl;
    cout << "ZAWARTOSC STOSU:" << endl;
    cout << "----------------" << endl;
    element* aktualny = wierzcholek;
    if(wierzcholek == nullptr){
        cout<<"stos jest pusty"<<endl;
    }
    while(aktualny != nullptr)
    {
        cout<<aktualny->wartosc<<endl;
        aktualny = aktualny->nastepny;
    }
    cout << "----------------" << endl;
}

void push()
{
    if(wierzcholek == nullptr)
    {
        wierzcholek = new element;
        wierzcholek->nastepny = nullptr;
        wierzcholek->wartosc = rand() % 10 + 1;
    }
    else
    {
        element* nowy = new element;
        nowy->nastepny = wierzcholek;
        nowy->wartosc = rand() % 10 + 1;
        wierzcholek = nowy;
    }
}

void pop()
{
    if(wierzcholek != nullptr)
    {
        element* usuwany = wierzcholek;
        wierzcholek = wierzcholek->nastepny;
        delete usuwany;
        cout << endl << "Usunieto wierzcholek ";
    }
    else
    {
        cout<< "Stos pusty! " << endl;
    }
}

void top()
{
    if(wierzcholek != nullptr)
    {
        cout << endl << "Ostatni element na stosie: " << wierzcholek->wartosc << endl;
    }
    else
    {
        cout << "Stos pusty! " << endl;
    }
}

int main()
{
    while (1)
    {
        int wybor;
        cout << endl;
        cout << "wybierz opcje: " << endl;
        cout << "1 - dodaj losowa liczbe na wierzcholek" << endl;
        cout << "2 - usun liczbe ktora znajduje sie na wierzcholku" << endl;
        cout << "3 - ostatni element w stosie" << endl;
        cout << "4 - Wyswietl stos " << endl;
        cout << "0 - WYJSCIE" << endl;
        cin >> wybor;
        if(wybor == 4)
        {
            wyswietl_stos();
        }
        if(wybor == 1)
        {
            push();
        }
        if(wybor == 2)
        {
            pop();
        }
        if(wybor == 3)
        {
            top();
        }
        if(wybor == 0)
        {
            break;
            system("exit");

        }

    }
    return 0;
}
