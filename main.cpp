#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#include "funcs.h"
#include "sorts.h"
#include "comparator.h"

#define in_fi "poem.txt"
#define out_fi "sigma_poem.txt"

void ADD_to_TXT(const char* const* onegin, int count, int cond);

int main() {
    int onegin_descr = open(in_fi, O_RDONLY);

    struct stat onegin_info;
    fstat(onegin_descr, &onegin_info);

    FILE* onega_stream = fdopen(onegin_descr, "r");

    char* onegin_bufff = (char*)calloc(onegin_info.st_size + 1, sizeof(char));//struct
    //printf("Buffer ptr: %p", onegin_bufff);

    size_t bytes_read = fread(onegin_bufff, sizeof onegin_bufff[0], onegin_info.st_size, onega_stream);
    //printf("sex\n");

    onegin_bufff[bytes_read] = '\0';

    // printf("\nBuffer contents:\n");
    // for (int i = 0; i < onegin_info.st_size; i++)
    //     putchar(onegin_bufff[i]);

    //printf("%d\n", onegin_info.st_size);

    char* trolley = onegin_bufff;
    char* marker = 0;
    int count = 0;
    while ((trolley - 1) != NULL) {
        //printf("sex\n");
        marker = strchr(trolley, '\n');
        if(marker != 0)
            *marker = '\0';
        trolley = marker + 1;
        //printf("Strchr pointer: %p\n", trolley);
        count++;
    }
    trolley = onegin_bufff;

    //printf("String count: %d\n", count);
    char** onegin_ptr = (char**)calloc(count, sizeof(char*));
    onegin_ptr[0] = onegin_bufff;

    for (int i = 1; (i < count) && ((trolley - 1) != NULL); i++) {
        marker = strchr(trolley, '\0');
        trolley = marker + 1;
        if (marker != NULL) {
            onegin_ptr[i] = trolley;
        }
    }
    // printf("\nPrint of ptr massive:\n");
    // for (int i = 0; i < count; i++)
    //     printf("%p : %s\n", *onegin_ptr[i], onegin_ptr[i]);

    FILE* clear_file = fopen(out_fi, "w");
    fclose(clear_file);

    int cond = 0;
    BUBBLEGUM_straight(onegin_ptr, count);
    cond = 0;
    ADD_to_TXT((const char* const*)onegin_ptr, count, cond);

    // printf("\nPrint of ptr massive:\n");
    // for (int i = 0; i < count; i++)
    //     printf("%p : %s\n", onegin_ptr[i], onegin_ptr[i]);

    BUBBLEGUM_back(onegin_ptr, count);
    cond = 1;
    ADD_to_TXT((const char* const*)onegin_ptr, count, cond);

    // printf("\nPrint of ptr massive:\n");
    // for (int i = 0; i < count; i++)
    //     printf("%p : %s\n", onegin_ptr[i], onegin_ptr[i]);

    qsort(onegin_ptr, count, sizeof(char*), CompareStr);
    cond = 2;
    ADD_to_TXT((const char* const*)onegin_ptr, count, cond);

    free(onegin_bufff);
    free(onegin_ptr);
}

void ADD_to_TXT(const char* const* onegin, int count, int cond) {

    FILE* onega_out = fopen(out_fi, "a");

    // printf("\nPrint of ptr massive:\n");
    // for (int i = 0; i < count; i++)
    //     printf("%p : %s\n", onegin_ptr[i], onegin_ptr[i]);
    switch(cond) {
    case 0: fprintf(onega_out, "\nENCYCLOPEDIA OF RUSSIAN LIFE:\n");
            break;
    case 1: fprintf(onega_out, "\nENCYCLOPEDIA OF RUSSIAN RHYMES:\n");
            break;
    case 2: fprintf(onega_out, "\nENCYCLOPEDIA OF RUSSIAN LIFE BY QSORT:\n");
    }

    for (int i = 0; i < count; i++) {
        fprintf(onega_out, "%s\n", onegin[i]);
        //printf("%s\n", onegin_ptr[i]);
    }

    fclose(onega_out);
}
