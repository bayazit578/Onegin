#include "comparator.h"

#include <string.h>

int CompareStr(const void* par1, const void* par2) {
    const char* str1 = *(char**)par1;
    const char* str2 = *(char**)par2;
    return strcmp(str1, str2);
}
