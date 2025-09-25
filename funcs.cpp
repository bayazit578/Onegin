#include "funcs.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "struct.h"
#include "supportive.h"

static bool if_null(char x) {
    return x == '\n' || x == '\0';
}

int CPABHEHUE_CTPOK(string str1, string str2) {
    int result = 0;
    int len1 = Alpha_index(str1.line);
    int len2 = Alpha_index(str2.line);
    for (int step = 0; !(if_null(str1.line[len1 + step]) ||
                       if_null(str2.line[len2 + step])); step++) {
        if (str1.line[len1 + step] == str2.line[len2 + step])
            continue;
        else if (str1.line[len1 + step] > str2.line[len2 + step]) {
            result = 1;
            break;
        }
        else {
            result = -1;
            break;
        result = 0;
        }
    }
    return result;
}

int CPABHEHUE_CTPOK_back(string str1, string str2) {
    int result = 0;
    int len1 = Back_Alpha_index(str1.line);
    int len2 = Back_Alpha_index(str2.line);
    for (int step = 0; !(if_null(str1.line[len1 - step]) ||
                       if_null(str2.line[len2 - step])); step++) {
        if (str1.line[len1 - step] == str2.line[len2 - step])
            continue;
        else if (str1.line[len1 - step] > str2.line[len2 - step]) {
            result = 1;
            break;
        }
        else {
            result = -1;
            break;
        result = 0;
        }
    }
    return result;
}

void KOnUPOBAHUE_CTPOKU(const char* str1, char* str2) {
    int line = (int)strlen(str2);
    int step = 0;
    while (str1[step] != '\0') {
        str2[step] = str1[step];
        step++;
    }
    for (int i = 0; i < (line - step); i++)
        str2[step + i] = '\0';
}

void COEDUHEHUE_CTPOK(char* str1, const char* str2) {
    int step = 0;
    while (str1[step] != '\0') {
        step++;
    }
    for (int i = 0; str2[i] != '\0'; i++)
        str1[step + i] = str2[i];
}

char* nOUCK_CUMBOVA_B_CTPOKE(const char* str1, char symbol) {
    while (*(str1++) != symbol){
        if (*str1 == '\0')
            return NULL;
    }
    return (char*)str1;
}

int DVUHA_CTPOKU(const char* str) {
    int length = 0;
    while (*(str++) != '\0')
        length++;
    return length;
}

char* DY6VUKAT_CTPOKU(const char* str) {
    int size = (int)strlen(str);
    printf("%d\n", size);
    char* dub_str = (char*)calloc(size, sizeof(char));
    int cycles = 0;
    while (str[cycles] != '\0') {
        dub_str[cycles] = str[cycles];
        cycles++;
    }
    dub_str[cycles] = '\0';
    return dub_str;
}

char* nOUCK_CTPOKU_B_CTPOKE(const char* str, const char* target_str) {
    for (; *str != '\0'; str++) {
        const char* s = str;
        const char* t = target_str;
        while (*t != '\0' && *s == *t) {
            s++;
            t++;
        }
        if (*t == '\0')
            return (char*) str;
    }
    return NULL;
}

int CTPOKY_B_INT(char* str) {
    int size = (int)strlen(str);
    int number = 0;
    for (int step = 0; step < size; step++) {
        number += str[step] - '0';
        if (size - step > 1)
            number *= 10;
    }
    return number;
}

int GetLine(char** str, size_t* size, FILE* stream) {
    if (*str == NULL) {
        *size = 1;
        *str = (char*)calloc(*size, sizeof(char));
    }
    int counter = 0;
    //printf("size ptr:%d ", size);
    // printf("str ptr ptr:%d\n", str);
    // printf("str ptr:%d\n", *str);
    int ch = 0;

    while ((ch = fgetc(stream)) != '\n') {
        (*str)[counter] = ch;
        counter++;
        if (counter >= (int)*size) {
            *size *= 2;
            *str = (char*)realloc(*str, *size);
            (*str)[counter] = ch;
            //printf("str:%c\n", ch);
        }
    }
    (*str)[counter] = '\0';
    //printf("%d\n", counter);
    return counter;
}

char* Fgets(char* str, size_t size, FILE* stream) {
    if (size == 0)
        return NULL;

    int i = 0;
    char ch = 0;
    if (size > 1) {
        for (; i < size; i++) {
            if ((ch = fgetc(stream)) != '\n') {
                str[i] = ch;
                //printf("%c ", ch);
            }
            else {
                str[size] = '\0';
                return str;
            }
        }
    }
    return NULL;
}

int My_Strcmp(const char* str1, const char* str2) {
    int result = 0;
    for (int step = 0; str1[step] != '\0'; step++) {
        if (str1[step] == str2[step])
            continue;
        else if (str1[step] > str2[step]) {
            result = 1;
            break;
        }
        else {
            result = -1;
            break;
        result = 0;
        }
    }
    return result;
}

int My_Strcmp_back(const char* str1, const char* str2) {
    int result = 0;
    int len1 = (int)strlen(str1);
    int len2 = (int)strlen(str2);
    for (int step = 0; str1[step] != '\0'; step++) {
        if (str1[len1 - step - 1] == str2[len2 - step - 1])
            continue;
        else if (str1[len1 - step - 1] > str2[len2 - step - 1]) {
            result = 1;
            break;
        }
        else {
            result = -1;
            break;
        result = 0;
        }
    }
    return result;
}
