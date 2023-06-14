/*
Stwórz strukturę zawierającą wskaźnik na kolejny element kolejki oraz znak w celu
zaimplementowania kolejki. Następnie stwórz strukturę kolejka, która będzie zawierała dwa
wskaźniki: head oraz tail.
W programie głównym należy stworzyć menu wielokrotnego wyboru oraz
zaimplementować funkcje:
1) sprawdzenie czy kolejka jest pusta,
2) powinien zostać wyświetlony odpowiedni komunikat.
3) dodanie elementu do kolejki,
należy wylosować znak, który zostanie dodany do kolejki.
4) usunięcie elementu z kolejki,
jeśli w kolejce nie ma żadnego elementu należy wyświetlić stosowny komunikat, na
przykład "Kolejka jest pusta, nie da się usunąć elementu".
5) pobranie elementu z kolejki,
należy wyświetlić pierwszy znak, który znajduje się w kolejce.
6) usunięcie wszystkich elementów z kolejki,
podczas usuwania kolejnych elementów należy wyświetlić element, który jest
usuwany.
7) wczytanie do kolejki dużych liter alfabetu łacińskiego z pliku tekstowego, plik
powinien znajdować się w katalogu projektu. Nazwa pliku – „znaki2.txt” powinna
zostać przekazana jako argument. Struktura pliku została przedstawiona na rysunku
10.8. Do kolejki powinny zostać zapisane tylko te znaki, które są dużymi literami
alfabetu łacińskiego.
8) wyjście z programu
*/


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct element{
    char character;
    element *next;
};

struct Queue{
    element *head;
    element *tail;
};

bool isEmpty(Queue q){
    return (q.head == NULL);
}

void push(Queue &q, char value){
    element *el = new element;
    el->character = value;
    el->next = NULL;

    if(q.tail != NULL){
        q.tail->next = el;
    }
    else{
        q.head = el;
    }

    q.tail = el;
}

void pop(Queue &q){
    if(!isEmpty(q)){
        element *temp = q.head;
        q.head = q.head->next;
        delete temp;

        if(q.head == NULL){
            q.tail = NULL;
        }
    } else {
        cout << "Kolejka jest pusta, nie da sie usunac elementu" << endl;
    }
}

char first(Queue q){
    if(!isEmpty(q)){
        return q.head->character;
    }
    else{
        cout << "Kolejka jest pusta!" << endl;
        return '\0';
    }
}

void clearQueue(Queue &q){
    if(!isEmpty(q)){
        while(!isEmpty(q)){
            cout << "Usunieto: " << first(q) << endl;
            pop(q);
        }
    }
    else cout << "Kolejka jest pusta!" << endl;


}

void wczytaj(Queue &q){
    ifstream plik("znaki2.txt");

    if(!plik){
        cout << "Nie udalo sie utworzyc pliku" << endl;
        return;
    }

    char znak;
    while(plik.get(znak)){
        if((int)znak >= 65 && (int)znak <= 90){
            push(q, znak);
        }
    }

    cout << "Wczytano duze litery z pliku 'znaki2.txt' " << endl;
    plik.close();

}

void wyswietl(Queue &q){
    if(!isEmpty(q)){

        Queue Rob;
        Rob.head = NULL;
        Rob.tail = NULL;

        while(!isEmpty(q)){
            cout << first(q) << " ";
            push(Rob, first(q));
            pop(q);
    }

        q = Rob;
        cout << endl;
    }
    else{
        cout << "Kolejka jest pusta !" << endl;
    }
}



int main()
{
    Queue q;
    q.head = NULL;
    q.tail = NULL;

    int wybor = 8;

    cout << "1) czy pusta" << endl;
    cout << "2) Dodanie elementu do kolejki" << endl;
    cout << "3) Usuniecie elementu z kolejki" << endl;
    cout << "4) Pobranie elementu z kolejki" << endl;
    cout << "5) Usuniecie wszystkich elementow z kolejki" << endl;

    cout << "6) Wczytanie duzych liter Alfabetu Lacinskiego z pliku" << endl;
    cout << "7) Wyswietlenie kolejki" << endl;

    cout << "0) Wyjscie" << endl;



    while(wybor){

        cout << "wybor: "; cin >> wybor;

        if(wybor == 1){
            if(isEmpty(q)) cout << "Kolejka jest pusta!" << endl;
            else cout << "Kolejka nie jest pusta" << endl;
        }

        else if(wybor == 2){
            char znak;
            srand(time(NULL));
            znak = 'A' + rand () % 26;
            push(q,znak);

        }

        else if(wybor == 3){
            pop(q);

        }
        else if(wybor == 4){
            cout << "Pierwszy element kolejki: " << first(q) << endl;
        }
        else if(wybor == 5){
            clearQueue(q);
        }

        else if(wybor == 6){
            wczytaj(q);
        }
        else if(wybor == 7){
            wyswietl(q);
        }

        else if(wybor!=0){
            cout << "Sprobuj ponownie!" << endl;
        }
    }

    cout << "Wyjscie :)" << endl;

    return 0;
}
