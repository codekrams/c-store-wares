#include <stdio.h>
#include <stdlib.h>
#define ANZAHL 2

struct artikel {
    char artbezeichnung[100];
    float preis;
    float menge;
    char einheit[100];
};

typedef struct artikel ARTIKEL;


int main()
{

    ARTIKEL artikel[ANZAHL];

    int i;
    for (i=0; i<ANZAHL; i++){
        printf("Bitte geben Sie die Bezeichnung des %d. Artikels ein:\n", i+1);
        scanf("%s", artikel[i].artbezeichnung);

        printf("\nBitte geben Sie den Preis in Euro ein:\n");
        scanf("%f", &artikel[i].preis);

        printf("\nBitte geben Sie die Menge ein:\n");
        scanf("%f", &artikel[i].menge);

        printf("\nBitte geben Sie die Einheit ein:\n");
        scanf("%s", artikel[i].einheit);
            }
    printf("Ihre Eingaben:");
    int m;
    for (m=0; m<ANZAHL; m++){
        printf("\nArtikelbezeichnung: %s\nPreis in Euro: %f\nMenge: %f\nEinheit: %s\n",
                artikel[m].artbezeichnung, artikel[m].preis, artikel[m].menge, artikel[m].einheit);
    }

    FILE *artikeldatei;
    artikeldatei= fopen("artikeldatei.dat", "w");
    fwrite(artikel, sizeof(ARTIKEL), ANZAHL, artikeldatei);
    fclose(artikeldatei);

    artikeldatei=fopen("artikeldatei.dat", "rb");
    fread(artikel, sizeof(ARTIKEL), ANZAHL, artikeldatei);
    int j;
    for (j=0; j<ANZAHL; j++){
        printf("%s", artikel[j].artbezeichnung);
        printf("%f", &artikel[j].preis);
        printf("%f", &artikel[j].menge);
        printf("%s", artikel[j].einheit);
    }
    fclose(artikeldatei);


 return 0;
}
