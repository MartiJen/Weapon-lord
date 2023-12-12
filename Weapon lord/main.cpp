#include <cstdio>
#include <iostream>
#include<string>
#include <limits>
#include "Knight.h"
#include "Orc.h"
using namespace std;

// Déclaration des fonction pour chaque partie du jeu
void FirstPart();
void SecondPart();

void ShowTitleScreen() {
    cout << "========================================\n";
    cout << "               Weapon Lord              \n";
    cout << "========================================\n";
    cout << "1. Première partie : Simulation de combat\n";
    cout << "2. Seconde partie : Ajout d'options au jeu\n";
    cout << "3. Quittter\n";
    cout << "Veuillez choisir une option : ";
}

int main()
{
    while (true) {
        ShowTitleScreen();

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorer l'entrée précédente
            cout << "Veuillez enter un nombre valide.\n";
            continue;
        }

        switch (choice) {
        case 1:
            FirstPart();
            break;
        case 2:
            SecondPart();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Option non valide, veullez réessayer.\n";
            break;
        }
    }
    return 0;
}

void FirstPart() {
    Knight knight;
    Orc orc;
    int turnCounter = 1;

    cout << "La bataille Commence !" << endl;

    while (knight.IsAlive() && orc.IsAlive()) {
        cout << "Début du tour " << turnCounter << " !" << endl;
        
        // Tour du chevalier
        if (knight.TrySpecialAttack(orc)) {
            knight.UseSpecialAbility(orc);
        }
        else {
            knight.PerformAttack(orc);
        }

        // Réponse de l'orc
        if (orc.IsAlive()) {
            if (orc.TryStunAttack()) {
                orc.UseSpecialAbility(knight);
            }
            else {
                orc.PerformAttack(knight);
            }
        }

        // Incrémentation du nombre de tours
        turnCounter++;

        // Affichage des statuts après le tours
        knight.DisplayStatus();
        orc.DisplayStatus();

        // Virtoire
        if (!knight.IsAlive()) {
            cout << "L'orc a gagné !" << endl;
        }
        else if (!orc.IsAlive()){
            cout << "Le chevalier à gagné !" << endl;
        }
    }
}