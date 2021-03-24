#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    char is;
    int nrMatricol;
    char numePrenume[25];
    int grupa;
    char an;
    struct {
        char curs;
        char seminar;
    } discipline[15];
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

        fprintf(outputFile, "numar matricol   nume si prenume   grupa  an  absente \n");

        fseek(myFile, 0, SEEK_SET);

        fread(&myStudent, sizeof(STUDENT), 1, myFile);

        while(!feof(myFile)) {

            if(myStudent.is) {

                fprintf(outputFile, "%-16i  %-30s %-5i %-14i ", myStudent.nrMatricol, myStudent.numePrenume, myStudent.grupa, myStudent.an);

                for(int i = 0;i < 15;i++) {
                    fprintf(outputFile, "%i %i ", myStudent.discipline[i].curs, myStudent.discipline[i].seminar);
                }

                fprintf(outputFile, "\n");
            }        
            
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