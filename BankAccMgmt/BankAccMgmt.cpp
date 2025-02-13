#include <iostream>  // Librari p�r operacionet e hyrjes dhe daljes
#include <iomanip>   // Librari p�r formatimin e daljes
#include <string>    // Librari p�r manipulimin e vargjeve t� karaktereve
#include <cmath>     // Librari p�r funksione matematikore
using namespace std;



const int MAX_ACCOUNTS = 100; // Numri maksimal i llogarive q� mund t� ruhen

// Struktura q� p�rfaq�son nj� llogari bankare
struct Llogari {
    int id;            // Identifikues unik p�r llogarin�
    string emri;       // Emri i mbajt�sit t� llogaris�
    string mbiemri;    // Mbiemri i mbajt�sit t� llogaris�
    double bilanci;    // Bilanci i llogaris�
    string historia;   // Historia e transaksioneve
    bool aktive;       // Gjendja e llogaris� (aktive/inaktive)
};

Llogari llogarite[MAX_ACCOUNTS]; // Krijon nj� varg me objekte t� tipit 'Llogari' me madh�si maksimale 'MAX_ACCOUNTS'.
int numriLlogarive = 0;          // Inicializon nj� variab�l q� ruan numrin aktual t� llogarive n� 0.



// Funksioni per krijimin e nje llogarie te re
void krijoLlogari() {
    if (numriLlogarive >= MAX_ACCOUNTS) {
        cout << "Nuk mund te krijoni me shume llogari!\n";
        return;
    }

    Llogari l;
    l.id = numriLlogarive + 1;
    cout << "Emri: ";
    cin >> l.emri;
    cout << "Mbiemri: ";
    cin >> l.mbiemri;
    l.bilanci = 0;
    l.aktive = true;
    l.historia = "Llogaria u krijua me sukses.\n";

    llogarite[numriLlogarive] = l;
    numriLlogarive++;

    cout << "Llogaria u krijua me sukses! ID e saj eshte: " << l.id << "\n";
}



// Funksioni per depozitimin e parave
void depozito() {
    int id;
    double shuma;

    cout << "Jepni ID e llogarise: ";
    cin >> id;

    while (!(id > 0 && id <= numriLlogarive && llogarite[id - 1].aktive)) {
        cout << "Llogaria nuk ekziston! Ju lutem provoni perseri: ";
        cin >> id;
    }

    cout << "Shuma per depozitim: ";
    cin >> shuma;

    while (!(shuma > 0)) {
        cout << "Shuma duhet te jete pozitive! Provoni perseri: ";
        cin >> shuma;
    }

    llogarite[id - 1].bilanci += shuma;
    llogarite[id - 1].historia += "Depozitim: +" + to_string(shuma) + " EUR\n";
    cout << "Depozitimi u krye me sukses!\n";
}



// Funksioni per terheqjen e parave
void terheq() {
    int id;
    double shuma;

    cout << "Jepni ID e llogarise: ";
    cin >> id;

    while (!(id > 0 && id <= numriLlogarive && llogarite[id - 1].aktive)) {
        cout << "Llogaria nuk ekziston! Ju lutem provoni perseri: ";
        cin >> id;
    }

    cout << "Shuma per terheqje: ";
    cin >> shuma;

    while (!(shuma > 0 && shuma <= llogarite[id - 1].bilanci)) {
        cout << "Shuma nuk eshte e vlefshme! Provoni perseri: ";
        cin >> shuma;
    }

    llogarite[id - 1].bilanci -= shuma;
    llogarite[id - 1].historia += "Terheqje: -" + to_string(shuma) + " EUR\n";
    cout << "Terheqja u krye me sukses!\n";
}



// Funksioni per te shfaqur bilancin e llogarise
void shfaqBilancin() {
    int id;
    cout << "Jepni ID e llogarise: ";
    cin >> id;

    // Kontrollo n�se inputi �sht� numer dhe brenda kufijve t� lejuar
    while (!(id > 0 && id <= numriLlogarive && llogarite[id - 1].aktive)) {
        cout << "ID e pavlefshme! Ju lutem provoni perseri: ";
        cin >> id;
    }

    cout << "\n-------------------------\n";
    cout << "Bilanci aktual per llogarine me ID " << id << ": "
        << fixed << setprecision(2) << llogarite[id - 1].bilanci << " EUR\n";
    cout << "-------------------------\n";
}


// Funksioni per te shfaqur detajet e llogarise
void shfaqDetajet() {
    int id;
    cout << "Jepni ID e llogarise: ";
    cin >> id;

    while (!(id > 0 && id <= numriLlogarive && llogarite[id - 1].aktive)) {
        cout << "Llogaria nuk ekziston! Ju lutem provoni perseri: ";
        cin >> id;
    }

    Llogari l = llogarite[id - 1];

    cout << "-------------------------\n";
    cout << "ID: " << l.id << "\n";
    cout << "Emri: " << l.emri << " " << l.mbiemri << "\n";
    cout << "Bilanci: " << fixed << setprecision(2) << l.bilanci << " EUR\n";
    cout << "-------------------------\n";
}


int main()
{
    // Pika e hyrjes s� programit, p�r momentin bosh
}
