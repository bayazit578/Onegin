#include "sorts.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcs.h"
#include "supportive.h"
#include "fileworks.h"
#include "comparator.h"
#include "struct.h"

// int (*a)(const void*, const void*)
void Run_Sorts(string* str, size_t count, FILE* out_file, char* bufff, size_t bytes_read) {
    char* title = {};

    BUBBLEGUM(str, count, CompareStr);
    title = "\nENCYCLOPEDIA OF RUSSIAN LIFE:\n";
    Add_to_File(str, title, count, out_file);
    // printf("\nPrint of ptr massive:\n");
    // for (int i = 0; i < count; i++)
    //     printf("%p : %s\n", onegin_ptr[i], onegin_ptr[i]);

    BUBBLEGUM(str, count, CompareStr_back);
    title = "\nENCYCLOPEDIA OF RUSSIAN RHYMES:\n";
    Add_to_File(str, title, count, out_file);
    // printf("\nPrint of ptr massive:\n");
    // for (int i = 0; i < count; i++)
    //     printf("%p : %s\n", onegin_ptr[i], onegin_ptr[i]);

    qsort(str, sizeof(str)/sizeof(str[0]), sizeof(string), CompareStr);
    title = "\nENCYCLOPEDIA OF RUSSIAN LIFE QSORT:\n";
    Add_to_File(str, title, count, out_file);
    // printf("\nPrint of ptr massive:\n");
    // for (int i = 0; i < count; i++)
    //     printf("%p : %s\n", onegin_ptr[i], onegin_ptr[i]);

    qsort(str, sizeof(str)/sizeof(str[0]), sizeof(string), CompareStr_back);
    title = "\nENCYCLOPEDIA OF RUSSIAN RHYMES QSORT:\n";
    Add_to_File(str, title, count, out_file);
    // printf("\nPrint of ptr massive:\n");
    // for (int i = 0; i < count; i++)
    //     printf("%p : %s\n", onegin_ptr[i], onegin_ptr[i]);

    fputs("\nORIGINAL TEXT:\n\n", out_file);
    fwrite(bufff, sizeof(char), bytes_read, out_file);
}

void BUBBLEGUM(string* str, size_t count, Comparator Compare) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if(Compare(&str[j], &str[j + 1]) > 0) {
                string elem = str[j];
                str[j] = str[j + 1];
                str[j + 1] = elem;
            }
        }
    }
}
