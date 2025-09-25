#include "create_structs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#include "struct.h"

int Cut_n_Count_Buffer(char* bufff) {
    char* trolley = bufff;
    char* marker = 0;
    int count = 0;
    while (true) {
        //printf("sex\n");
        marker = strchr(trolley, '\n');
        trolley = marker + 1;
        //printf("Strchr pointer: %p\n", trolley);
        if (marker == NULL)
            break;

        count++;
    }
    //printf("String count: %d\n", count);
    return count;
}

void Split_Lines(string** str, char* bufff, size_t* count) {
    //printf("count1: %d\n", count);
    *count = Cut_n_Count_Buffer(bufff);
    *str = (string*)calloc(*count, sizeof(string));
    assert(*str != NULL);

    char* trolley = bufff;
    char* marker = 0;
    size_t size = 0;
    for (int i = 0; (i < *count) && (*trolley != '\0'); i++) {
        marker = strchr(trolley, '\n');
        size = marker - trolley;
        if (marker != NULL) {
            (*str)[i].line = trolley;
            (*str)[i].length = size;
            trolley = marker + 1;
            // printf("%d", i);
        }
    }
}
