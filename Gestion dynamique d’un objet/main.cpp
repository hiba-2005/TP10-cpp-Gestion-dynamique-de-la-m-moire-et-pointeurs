#include <iostream>
#include <string>
using namespace std;

class Personne {
private:
    string nom;
    int age;

public:

    Personne(string n, int a) : nom(n), age(a) {
        cout << "Constructeur : Objet Personne cree!" << endl;
    }


    void afficher() const {
        cout << "Nom : " << nom << ", Age : " << age << " ans" << endl;
    }


    ~Personne() {
        cout << "Destructeur : Objet Personne détruit !" << endl;
    }
};

int main() {
    cout << "=== Allocation dynamique d’un objet Personne ===" << endl;

    //  Allocation dynamique d’un objet Personne
    Personne* p1 = new Personne("Ouirouane HiBa", 20);

    // Utilisation du pointeur
    cout << "\n--- Affichage des informations ---" << endl;
    p1->afficher();

    // Libération de la mémoire
    delete p1;
    p1 = nullptr;

    cout << "\nMemoire liberee avec succes !" << endl;

    return 0;
}
