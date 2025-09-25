#include "comparator.h"

#include <string.h>

#include "supportive.h"
#include "funcs.h"
#include "struct.h"

int CompareStr(const void* par1, const void* par2) {
    const char* str1 = (*(string*)par1).line;
    const char* str2 = (*(string*)par2).line;
    return My_Strcmp(&str1[Alpha_index(str1)],
                           &str2[Alpha_index(str2)]);
}

int CompareStr_back(const void* par1, const void* par2) {
    const char* str1 = (*(string*)par1).line;
    const char* str2 = (*(string*)par2).line;
    return My_Strcmp_back(&str1[Back_Alpha_index(str1)],
                  &str2[Back_Alpha_index(str2)]);
}
