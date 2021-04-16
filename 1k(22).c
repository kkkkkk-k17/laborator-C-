
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int matrice[10][10];
int varfuri, muchii= 0;

typedef struct muchii{
    int v1;
    int v2;
    int id;
}arc;
arc a[100];

int VM(int min, int max, int i, int j) {
    int index;
    scanf("%d", &index);
    while (index < min || index > max) {
        printf("\nEroare\n");
        printf("\nVarful %d se duce la %d (1/0): ", i + 1, j + 1);
        scanf("%d", &index);
    }
    return index;
}

int VR(int min, int max, char text[50]) {
    int index;
    scanf("%d", &index);
    while (index < min || index > max) {
        printf("\nEroare\n%s: ", text);
        scanf("%d", &index);
    }
    return index;
}

int VL(int min, int max, int i) {
    int index;
    scanf("%d", &index);
    while (index < min || index > max) {
        printf("\nEroare\n");
        printf("\nVarful %d se duce la (0 - sfarsit): ", i + 1);
        scanf("%d", &index);
    }
    return index;
}


void IntroducereMatriceAdiacenta() {
    printf("Dati numarul de varfuri: ");
    scanf("%d",&varfuri);

    for (int i = 1; i <= varfuri; i++)
    {
        for (int j = 1; j <= varfuri; j++)
        {
            printf("Varful %d se duce la %d (1/0): ", i, j);
            matrice[i][j] = VM(0, 1, i, j);
            if (matrice[i][j] == 1) {
                muchii++;
                a[muchii].id = i;
                a[muchii].v1 = i;
                a[muchii].v2 = j;
            }
        }
        printf(" \n");
    }
}

void AfisareMatriceDeAdiacenta() {
    printf("\nMA  |");
    for (int i = 0; i < varfuri; i++) {
        printf(" x%d |", i + 1);
    }

     printf("\n----");
    for (int i = 0; i < varfuri; i++) {
        printf("----");
    }
    for (int i = 1; i <= varfuri; i++)
    {
        printf("\nx%-2d | ", i);
        for (int j = 1; j <= varfuri; j++)
        {
            if (matrice[i][j] == 1) {
                printf(" %d | ", matrice[i][j]);
            }
            else {
                printf(" 0 | ");
            }
        }
    }
}

void IntroducereMatriceIncidenta() {
    printf("Dati numarul varfuri: ");
    scanf("%d",&varfuri);
    int maxArce = varfuri * varfuri;
    int i = 1;
    do {
        printf("Introduceti coordonatele arcului %d (x,y): ", i);
        a[muchii].id = i;
        scanf("%d %d", &a[i].v1, &a[i].v2);
        if (a[i].v1 || a[i].v2) {
            matrice[a[i].v1][a[i].v1] = -1;
            matrice[a[i].v1][a[i].v2] = 1;
            muchii++;
            i++;
        }
        else break;
    } while (i <= maxArce);
}

void AfisareMatriceDeIncidenta() {
    printf("\nMI  |");
    for (int i = 0; i < varfuri; i++) {
        printf(" x%d  |", i + 1);
    }
    printf("\n----");
    for (int i = 0; i < varfuri; i++) {
        printf("-----");
    }
    for (int i = 1; i <=muchii; i++)
    {
        printf("\nu%-2d | ", i);
        for (int j = 1; j <= varfuri; j++)
        {
            if (a[i].v1 == j) {
                printf("-1  | ");
            }
            else if (a[i].v2 == j) {
                printf(" 1  | ");
            }
            else
                printf(" 0  | ");
        }
    }
}

void IntroducereListaAdiacenta() {
    printf("\nDati numarul de varfuri: ");
    scanf("%d",&varfuri);
    for (int i = 1; i <= varfuri; i++)
    {
        int n = 0, j = 1; // n - varful i, j - numarul de conxiuni la varf
        do {
            printf("Varful %d se duce la (0 - sfarsit): ", i);
            scanf("%d", &n);
            matrice[i][n] = 1;
            j++;
            if (n) {
                muchii++;
                a[muchii].id = i;
                a[muchii].v1 = i;
                a[muchii].v2 = n;
            }
        } while (n || j > varfuri);
        printf("\n");
    }
}

void AfisareListaDeAdiacenta() {
    printf("\nXi  | F(xi)\n----+");
    for (int i = 0; i < varfuri; i++) {
        printf("--");
    }
    printf("\n");
    for (int i = 1; i <= varfuri; i++)
    {
        printf("x%-3d| ", i);
        for (int j = 1; j <= varfuri + 1; j++)
        {
            if (matrice[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("0");
        printf("\n");
    }
}



int main() {
    int i,j;
    int numar,varfuri,muchii,d=1,r=0,l,MA[30][30],e=0,varf[30],LS[30][30],MI[30][30],v1[varfuri],v2[varfuri];;
    int k, v,cr,arc,x,y=0;


    printf("Alegeti modul de introducere: \n1.Lista de adiacenta.\n2.Matricea de adiacenta.\n3.Matricea de incidenta.\n4.exit\n");
    scanf("%d",&numar);

    switch(numar) {
    case 1:  IntroducereListaAdiacenta(); AfisareListaDeAdiacenta(); AfisareMatriceDeIncidenta();AfisareMatriceDeAdiacenta();break;
    case 2: IntroducereMatriceAdiacenta();AfisareMatriceDeAdiacenta() ;AfisareListaDeAdiacenta();AfisareMatriceDeIncidenta();break;
    case 3: IntroducereMatriceIncidenta();AfisareMatriceDeIncidenta(); AfisareListaDeAdiacenta();AfisareMatriceDeAdiacenta();break;


    }

     return 0;
}
