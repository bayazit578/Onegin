#ifndef COMPARATOR_H
#define COMPARATOR_H

typedef int (*Comparator)(const void* par1, const void* par2);

int CompareStr(const void* par1, const void* par2);
int CompareStr_back(const void* par1, const void* par2);

#endif // COMPARATOR_H
