# Menaxhimi i Llogarive Bankare


## Përshkrimi

Ky projekt është një program i zhvilluar në gjuhën C++ që simulon një sistem të thjeshtë për menaxhimin e llogarive bankare. Përdoruesit mund të krijojnë llogari, të kryejnë depozitime dhe tërheqje, të transferojnë para midis llogarive dhe të shohin historinë e transaksioneve.

**Ky projekt është zhvilluar nga një grup prej 4 studentësh të Fakultetit të Inxhinierisë Elektrike dhe Kompjuterike (Departamenti IKS).** 🎓


## Funksionalitetet

- ✅ Hapja e një llogarie të re (Me ID unike)  
- ✅ Depozitimi i parave  
- ✅ Tërheqja e parave  
- ✅ Kontrollimi i bilancit të llogarisë  
- ✅ Shfaqja e detajeve të llogarisë  
- ✅ Transferimi i parave midis llogarive  
- ✅ Shfaqja e historisë së transaksioneve  
- ✅ Mbyllja e programit në mënyrë të sigurt  


## Instalimi dhe Përdorimi

1. **Klono projektin nga GitHub**:  
   ```bash
   git clone https://github.com/username/repository-name.git
   cd repository-name

2. **Kompilimi dhe Ekzekutimi**:

### Në Linux/Mac:
```bash
g++ -o bank_system bank_system.cpp
./bank_system

### Në Windows(përdorimi i MinGW):
```bash
g++ -o bank_system bank_system.cpp
bank_system.exe

3. **Ndjekja e menusë**:

Pas ekzekutimit, përdoruesi mund të ndjekë opsionet e menusë për të kryer operacione bankare.


## Struktura e kodit

struct Llogari – Struktura për ruajtjen e të dhënave të një llogarie.
krijoLlogari() – Funksioni për hapjen e një llogarie të re.
depozito() – Funksioni për depozitimin e parave në një llogari ekzistuese.
terheq() – Funksioni për tërheqjen e parave nga një llogari.
shfaqBilancin() – Funksioni për të parë bilancin aktual të një llogarie.
shfaqDetajet() – Funksioni për të shfaqur detajet e një llogarie.
transfero() – Funksioni për transferimin e parave midis llogarive.
shfaqHistorine() – Funksioni për të parë historinë e transaksioneve.


## Përmirësime të mundshme

📌 Ruajtja e të dhënave në një skedar për të shmangur humbjen e informacionit pas mbylljes së programit.
📌 Përdorimi i një baze të dhënash për menaxhimin më efikas të llogarive.
📌 Shtimi i një ndërfaqeje grafike për një përvojë më të mirë të përdoruesit.
📌 Implementimi i sigurisë me kredenciale për hyrje.


## Kontributi
Nëse dëshironi të kontribuoni në këtë projekt:

1. **Fork repository-n**.  
2. Krijoni një **branch** të ri:  
   ```bash
   git checkout -b emri-i-funksionalitetit
3. Kryeni ndryshimet dhe bëni commit:
   ```bash
   git commit -m "Shtova funksionalitetin X"
4. Dërgoni ndryshimet në GitHub:
   git push origin emri-i-funksionalitetit
5. Hapni një pull request


## Autorët
Dren Nitaj
Diart Nika
Ndrit Osmani
Lind Mjekiqi
