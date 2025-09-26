#ifndef SORTS_H
#define SORTS_H

#include <stdio.h>
#include <stdlib.h>

#include "comparator.h"

void Run_Sorts(struct string* str, size_t count, FILE* out_file);
void BUBBLEGUM(string* str, size_t count, Comparator Compare);

#endif // SORTS_H
