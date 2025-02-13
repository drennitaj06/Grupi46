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

int main()
{
    // Pika e hyrjes së programit, për momentin bosh
}
