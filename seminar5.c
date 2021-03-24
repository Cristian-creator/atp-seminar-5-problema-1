#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    int nrMatricol;
    char numePrenume[30];
    int grupa;
    char probaPractica;
    char puncte[10];
    char puncteExamen;
} STUDENT;

void creareFisier(FILE * myFile) {

    FILE * outputFile;
    STUDENT myStudent;

    char fileName[30];
    printf("numele fisierului: ");
    scanf("%s", fileName);

    outputFile = fopen(fileName, "w");

    if(!outputFile) printf("eroare");
    else {

        fprintf(outputFile, "numar matricol   nume si prenume               grupa  proba practica          puncte         puncte examen \n");

        fseek(myFile, 0, SEEK_SET);

        fread(&myStudent, sizeof(STUDENT), 1, myFile);

        while(!feof(myFile)) {

            fprintf(outputFile, "%-16i  %-30s %-5i %-14i ", myStudent.nrMatricol, myStudent.numePrenume, myStudent.grupa, myStudent.probaPractica);

            for(int i = 0;i < 10;i++) {
                fprintf(outputFile, "%i ", myStudent.puncte[i]);
            }

            fprintf(outputFile, " %i \n", myStudent.puncteExamen);
            
            fread(&myStudent, sizeof(STUDENT), 1, myFile);
        }

        fclose(outputFile);        

    }

}

void main() {

    FILE * myFile;

    char fileName[30];
    printf("numele fisierului: ");
    scanf("%s", fileName);
    
    myFile = fopen(fileName, "rb+");

    if(!myFile) printf("eroare");
    else {
        creareFisier(myFile);

        fclose(myFile);
    }

}