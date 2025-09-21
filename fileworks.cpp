#include "fileworks.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define out_fi "sigma_poem.txt"

int Read_File(int input_descr, char** bufff) {
    struct stat input_info;
    fstat(input_descr, &input_info);
    //printf("%d\n", input_info.st_size);
    //printf("Describtor2: %d\n", input_descr);

    FILE* input_stream = fdopen(input_descr, "r");

    *bufff = (char*)calloc(input_info.st_size + 1, sizeof(char));//struct
    //printf("Buffer ptr: %p", onegin_bufff);

    size_t bytes_read = fread(*bufff, sizeof (*bufff)[0], input_info.st_size, input_stream);
    //printf("sex\n");

    (*bufff)[bytes_read] = '\0';
    return bytes_read;
}

void ADD_to_File(const char* const* onegin, int count, int cond) {

    FILE* onega_out = fopen(out_fi, "a");
    // printf("\nPrint of ptr massive:\n");
    // for (int i = 0; i < count; i++)
    //     printf("%p : %s\n", onegin[i], onegin[i]);

    Print_Title_to_File(onega_out, cond);

    for (int i = 0; i < count; i++) {
        fprintf(onega_out, "%s\n", onegin[i]);
        //printf("fprintf str: %s\n", onegin[i]);
    }
    fclose(onega_out);
}

void Print_Title_to_File(FILE* out_file, int cond) {
    switch(cond) {
    case 0: fprintf(out_file, "\nENCYCLOPEDIA OF RUSSIAN LIFE:\n");
            break;
    case 1: fprintf(out_file, "\nENCYCLOPEDIA OF RUSSIAN RHYMES:\n");
            break;
    case 2: fprintf(out_file, "\nENCYCLOPEDIA OF RUSSIAN LIFE BY QSORT:\n");
            break;
    case 3: fprintf(out_file, "\nENCYCLOPEDIA OF RUSSIAN RHYMES BY QSORT:\n");
            break;
    }
}
