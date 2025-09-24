#include "create_structs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "struct.h"

int Cut_n_Count_Buffer(char* bufff) {
    char* trolley = bufff;
    char* marker = 0;
    int count = 0;
    while ((trolley - 1) != NULL) {
        //printf("sex\n");
        marker = strchr(trolley, '\n');
        trolley = marker + 1;
        //printf("Strchr pointer: %p\n", trolley);
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

    (*str)[0].line = bufff;
    char* trolley = bufff;
    char* marker = 0;
    for (int i = 1; (i < *count) && ((trolley - 1) != NULL); i++) {
        marker = strchr(trolley, '\n');
        int size = marker - trolley;
        trolley = marker + 1;
        if (trolley != NULL) {
            (*str)[i].line = trolley;
            (*str)[i].length = size;
        }
    }
}
