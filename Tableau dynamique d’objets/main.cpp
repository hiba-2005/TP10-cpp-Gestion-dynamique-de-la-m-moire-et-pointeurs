#include <iostream>
#include <string>
using namespace std;

class Livre {
private:
    string titre;
    float prix;

public:

    Livre() : titre("Inconnu"), prix(0.0f) {}


    Livre(string t, float p) : titre(t), prix(p) {}


    void saisir() {
        cout << "Titre du livre : ";
        getline(cin, titre);
        cout << "Prix du livre  : ";
        cin >> prix;
        cin.ignore();
    }

    void afficher() const {
        cout << "Titre : " << titre << " | Prix : " << prix << " DH" << endl;
    }
};

int main() {
    int n;

    cout << "=== Allocation dynamique d’un tableau d’objets Livre ===" << endl;
    cout << "Combien de livres voulez-vous créer ? ";
    cin >> n;
    cin.ignore(); // vider le tampon après lecture d’un entier

    if (n <= 0) {
        cout << "Nombre invalide de livres !" << endl;
        return 1;
    }

    Livre* tab = new Livre[n];

    cout << "\n--- Saisie des livres ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nLivre " << i + 1 << " :" << endl;
        tab[i].saisir();
    }


    cout << "\n--- Liste des livres saisis ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << ". ";
        tab[i].afficher();
    }


    delete[] tab;
    tab = nullptr;

    cout << "\nMémoire libérée avec succès !" << endl;

    return 0;
}
