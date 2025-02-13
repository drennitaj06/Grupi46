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



// Funksioni per te transferuar para nga nje llogari ne tjetren
void transfero() {
    int id1, id2;
    double shuma;

    // Marrja e ID s� llogaris� q� do t� d�rgoj� para
    cout << "Jepni ID e llogarise qe do te dergoje para: ";
    cin >> id1;
    while (id1 <= 0 || id1 > numriLlogarive || !llogarite[id1 - 1].aktive) {
        cout << "Llogaria nuk ekziston! Ju lutem provoni perseri: ";
        cin >> id1;
    }

    // Marrja e ID s� llogaris� q� do t� pranoj� para
    cout << "Jepni ID e llogarise qe do te pranoje para: ";
    cin >> id2;
    while (id2 <= 0 || id2 > numriLlogarive || !llogarite[id2 - 1].aktive || id1 == id2) {
        cout << "Llogaria nuk ekziston ose ID eshte e njejte me dhenesin! Provoni perseri: ";
        cin >> id2;
    }

    // Marrja e shum�s p�r transferim
    cout << "Shuma per transferim: ";
    cin >> shuma;
    while (shuma <= 0 || shuma > llogarite[id1 - 1].bilanci) {
        cout << "Shuma nuk eshte e vlefshme! Ju lutem provoni perseri: ";
        cin >> shuma;
    }

    // Kryerja e transferimit
    llogarite[id1 - 1].bilanci -= shuma;
    llogarite[id2 - 1].bilanci += shuma;

    // Regjistrimi i transaksionit n� historin� e t� dyja llogarive
    llogarite[id1 - 1].historia += "Transferuar: -" + to_string(shuma) + " EUR tek llogaria " + to_string(id2) + "\n";
    llogarite[id2 - 1].historia += "Marre: +" + to_string(shuma) + " EUR nga llogaria " + to_string(id1) + "\n";

    cout << "Transferimi u krye me sukses!\n";
}



int main() {
    int zgjedhja;

    do {
        cout << "\n1. Hap Llogari\n2. Depozito\n3. Terheq\n4. Kontrollo Bilancin\n5. Shfaq Detajet\n6. Transfero Para\n7. Dil\nZgjedhja juaj: ";
        cin >> zgjedhja;

        switch (zgjedhja) {
        case 1: krijoLlogari(); break;
        case 2: depozito(); break;
        case 3: terheq(); break;
        case 4: shfaqBilancin(); break;
        case 5: shfaqDetajet(); break;
        case 6: transfero(); break;
        case 7: cout << "Dalje...\n"; break;
        default: cout << "Zgjedhje e pavlefshme!\n";
        }
    } while (zgjedhja != 8);

    return 0;
}
