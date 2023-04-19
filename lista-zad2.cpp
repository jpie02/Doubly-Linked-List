#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

// struktura definiująca node listy dwukierunkowej (DLL)
struct node {
    
    // część przechowująca dane
    string nazwisko;
    string imie;
    string wiek;
    string pesel;
    string plec;
    // wskaźnik wskazujący na poprzedni node
    node* prev;
    // wskaźnik wskazujący na następny node
    node* next;
};

void menu(node* head);

// funkcja dodawająca pierwszy node (osobę) do DLL (jeśli nie istnieje) lub dodająca kolejny na końcu listy
void dodajNowyNodeNaKoncu(node** head, string nazwiskof, string imief, string wiekf, string peself, string plecf) {

    // tworzenie nowego node z podanymi danymi
    
    // dynamiczna alokacja pamięci
    struct node* new_node = new node();
    //struct node* new_node = (node*)malloc(sizeof(struct node));

    new_node->nazwisko = nazwiskof;
    new_node->imie = imief;
    new_node->wiek = wiekf;
    new_node->pesel = peself;
    new_node->plec = plecf;

    // ustawianie wskaźnik na next na NULL
    new_node->next = NULL;

    // jeśli lista jest pusta (tworzenie pierwszego node'a)
    if ((*head) == NULL) {
        new_node->prev = NULL;

        *head = new_node;

        menu(*head);
    }
    // jeśli na liście są już node'y
    else {

        node* end = *head;

        // przemieszczanie się na koniec listy
        while (end->next != NULL) {
            // przejście do następnego node'a
            end = end->next;
        }

        end->next = new_node;

        new_node->prev = end;

        menu(*head);
    }
}

// pobieranie danych
void case1(node* head) {

    string nazwisko1;
    string imie1;
    string wiek1;
    string pesel1;
    string plec1;

    system("CLS");

    cout << "Nazwisko:" << endl;
    cin >> nazwisko1;
    cout << "Imie:" << endl;
    cin >> imie1;
    cout << "Wiek:" << endl;
    cin >> wiek1;
    cout << "PESEL:" << endl;
    cin >> pesel1;
    cout << "Plec (k lub m):" << endl;
    cin >> plec1;

    dodajNowyNodeNaKoncu(&head, nazwisko1, imie1, wiek1, pesel1, plec1);
}

// wyświetlanie od początku listy
void case2(node* head) {

    system("CLS");

    // temp = head "przemieszczający się"
    node* temp = head;

    // przemieszczanie się w liście i wyświetlanie
    while (temp != NULL) {
        cout << "   Nazwisko:" << endl;
        cout << "   " << temp->nazwisko << endl;
        cout << "   Imie:" << endl;
        cout << "   " << temp->imie << endl;
        cout << "   Wiek:" << endl;
        cout << "   " << temp->wiek << endl;
        cout << "   PESEL:" << endl;
        cout << "   " << temp->pesel << endl;
        cout << "   Plec (k lub m):" << endl;
        cout << "   " << temp->plec << endl;
        cout << " " << endl;

        // przejście do następnego node'a  
        temp = temp->next;
    }
    menu(head);
}

// wyświetlanie od końca listy
void case3(node* head) {

    system("CLS");

    // end = head "przemieszczający się"
    node* end = head;

    // przemieszczanie się do końca listy
    while (end->next != NULL) {
        end = end->next;
    }
    // wyświetlanie od końca listy
    while (end != head) {
        cout << "   Nazwisko:" << endl;
        cout << "   " << end->nazwisko << endl;
        cout << "   Imie:" << endl;
        cout << "   " << end->imie << endl;
        cout << "   Wiek:" << endl;
        cout << "   " << end->wiek << endl;
        cout << "   PESEL:" << endl;
        cout << "   " << end->pesel << endl;
        cout << "   Plec (k lub m):" << endl;
        cout << "   " << end->plec << endl;
        cout << " " << endl;

        // przejście do następnego node'a
        end = end->prev;
    }

    // wyświetlanie, kiedy end = head
    cout << "   Nazwisko:" << endl;
    cout << "   " << end->nazwisko << endl;
    cout << "   Imie:" << endl;
    cout << "   " << end->imie << endl;
    cout << "   Wiek:" << endl;
    cout << "   " << end->wiek << endl;
    cout << "   PESEL:" << endl;
    cout << "   " << end->pesel << endl;
    cout << "   Plec (k lub m):" << endl;
    cout << "   " << end->plec << endl;
    cout << " " << endl;

    menu(head);
}

// wyszukiwanie osoby po nazwisku lub imieniu
void case4(node* head) {

    system("CLS");

    // temp = head "przemieszczający się"
    node* temp = head;

    int x;
    string y;
    string z;

    cout << "   Wybierz nazwisko lub imie:" << endl;
    cout << "   * 1 - nazwisko" << endl;
    cout << "   * 2 - imie" << endl;
    cout << "   ";
    cin >> x;

    switch (x) {
    case 1:
        cout << "   Podaj nazwisko:" << endl;
        cout << "   ";
        cin >> y;
        cout << " " << endl;

        // przeszukiwanie listy w celu znalezienia podanego nazwiska
        while (temp->nazwisko != y && temp->next != NULL) {
            temp = temp->next;
        }

        // jeśli nazwisko nie występuje na liście
        if (temp->nazwisko != y) {
            cout << "   Podane nazwisko nie wystepuje na liscie" << endl;
            menu(head);
        }

        // jeśli nazwisko zostało znalezione - wyświetlanie
        cout << "   Nazwisko:" << endl;
        cout << "   " << temp->nazwisko << endl;
        cout << "   Imie:" << endl;
        cout << "   " << temp->imie << endl;
        cout << "   Wiek:" << endl;
        cout << "   " << temp->wiek << endl;
        cout << "   PESEL:" << endl;
        cout << "   " << temp->pesel << endl;
        cout << "   Plec (k lub m):" << endl;
        cout << "   " << temp->plec << endl;

        menu(head);
        break;

    case 2:
        cout << "   Podaj imie:" << endl;
        cout << "   ";
        cin >> z;
        cout << " " << endl;

        // przeszukiwanie listy w celu znalezienia podanego imienia
        while (temp->imie != z && temp->next != NULL) {
            temp = temp->next;
        }

        // jeśli imię nie występuje na liście
        if (temp->imie != z) {
            cout << "   Podane imie nie wystepuje na liscie" << endl;
            menu(head);
        }

        // jeśli imię zostało znalezione - wyświetlanie
        cout << "   Nazwisko:" << endl;
        cout << "   " << temp->nazwisko << endl;
        cout << "   Imie:" << endl;
        cout << "   " << temp->imie << endl;
        cout << "   Wiek:" << endl;
        cout << "   " << temp->wiek << endl;
        cout << "   PESEL:" << endl;
        cout << "   " << temp->pesel << endl;
        cout << "   Plec (k lub m):" << endl;
        cout << "   " << temp->plec << endl;

        menu(head);
        break;
    default:
        menu(head);
    }
}

// usuwanie osoby po nazwisku
void case5(node* head) {

    system("CLS");

    // temp = head "przemieszczający się"
    node* temp = head;

    string y;

    cout << "   Podaj nazwisko:" << endl;
    cout << "   ";
    cin >> y;
    cout << " " << endl;

    // przeszukiwanie listy w celu znalezienia podanego nazwiska
    while (temp->nazwisko != y
        && temp->next != NULL) {
        temp = temp->next;
    }

    // jeśli nazwisko nie występuje na liście
    if (temp->nazwisko != y) {
        cout << "   Podane nazwisko nie wystepuje na liscie" << endl;
        menu(head);
    }

    // jeśli nazwisko zostało znalezione - usuwanie

    // zmiana next jeśli usuwany node jest head'em
    if (temp->prev == NULL)
        head = temp->next;

    // zmiana next tylko jeśli node nie jest ostatni
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    // zmiana prev tylko jesli node nie jest pierwszym (head'em)
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    // uwalnianie pamięci zajmownej przez node'a
    free(temp);

    menu(head);
}

// zapisywanie listy do pliku
void case6(node* head) {

    system("CLS");

    // otwieranie lub tworzenie i otwieranie pliku do zapisu
    ofstream plik("lista-dwukierunkowa.txt");

    // temp = head "przemieszczający się"
    node* temp = head;

    // przemieszczanie się w liście i zapisywanie do pliku
    while (temp != NULL) {

        plik << "Nazwisko: " << endl;
        plik << temp->nazwisko << endl;
        plik << "Imie: " << endl;
        plik << temp->imie << endl;
        plik << "Wiek: " << endl;
        plik << temp->wiek << endl;
        plik << "PESEL: " << endl;
        plik << temp->pesel << endl;
        plik << "Plec: " << endl;
        plik << temp->plec << endl;
        plik << "   " << endl;

        // przejście do następnego node'a  
        temp = temp->next;
    }

    // zamykanie pliku
    plik.close();

    menu(head);
}

void zwalnianiePamieci(node* head) {
    free(head);
}

void menu(node* head) {

    int x;

    cout << " " << endl;
    cout << "   Wybierz opcje:" << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout << "   * 1 - dodaj osobe" << endl;
    cout << "   * 2 - wyswietl od poczatku" << endl;
    cout << "   * 3 - wyswietl od konca" << endl;
    cout << "   * 4 - wyszukaj po nazwisku lub imieniu" << endl;
    cout << "   * 5 - usun po nazwisku" << endl;
    cout << "   * 6 - zapisz do pliku" << endl;
    cout << "   * 7 - wyjscie" << endl;

    cin >> x;

    switch (x) {
    case 1:
        case1(head);
        break;
    case 2:
        case2(head);
        break;
    case 3:
        case3(head);
        break;
    case 4:
        case4(head);
        break;
    case 5:
        case5(head);
        break;
    case 6:
        case6(head);
        break;
    case 7:
        zwalnianiePamieci(head);
        break;
    }
}

int main() {

    struct node* head = NULL;

    menu(head);

    return 0;
}