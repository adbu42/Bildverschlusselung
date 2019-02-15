#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    const long sizepu = 500*500;  // max. Bildgröße
    FILE *Bildfile;
    int puffer[sizepu];  // Puffer für Bilder

    char *hallo; // Nachricht
    char *code; // Code
    int spe = 0;  // Zähler bei malloc code/hallo
    char car;  // char für hallo
    char car2;   // char für code

    char dateipfad[100];  // Dateipfad Originalbild
    char dateipfad2[100];    // Dateipfad verschlüsseltes Bild

    int i;  // for-Schleife
    int j = 0;  // Hochzählen Nachricht
    int h = -1;  // Hochzählen Code

    // Nachricht Eingabe
    printf("Geben sie die Nachricht ein:");

    hallo = malloc(sizeof(char));
    while(scanf("%c", &car)&&car!= 10){
        hallo = realloc((void *)hallo, (spe+1)*sizeof(char));
        hallo[spe] = car;
        spe++;
    }

    // Code Eingabe
    printf("\nCode eingeben:\n");
    spe = 0;
    code = malloc(sizeof(char));

    while(scanf("%c", &car2)&&car2!= 10){
        code = realloc((void *)code, (spe+1)*sizeof(char));
        code[spe] = car2;
        spe++;
    }

    // Originalbild einlesen
    printf("\nGeben sie den Dateipfad an (bsp: C:\\Bildordner\\70.bmp):\n");
    scanf("%s", dateipfad);
    if(Bildfile = fopen(dateipfad, "r+b")){
        printf("Bin offen ");
        fread(puffer, sizeof(int), sizepu, Bildfile);
    }
    else{
        printf("fehlgeschlagen ");
    }
    fclose(Bildfile);

    // Verschlüsselung
    for(i=50; i<=strlen(hallo)*122; i += code[h]){
        h++;
        if(h == strlen(code)-1) h = 0;
        puffer[i] = puffer[i] + hallo[j]-65;
        j++;
    }

    free(code);

    // In Bild verschlüsseln
    printf("\n\n%s", hallo);
    printf("\nDateipfad der Zieldatei eingeben:\n");
    scanf("%s", dateipfad2);
    if(Bildfile = fopen(dateipfad2, "w+")){
        printf("Bin offen2 ");
        fwrite(puffer, sizeof(int), sizepu, Bildfile);
    }
    else{
        printf("schreiben fehlgeschlagen ");
    }
    return 0;
}
