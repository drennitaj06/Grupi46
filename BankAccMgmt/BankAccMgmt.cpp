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

    if (id <= 0 || id > numriLlogarive || !llogarite[id - 1].aktive) {
        cout << "Llogaria nuk ekziston!\n";
        return;
    }

    cout << "Shuma per depozitim: ";
    cin >> shuma;

    if (shuma <= 0) {
        cout << "Shuma duhet te jete pozitive!\n";
        return;
    }

    llogarite[id - 1].bilanci += shuma;
    llogarite[id - 1].historia += "Depozitim: +" + to_string(shuma) + " EUR\n";
    cout << "Depozitimi u krye me sukses!\n";
}



int main()
{
    // Pika e hyrjes së programit, për momentin bosh
}
