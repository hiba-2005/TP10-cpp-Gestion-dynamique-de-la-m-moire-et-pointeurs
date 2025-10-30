#include <iostream>
using namespace std;

int main() {
    int taille; // taille du tableau

    cout << "=== Allocation dynamique d'un tableau d'entiers ===" << endl;
    cout << "Entrez la taille du tableau : ";
    cin >> taille;

    // V�rification de la validit�
    if (taille <= 0) {
        cout << "Taille invalide !" << endl;
        return 1;
    }

    //  Allocation dynamique du tableau
    int* tableau = new int[taille];

    // Remplissage du tableau
    cout << "\n--- Saisissez les " << taille << " valeurs ---" << endl;
    for (int i = 0; i < taille; i++) {
        cout << "�l�ment [" << i + 1 << "] : ";
        cin >> tableau[i];
    }

    //  Affichage du contenu
    cout << "\n--- Contenu du tableau ---" << endl;
    for (int i = 0; i < taille; i++) {
        cout << "tableau[" << i << "] = " << tableau[i] << endl;
    }

    // Lib�ration de la m�moire
    delete[] tableau;
    tableau = nullptr;

    cout << "\nM�moire lib�r�e avec succ�s !" << endl;

    return 0;
}
