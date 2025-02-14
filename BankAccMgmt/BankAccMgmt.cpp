#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

const int MAX_ACCOUNTS = 100;

struct Llogari {
    int id;
    string emri;
    string mbiemri;
    double bilanci;
    string historia;
    bool aktive;
};

Llogari llogarite[MAX_ACCOUNTS];
int numriLlogarive = 0;

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


// Funksioni per te transferuar para nga nje llogari ne tjetren
void transfero() {
    int id1, id2;
    double shuma;

    // Marrja e ID së llogarisë që do të dërgojë para
    cout << "Jepni ID e llogarise qe do te dergoje para: ";
    cin >> id1;
    while (id1 <= 0 || id1 > numriLlogarive || !llogarite[id1 - 1].aktive) {
        cout << "Llogaria nuk ekziston! Ju lutem provoni perseri: ";
        cin >> id1;
    }

    // Marrja e ID së llogarisë që do të pranojë para
    cout << "Jepni ID e llogarise qe do te pranoje para: ";
    cin >> id2;
    while (id2 <= 0 || id2 > numriLlogarive || !llogarite[id2 - 1].aktive || id1 == id2) {
        cout << "Llogaria nuk ekziston ose ID eshte e njejte me dhenesin! Provoni perseri: ";
        cin >> id2;
    }

    // Marrja e shumës për transferim
    cout << "Shuma per transferim: ";
    cin >> shuma;
    while (shuma <= 0 || shuma > llogarite[id1 - 1].bilanci) {
        cout << "Shuma nuk eshte e vlefshme! Ju lutem provoni perseri: ";
        cin >> shuma;
    }

    // Kryerja e transferimit
    llogarite[id1 - 1].bilanci -= shuma;
    llogarite[id2 - 1].bilanci += shuma;

    // Regjistrimi i transaksionit në historinë e të dyja llogarive
    llogarite[id1 - 1].historia += "Transferuar: -" + to_string(shuma) + " EUR tek llogaria " + to_string(id2) + "\n";
    llogarite[id2 - 1].historia += "Marre: +" + to_string(shuma) + " EUR nga llogaria " + to_string(id1) + "\n";

    cout << "Transferimi u krye me sukses!\n";
}


// Funksioni per te shfaqur historine e transaksioneve
void shfaqHistorine() {
    int id;
    cout << "Jepni ID e llogarise: ";
    cin >> id;

    while (!(id > 0 && id <= numriLlogarive && llogarite[id - 1].aktive)) {
        cout << "Llogaria nuk ekziston! Ju lutem provoni perseri: ";
        cin >> id;
    }

    cout << "Historia e transaksioneve:\n" << llogarite[id - 1].historia;
}


int main() {
    int zgjedhja;

    do {
        cout << "\n1. Hap Llogari\n2. Depozito\n3. Terheq\n4. Kontrollo Bilancin\n5. Shfaq Detajet\n6. Transfero Para\n7. Historia e Transaksioneve\n8. Dil\nZgjedhja juaj: ";
        cin >> zgjedhja;

        switch (zgjedhja) {
        case 1: krijoLlogari(); break;
        case 2: depozito(); break;
        case 3: terheq(); break;
        case 4: shfaqBilancin(); break;
        case 5: shfaqDetajet(); break;
        case 6: transfero(); break;
        case 7: shfaqHistorine(); break;
        case 8: cout << "Dalje...\n"; break;
        default: cout << "Zgjedhje e pavlefshme!\n";
        }
    } while (zgjedhja != 8);

    return 0;
}
