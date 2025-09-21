#include "comparator.h"

#include <string.h>

#include "supportive.h"
#include "funcs.h"

int CompareStr(const void* par1, const void* par2) {
    const char* str1 = *(char**)par1;
    const char* str2 = *(char**)par2;
    return CPABHEHUE_CTPOK(&str1[Alpha_index(str1)],
                  &str2[Alpha_index(str2)]);
}

int CompareStr_back(const void* par1, const void* par2) {
    const char* str1 = *(char**)par1;
    const char* str2 = *(char**)par2;
    return CPABHEHUE_CTPOK_back(&str1[Back_Alpha_index(str1)],
                  &str2[Back_Alpha_index(str2)]);
}
