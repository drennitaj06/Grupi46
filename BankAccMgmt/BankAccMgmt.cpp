/ Funksioni per terheqjen e parave
void terheq() {
    int id;
    double shuma;
    cout << "Jepni ID e llogarise: ";
    cin >> id;

    if (id <= 0 || id > numriLlogarive || !llogarite[id - 1].aktive) {
        cout << "Llogaria nuk ekziston!\n";
        return;
    }

    cout << "Shuma per terheqje: ";
    cin >> shuma;

    if (shuma <= 0 || shuma > llogarite[id - 1].bilanci) {
        cout << "Shuma nuk eshte e vlefshme!\n";
        return;
    }

    llogarite[id - 1].bilanci -= shuma;
    llogarite[id - 1].historia += "Terheqje: -" + to_string(shuma) + " EUR\n";
    cout << "Terheqja u krye me sukses!\n";
}