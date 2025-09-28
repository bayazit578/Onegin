#include "comparator.h"

#include <string.h>

#include "supportive.h"
#include "funcs.h"
#include "struct.h"

int CompareStr(const void* par1, const void* par2) {
    string str1 = *(string*)par1;
    string str2 = *(string*)par2;
    return My_Strcmp(str1, str2);
}

int CompareStr_back(const void* par1, const void* par2) {
    string str1 = *(string*)par1;
    string str2 = *(string*)par2;
    return My_Strcmp_back(str1, str2);
}
