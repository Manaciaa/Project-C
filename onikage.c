#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // NEW LINE
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


// création de la structure du personnage 


struct personnage {
    char nom[50];
    int pv;
    int dps;
    int level;
    bool vivant;
};


// création de la structure du boss 


struct boss {
    char nom[50];
    int pv;
    int dps;
    int level;
    bool vivant;
};


int main() {

    int choix; // variable servant à stocker le choix de l'utilisateur 
    choix = 0;


    // initialisation du personnage nommé " onikage "

    struct personnage onikage;
    strcpy(onikage.nom, "onikage");
    onikage.pv = 500;
    onikage.dps = 100;
    onikage.level = 20;
    onikage.vivant = true;

    // Initialisation du boss "Taureau"

    struct boss taureau;
    strcpy(taureau.nom, "taureau");
    taureau.pv = 1000;
    taureau.dps = 150;
    taureau.level = 20;
    taureau.vivant = true;

    //message pour introduire le combat 

    printf("Ikuzo Onikage ! \n");


    // Boucle pour le combat 

    while (taureau.vivant && onikage.vivant) {

        // affichage des choix possibles pour l'utilisateur

        printf("choisissez une action :\n 1 : esquiver, 2 : attaquer ou 3 : se soigner\n");
        scanf("%d", &choix);

        if (choix == 1) {
            printf("Onikage fait une roulade et esquive l'attaque ! \n");
        }

        else if (choix == 2) {
            taureau.pv = taureau.pv - onikage.dps;
            printf("Le taureau prend des degats, il lui reste %d PV\n", taureau.pv);
            onikage.pv = onikage.pv - taureau.dps;
            printf("Onikage prend des degats, il lui reste %d PV\n", onikage.pv);

        }

        else if (choix == 3) {

         // Onikage réstaure tout ses PV
         onikage.pv = 500;
         printf("Onikage se soigne et recupere tous ses PV\n");

        // Vérification des points de vie pour déterminer si les personnages sont toujours vivants
        }
        if (onikage.pv <= 0) {
            printf("Vous etes mort");
            onikage.vivant = false;
        }

        if (taureau.pv <= 0) {
            printf("Bravo Onikage a vaincu le taureau ! ");
            taureau.vivant = false;
        }

    }

    return 0;

}