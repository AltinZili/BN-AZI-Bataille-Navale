#include <stdio.h>
#include <windows.h>

#define longeur 10


int grille[longeur][longeur] = {
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        2, 2, 0, 0, 0, 0, 0, 0, 0, 0,
        3, 3, 3, 0, 0, 0, 0, 0, 0, 0,
        4, 4, 4, 4, 0, 0, 0, 0, 0, 0,
        5, 5, 5, 5, 5, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0

};


void aide() {
    printf("AIDE: \n\nLe but de cette bataille navale est de tirer sur des cases pour éliminer les bâteaux cachés dans la grille.\n"
           "la flotte est composée de 5 bateaux : 1 bateau de 5 cases, 1 bateau de 4 cases\n"
           "1 bateau de 3 cases, 1 bateau de 2 cases et un autre bateau de 1 cases. \n\n"
           "La grille est numérotée de A à J verticalement et de 1 à 10 horizontalement.\n"
           "Pour tirer sur une case il faut taper une position (exemple: A6) puis appuyer sur Enter.\n"
           "une vague (~) signifie qu'aucun bateau n'a été touché, une croix signifie qu'un bateau a été touché (X),\n"
           "un rond signifie qu'un bateau a été coulé (O).\n"
           "La partie est terminée une fois que tous les bateaux ont été coulés\n"
    );
}


#define STLC 218 // +, Single Top Left Corner
#define STRC 191 // +, Single Top Right Corner
#define SBLC 192 // +, Single Bottom Left Corner
#define SBRC 217 // +, Single Bottom Right Corner
#define SVSB 179 // ¦, Single Vertical Simple Border
#define SVRB 180 // ¦, Single Vertical Right Border
#define SVLB 195 // +, Single Vertical Left Border
#define SHSB 196 // -, Single Horizontal Simple Border
#define SHBB 193 // -, Single Horizontal Bottom Border
#define SHTB 194 // -, Single Horizontal Top Border
#define SC   197 // +, Single Center
#define TOUCHE 10

void topborder(int taille) {

    printf("     ");
    for (int j = 0; j < taille; ++j) {
        printf("%c   ", j + 'A');
    }
    printf("\n");
    printf("   %c", STLC);
    for (int i = 0; i < taille - 1; i++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SHTB);
    }
    printf("%c%c%c%c\n", SHSB, SHSB, SHSB, STRC);
}

void verticalborder(int taille, int numero) {



    char caractere = ' ';



    printf("%d ", numero + 1);
    if (numero < 9) {
        printf(" ");
    }
    int valeur_case;
    for (int i = 0; i < taille; i++) {

        if (grille[numero][i] > 10 && grille[numero][i] < 20) {
            caractere = 'X';
        }
        if (grille[numero][i] < 0) {
            caractere = '~';
        }

        if (grille[numero][i] > 20 && grille[numero][i] < 30) {
            caractere = 'O';
        }
        if (grille[numero][i] >= 0 && grille[numero][i] < 10) {
            caractere = ' ';
        }

        valeur_case = grille[numero][i];
        printf("%c %c ", SVSB, caractere);
    }
    printf("%c\n", SVSB);

}

void horizontalborder(int taille) {
    printf("   %c%c%c%c", SVLB, SHSB, SHSB, SHSB);
    for (int i = 0; i < taille - 1; i++) {
        printf("%c%c%c%c", SC, SHSB, SHSB, SHSB);
    }
    printf("%c \n", SVRB);
}

void bottomborder(int taille) {
    printf("   %c", SBLC);
    for (int i = 0; i < taille - 1; i++) {
        printf("%c%c%c%c", SHSB, SHSB, SHSB, SHBB);
    }
    printf("%c%c%c%c\n", SHSB, SHSB, SHSB, SBRC);
}


void affgrille() {
    SetConsoleOutputCP(65001); // For accented characters
    SetConsoleOutputCP(437); // For semi-graphic characters
    topborder(longeur);

    for (int row = 0; row < longeur; row++) {
        if (row > 0) {
            horizontalborder(longeur);
        }
        verticalborder(longeur, row);
    }

    bottomborder(longeur);

};


void jouer() {






    int x, y;
    int fin = 0;
    int compteur[5] = {0, 0, 0, 0, 0};
    char choix[2];
    while (fin < 1 + 2 + 3 + 4 + 5) {


        affgrille();
        printf("\n\n\nFaites votre tire :  ");
        scanf("%s", choix);

        x = choix[1] - 49;
        y = choix[0] - 97;

        if ((grille[x][y] > 0 && grille[x][y] < 10)) {
            if(grille[x][y] < 10)
            {
                fin++;
            }

grille[x][y]+= 10;

            if (grille[x][y] == 11) {
                compteur[0]++;

            }
            if (grille[x][y] == 12) {
                compteur[1]++;

            }


            if (grille[x][y] == 13) {
                compteur[2]++;

            }


            if (grille[x][y] == 14) {
                compteur[3]++;

            }


            if (grille[x][y] == 15) {
                compteur[4]++;
            }

        }
        if(compteur[0] == 1)
        {
            for (int i = 0; i < longeur; ++i) {
                for (int j = 0; j < longeur; ++j) {
                    if(grille[i][j] == 11)
                    grille[i][j]+=10;
                }
            }
        }
        if(compteur[1] == 2)
        {
            for (int i = 0; i < longeur; ++i) {
                for (int j = 0; j < longeur; ++j) {
                    if(grille[i][j] == 12)
                        grille[i][j]+=10;
                }
            }
        }
        if(compteur[2] == 3)
        {
            for (int i = 0; i < longeur; ++i) {
                for (int j = 0; j < longeur; ++j) {
                    if(grille[i][j] == 13)
                        grille[i][j]+=10;
                }
            }
        }
        if(compteur[3] == 4)
        {
            for (int i = 0; i < longeur; ++i) {
                for (int j = 0; j < longeur; ++j) {
                    if(grille[i][j] == 14)
                        grille[i][j]+=10;
                }
            }
        }
        if(compteur[4] == 5)
        {
            for (int i = 0; i < longeur; ++i) {
                for (int j = 0; j < longeur; ++j) {
                    if(grille[i][j] == 15)
                        grille[i][j]+=10;
                }
            }
        }
        if (grille[x][y] == 0) {
            grille[x][y] = -1;
        }

        system("cls");
        if(fin == 1 + 2 + 3 + 4 + 5)
        printf("\n"
               " _   _ _____ _____ _____ _____ ___________ _____ \n"
               "| | | |_   _/  __ \\_   _|  _  |_   _| ___ \\  ___|\n"
               "| | | | | | | /  \\/ | | | | | | | | | |_/ / |__  \n"
               "| | | | | | | |     | | | | | | | | |    /|  __| \n"
               "\\ \\_/ /_| |_| \\__/\\ | | \\ \\_/ /_| |_| |\\ \\| |___ \n"
               " \\___/ \\___/ \\____/ \\_/  \\___/ \\___/\\_| \\_\\____/ \n"
               "                                                 \n"
               "                                                 ");

    }

}

int main() {
#pragma execution_caracter_set("UTF-8")
    SetConsoleOutputCP(CP_UTF8); // For accented characters
    int choix;


    printf("1. Jouer\n"
           "2. Aide");
    scanf("%d", &choix);
    switch (choix) {
        case 1:
            jouer();

            printf("\n\n\n\n\n\n\n");
            system("pause");
            system("cls");
            main();
            break;
        case 2:
            aide();
            printf("\n\n\n\n\n\n\n");
            system("pause");
            system("cls");
            main();
            break;

        default:
            system("cls");
            main();
    }

    printf("\n\n\n\n\n\n\n");

    system("pause");
}