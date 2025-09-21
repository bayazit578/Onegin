#include "sorts.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcs.h"
#include "supportive.h"
#include "fileworks.h"
#include "comparator.h"

// int (*a)(const void*, const void*)
void Run_Sorts(char** ptr, int count) {
    int cond = 0;
    BUBBLEGUM_straight(ptr, count);
    cond = 0;
    ADD_to_File((const char* const*)ptr, count, cond);
    // printf("\nPrint of ptr massive:\n");
    // for (int i = 0; i < count; i++)
    //     printf("%p : %s\n", onegin_ptr[i], onegin_ptr[i]);

    BUBBLEGUM_back(ptr, count);
    cond = 1;
    ADD_to_File((const char* const*)ptr, count, cond);
    // printf("\nPrint of ptr massive:\n");
    // for (int i = 0; i < count; i++)
    //     printf("%p : %s\n", onegin_ptr[i], onegin_ptr[i]);

    qsort(ptr, count, sizeof(char*), CompareStr);
    cond = 2;
    ADD_to_File((const char* const*)ptr, count, cond);
    // printf("\nPrint of ptr massive:\n");
    // for (int i = 0; i < count; i++)
    //     printf("%p : %s\n", onegin_ptr[i], onegin_ptr[i]);

    qsort(ptr, count, sizeof(char*), CompareStr_back);
    cond = 3;
    ADD_to_File((const char* const*)ptr, count, cond);
    // printf("\nPrint of ptr massive:\n");
    // for (int i = 0; i < count; i++)
    //     printf("%p : %s\n", onegin_ptr[i], onegin_ptr[i]);


}

void BUBBLEGUM_straight(char** onegin, int count) {//указатель на функцию

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if(CPABHEHUE_CTPOK(&onegin[j][Alpha_index(onegin[j])],
                               &onegin[j + 1][Alpha_index(onegin[j + 1])]) > 0) {
                char* elem = onegin[j];
                onegin[j] = onegin[j + 1];
                onegin[j + 1] = elem;
            }
        }
    }
}

void BUBBLEGUM_back(char** onegin, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if(CPABHEHUE_CTPOK_back(&onegin[j][Back_Alpha_index(onegin[j])],
                                    &onegin[j + 1][Back_Alpha_index(onegin[j + 1])]) > 0) {
                char* elem = onegin[j];
                onegin[j] = onegin[j + 1];
                onegin[j + 1] = elem;
            }
        }
    }
}
