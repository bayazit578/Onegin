#include "supportive.h"

#include <ctype.h>
#include <string.h>

int Alpha_index(const char* str) {
    if ((*str == '\n') || (*str == '\0'))
        return 0;

    int i = 0;
    while (!(isalpha(str[i]))) {
        i++;

        if ((str[i] == '\n') || (str[i] == '\0'))
            return -1;
    }
    return i;
}

int Back_Alpha_index(const char* str) {
    if ((*str == '\n') || (*str == '\0'))
        return 0;

    int i = strchr(str, '\n') - str - 1;
    while (!(isalpha(str[i]))) {
        i--;
        if ((str[i] == '\n') || (str[i] == '\0'))
            return -1;
    }
    return i;
}
