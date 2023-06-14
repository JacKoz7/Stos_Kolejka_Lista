#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

struct element {
    char znak; //znak z pliku tekstowego
    element* nastepny;
};

void push(char znak, element* &wierzcholek)
{
    if (wierzcholek == nullptr)
    {
        wierzcholek = new element;
        wierzcholek->nastepny = nullptr;
        wierzcholek->znak = znak;
    }
    else
    {
        element* nowy = new element;
        nowy->nastepny = wierzcholek;
        nowy->znak = znak;
        wierzcholek = nowy;
    }
}

char pop(element* &wierzcholek)
{
    if (wierzcholek != nullptr)
    {
        element* usuwany = wierzcholek;
        wierzcholek = wierzcholek->nastepny;
        char znak = usuwany->znak;
        delete usuwany;
        return znak;
    }
    else
    {
        cout << "Stos pusty! " << endl;
        return 0;
    }
}

int main()
{
    element* wierzcholek = nullptr;
    ifstream plik1("znaki1.txt");
    ofstream wynik("wynik.txt");
    char znak;

    // Wyświetlanie zawartości pliku "znaki1.txt"
    while (plik1.get(znak))
    {
        cout << znak;
        push(znak, wierzcholek);
    }
    plik1.close();

    // Wyświetlanie zawartości pliku "wynik.txt"
    ifstream plik2("wynik.txt");
    while (plik2.get(znak))
    {
        cout << znak;
    }
    plik2.close();

    // Zapisywanie odwróconej kolejności do pliku "wynik.txt"
    while (wierzcholek != nullptr)
    {
        char znak = pop(wierzcholek);
        wynik << znak;
    }
    cout << "\n\n----------------------------------------";
    cout << "\n\nOdwrocono kolejnosc znakow w pliku 'znaki1.txt' i zapisano do pliku 'wynik.txt'" << endl;

    wynik.close();
    // Otwieranie pliku wynik.txt do odczytu
    ifstream plik_wynik("wynik.txt");
    if (!plik_wynik)
    {
        cout << "Nie udalo sie otworzyc pliku wynik.txt!" << endl;
        return 1;
    }

    // Wyświetlanie zawartości pliku wynik.txt na ekranie
    cout << "\n----------------------------------------\n";
    cout << endl << "Zawartosc pliku 'wynik.txt':" << endl;
    cout << "\n----------------------------------------\n\n";
    while (plik_wynik.get(znak))
    {
        cout << znak;
    }

    plik_wynik.close();

    return 0;
}
