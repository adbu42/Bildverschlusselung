#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    const long sizepu = 500*500; // max. Bildgr��e
    FILE *Bildfile;

    int puffer[sizepu];  // Puffer f�r verschl�sseltes Bild
    int puffer2[sizepu];  // Puffer f�r Originalbild

    char *ausgabe;
    char *code;

    char car;  // Char f�r malloc Reservierung (Code)
    int spe = 0;  // Hochz�hlen f�r malloc Reservierung (Code)

    char dateipfad[100]; // Dateipfad verschl�sseltes Bild
    char dateipfad2[100];  // Dateipfad Originalbild

    int i; // Hochz�hlen for-Schleife
    int j = 0;  // Hochz�hlen der Ausgabe
    int h = 0;  // Hochz�hlen Code


    // Code Eingabe
    code = malloc(sizeof(char));
    printf("\nBitte code eingeben:\n");
    while(scanf("%c", &car)&&car!= 10){
        code = realloc((void *)code, (spe+1)*sizeof(char));
        code[spe] = car;
        spe++;
    }


    // Verschl�sseltes Bild einlesen
    printf("\nGeben sie den Dateipfad des verschlusselten Bildes an (bsp: C:\\Bildordner\\70.bmp):\n");
    scanf("%s", dateipfad);

    if(Bildfile = fopen(dateipfad, "r+b")){
        printf("Bin offen ");
        fread(puffer, sizeof(int), sizepu, Bildfile);
    }
    else{
        printf("fehlgeschlagen ");
    }
    fclose(Bildfile);


    // Originalbild einlesen
    printf("\nGeben sie den Dateipfad des Originalbildes an (bsp: C:\\Bildordner\\70.bmp):\n");
    scanf("%s", dateipfad2);

        if(Bildfile = fopen(dateipfad2, "r+b")){
        printf("Bin offen ");
        fread(puffer2, sizeof(int), sizepu, Bildfile);
    }
    else{
        printf("fehlgeschlagen ");
    }
    fclose(Bildfile);


    // Bildvergleich und Entschl�sselung
    i = 50;  // i 0-49 sind Informationsdaten, keine Bilddaten
    spe = 1; // Speicher am Anfang auf 1 setzen

    ausgabe = malloc(spe*sizeof(char));
    do{
        realloc((void *)ausgabe, (spe+1)*sizeof(char));
        ausgabe[j] = puffer[i]-puffer2[i]+65;  // Verschl�sselung r�ckg�ngig machen
        j++;
        i += code[h];
        h++;
        if(h == strlen(code)-1) h = 0;
    }while(puffer2[i] != puffer[i]);

    printf("\n");

    for(i = 0; i<=j; i++){
       printf("%c", ausgabe[i]);
   }

    free(ausgabe);
    free(code);
    printf("Geben sie einen Buchstaben ein");
    char a[2];
    scanf("%s", &a);

    return 0;
}
