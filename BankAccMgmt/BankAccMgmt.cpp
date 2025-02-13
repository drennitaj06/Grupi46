#include <iostream>  // Librari për operacionet e hyrjes dhe daljes
#include <iomanip>   // Librari për formatimin e daljes
#include <string>    // Librari për manipulimin e vargjeve të karaktereve
#include <cmath>     // Librari për funksione matematikore
using namespace std;



const int MAX_ACCOUNTS = 100; // Numri maksimal i llogarive që mund të ruhen

// Struktura që përfaqëson një llogari bankare
struct Llogari {
    int id;            // Identifikues unik për llogarinë
    string emri;       // Emri i mbajtësit të llogarisë
    string mbiemri;    // Mbiemri i mbajtësit të llogarisë
    double bilanci;    // Bilanci i llogarisë
    string historia;   // Historia e transaksioneve
    bool aktive;       // Gjendja e llogarisë (aktive/inaktive)
};

Llogari llogarite[MAX_ACCOUNTS]; // Krijon një varg me objekte të tipit 'Llogari' me madhësi maksimale 'MAX_ACCOUNTS'.
int numriLlogarive = 0;          // Inicializon një variabël që ruan numrin aktual të llogarive në 0.



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

    // Kontrollo nëse inputi është numer dhe brenda kufijve të lejuar
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
    // Pika e hyrjes së programit, për momentin bosh
}
