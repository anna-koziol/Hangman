#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>


typedef enum {
    it = 1,
    ek = 2,
    ow = 3
} Kategorie;


int losowanie(int ilosc_wyrazow) {
    system("cls");
    srand((unsigned int)time(0));
    int liczba_los = rand() % (ilosc_wyrazow);
    return liczba_los;
}


void wisielec(int liczba_los, char** tab) {
    printf("WYLOSOWANY WYRAZ: %s \n\n", tab[liczba_los]);
    printf("Podaj kolejne male litery, aby odgadnac wyraz\n");
    char n;
    int dl_wylosowanego_wyrazu = strlen(tab[liczba_los]);
    int punkty = 0, proba = 0, zycia = 12;
    bool wygrana = false, znalezione = false;
    int i = 0, j = 0;

    char* a;
    a = (char*)malloc(dl_wylosowanego_wyrazu * sizeof(*a));
    for (int i = 0; i < dl_wylosowanego_wyrazu; ++i) {
        a[i] = '_';
    }

    do {
        n = _getch();
        for (i = 0; i < dl_wylosowanego_wyrazu; i++) {
            if (n == tab[liczba_los][i]) {
                a[i] = tab[liczba_los][i];
                ++punkty;
                znalezione = true;
            }
        }
        if (!znalezione) {
            --zycia;
            printf("Zostaly ci zycia %d/12 \n", zycia);
        }

            
        proba++;
        for (j = 0; j < dl_wylosowanego_wyrazu; j++) {
            printf("%c", a[j]);
        };
        printf("\n");
        j = 0;
        i = 0;
        znalezione = false;

        if (punkty == dl_wylosowanego_wyrazu) {
            printf("Super, wygrales w %d ruchach! \n", proba);
            wygrana = true;
            break;
        }
        printf("Punkty %d dlugosc wyrazu %d\n", punkty, dl_wylosowanego_wyrazu);
    } while ((zycia >= 1) && (!wygrana));

    if (punkty < dl_wylosowanego_wyrazu) { printf("Tym razem sie nie udalo, zdobyles %d/%d punktow", punkty, dl_wylosowanego_wyrazu);  }

    free(a);
}

int main(void)
{
    //glowne zmienne
    char* napisy[] = { "informatyka", "programowanie", "rzutowanie", "komputery", "rekurencja", "obiekt", "klasa", "kompilator", "tablica" };
    char* owoce[] = { "banan","kiwi", "liczi", "ananas", "cytryna", "gruszka", "brzoskwinia" };
    char* ekonomia[] = { "pkb", "mediana", "aktywa", "bank",  "bessa", "biznesplan",  "dywidendy", "finanse", "inflancja", "popyt" };
    int wybor_kategorii;
    int liczba_los = 0, ilosc_wyrazow = 0;

    //wybor kategorii
    printf("Wybierz kategorie slow do odgadniecia (1 - informatyka, 2 - ekonomia, 3 - owoce): ");

    if (scanf_s("%d", &wybor_kategorii) < 1) {
        printf("Niepoprawne dane.\n");
        return;
    }
        //gra
        switch (wybor_kategorii) {
        case it:
            printf("WESZLO.\n");
            ilosc_wyrazow = sizeof(napisy) / sizeof(int);
            liczba_los = losowanie(ilosc_wyrazow);
            wisielec(liczba_los, napisy);
            break;
        case ek:
            ilosc_wyrazow = sizeof(ekonomia) / sizeof(int);
            liczba_los = losowanie(ilosc_wyrazow);
            wisielec(liczba_los, ekonomia);
            break;
        case ow:
            ilosc_wyrazow = sizeof(owoce) / sizeof(int);
            liczba_los = losowanie(ilosc_wyrazow);
            wisielec(liczba_los, owoce);
            break;
        }


    printf("\n\n");
    system("PAUSE");
}