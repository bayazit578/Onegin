#include "supportive.h"

#include <ctype.h>
#include <string.h>

int Alpha_index(const char* str) {
    if (*str == '\0')
        return 0;

    int i = 0;
    while (!(isalpha(str[i])))
        i++;
    return i;
}

int Back_Alpha_index(const char* str) {
    if (*str == '\0')
        return 0;

    int i = strlen(str) - 1;
    while (!(isalpha(str[i])))
        i--;
    return i;
}
