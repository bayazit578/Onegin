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
void Run_Sorts(string* str, size_t count, FILE* out_file) {
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

}

void BUBBLEGUM(string* str, size_t count, Comparator Compare) {//указатель на функцию
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if(CompareStr(&str[j], &str[j + 1]) > 0) {
                string elem = str[j];
                str[j] = str[j + 1];
                str[j + 1] = elem;
            }
        }
    }
}

// void BUBBLEGUM_back(string* str, size_t count) {
//     for (int i = 0; i < count - 1; i++) {
//         for (int j = 0; j < count - i - 1; j++) {
//             if(CompareStr_back(&str[j], &str[j + 1]) > 0) {
//                 string elem = str[j];
//                 str[j] = str[j + 1];
//                 str[j + 1] = elem;
//             }
//         }
//     }
// }
