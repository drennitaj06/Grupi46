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

int main()
{
    // Pika e hyrjes s� programit, p�r momentin bosh
}
