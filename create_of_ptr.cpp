#include "create_of_ptr.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Count_Lines(char* bufff) {
    char* trolley = bufff;
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
    //printf("String count: %d\n", count);
    return count;
}

char** Split_Lines(char* bufff, int* count) {
    *count = Count_Lines(bufff);
    //printf("count1: %d\n", count);
    char** bufff_ptr = (char**)calloc(*count, sizeof(char*));
    bufff_ptr[0] = bufff;
    char* trolley = bufff;
    char* marker = 0;
    for (int i = 1; (i < *count) && ((trolley - 1) != NULL); i++) {
        marker = strchr(trolley, '\0');
        trolley = marker + 1;
        if (marker != NULL) {
            bufff_ptr[i] = trolley;
        }
    }
    return bufff_ptr;
}
