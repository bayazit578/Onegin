#include "sorts.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcs.h"
#include "supportive.h"

// int (*a)(const void*, const void*)

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
