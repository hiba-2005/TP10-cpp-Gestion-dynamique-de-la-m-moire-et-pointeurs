#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Contact {
    string nom;
    string telephone;
    string email;

public:
    Contact(const string& n, const string& t, const string& e)
        : nom(n), telephone(t), email(e) {}

    const string& getNom() const { return nom; }

    void afficher() const {
        cout << "Nom: " << nom
             << " | Téléphone: " << telephone
             << " | Email: " << email << '\n';
    }
};



static void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


void ajouterContact(Contact**& carnet, int& n, Contact* c) {
    Contact** nouveau = new Contact*[n + 1];
    for (int i = 0; i < n; ++i) {
        nouveau[i] = carnet[i];
    }
    nouveau[n] = c;
    delete[] carnet;
    carnet = nouveau;
    ++n;
}


void afficherCarnet(Contact* const* carnet, int n) {
    if (n == 0) {
        cout << "(Carnet vide)\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        cout << (i + 1) << ". ";
        carnet[i]->afficher();
    }
}

bool supprimerContact(Contact**& carnet, int& n, const string nom) {
    if (n == 0 || carnet == nullptr) return false;

    int idx = -1;
    for (int i = 0; i < n; ++i) {
        if (carnet[i]->getNom() == nom) {
            idx = i;
            break;
        }
    }
    if (idx == -1) return false;


    delete carnet[idx];
    carnet[idx] = nullptr;


    for (int i = idx; i < n - 1; ++i) {
        carnet[i] = carnet[i + 1];
    }


    Contact** nouveau = nullptr;
    if (n - 1 > 0) {
        nouveau = new Contact*[n - 1];
        for (int i = 0; i < n - 1; ++i) {
            nouveau[i] = carnet[i];
        }
    }

    delete[] carnet;
    carnet = nouveau;
    --n;

    return true;
}

void libererCarnet(Contact**& carnet, int& n) {
    if (carnet == nullptr) { n = 0; return; }
    for (int i = 0; i < n; ++i) {
        delete carnet[i];
        carnet[i] = nullptr;
    }
    delete[] carnet;
    carnet = nullptr;
    n = 0;
}


Contact* saisirContactInteractif() {
    string nom, tel, mail;

    cout << "Nom        : ";
    getline(cin, nom);
    cout << "Téléphone  : ";
    getline(cin, tel);
    cout << "Email      : ";
    getline(cin, mail);


    return new Contact(nom, tel, mail);
}

int main() {
    Contact** carnet = nullptr;
    int n = 0;

    int choix = -1;
    while (choix != 0) {
        cout << "\n=== Carnet d'adresses (Contact**) ===\n"
             << "1) Ajouter un contact\n"
             << "2) Afficher tous les contacts\n"
             << "3) Supprimer un contact (par nom)\n"
             << "0) Quitter\n"
             << "Votre choix: ";
        if (!(cin >> choix)) { clearInput(); continue; }
        clearInput();

        switch (choix) {
            case 1: {
                cout << "\n--- Ajout d'un contact ---\n";
                Contact* c = saisirContactInteractif();
                ajouterContact(carnet, n, c);
                cout << "Contact ajouté. Total = " << n << '\n';
                break;
            }
            case 2: {
                cout << "\n--- Liste des contacts ---\n";
                afficherCarnet(carnet, n);
                break;
            }
            case 3: {
                cout << "\nNom exact du contact à supprimer: ";
                string cible; getline(cin, cible);
                bool ok = supprimerContact(carnet, n, cible);
                if (ok) cout << "Contact supprimé. Total = " << n << '\n';
                else    cout << "Aucun contact portant ce nom.\n";
                break;
            }
            case 0: {
                cout << "Fermeture du carnet...\n";
                break;
            }
            default:
                cout << "Choix invalide.\n";
        }
    }


    libererCarnet(carnet, n);
    cout << "Mémoire libérée. Au revoir !\n";
    return 0;
}
