#include <iostream>
using namespace std;

int main() {
    int taille; // taille du tableau

    cout << "=== Allocation dynamique d'un tableau d'entiers ===" << endl;
    cout << "Entrez la taille du tableau : ";
    cin >> taille;

    // Vérification de la validité
    if (taille <= 0) {
        cout << "Taille invalide !" << endl;
        return 1;
    }

    //  Allocation dynamique du tableau
    int* tableau = new int[taille];

    // Remplissage du tableau
    cout << "\n--- Saisissez les " << taille << " valeurs ---" << endl;
    for (int i = 0; i < taille; i++) {
        cout << "Élément [" << i + 1 << "] : ";
        cin >> tableau[i];
    }

    //  Affichage du contenu
    cout << "\n--- Contenu du tableau ---" << endl;
    for (int i = 0; i < taille; i++) {
        cout << "tableau[" << i << "] = " << tableau[i] << endl;
    }

    // Libération de la mémoire
    delete[] tableau;
    tableau = nullptr;

    cout << "\nMémoire libérée avec succès !" << endl;

    return 0;
}
