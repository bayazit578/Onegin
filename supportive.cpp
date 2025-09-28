#include "supportive.h"

#include <ctype.h>
#include <string.h>
#include <assert.h>

bool if_null(char x) {
    return x == '\n' || x == '\0';
}

int Alpha_index_structs(string str) {
    assert(str.line != NULL);
    if (str.length == 1)
        return 0;
    int i = 0;
    for (; !(isalpha(str.line[i])) && i < str.length; i++) {
        if (if_null(str.line[i]))
            return -1;
    }
    return i;
}

int Back_Alpha_index_structs(string str) {
    assert(str.line != NULL);
    if (!str.length)
        return 0;
    int i = str.length - 2;
    for (; !(isalpha(str.line[i])) && i >= 0; i--) {
        if (if_null(str.line[i]))
            return -1;
    }
    return i;
}
