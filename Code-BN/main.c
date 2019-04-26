#include <stdio.h>
#include <windows.h>




int main() {
#pragma execution_caracter_set("UTF-8")
    SetConsoleOutputCP(CP_UTF8); // For accented characters
    int choix;



    printf("1. Jouer\n"
           "2. Aide");
    scanf("%d", &choix);
    switch (choix)
    {
        case 2:     printf("AIDE: \n\nLe but de cette bataille navale est de tirer sur des cases pour éliminer les bâteaux cachés dans la grille.\n"
                           "la flotte est composée de 5 bateaux : 1 bateau de 5 cases, 1 bateau de 4 cases\n"
                           "1 bateau de 3 cases, 1 bateau de 2 cases et un autre bateau de 1 cases. \n\n"
                           "La grille est numérotée de A à J verticalement et de 1 à 10 horizontalement.\n"
                           "Pour tirer sur une case il faut taper une position (exemple: A6) puis appuyer sur Enter.\n"
                           "une vague (~) signifie qu'aucun bateau n'a été touché, une croix signifie qu'un bateau a été touché (X),\n"
                           "un rond signifie qu'un bateau a été coulé (O).\n"
                           "La partie est terminée une fois que tous les bateaux ont été coulés\n"
            );
            printf("\n\n\n\n\n\n\n");
            system("pause");
            system("cls");
            main();

        default:
            system("cls");
            main();
    }

    printf("\n\n\n\n\n\n\n");
    system("pause");
}