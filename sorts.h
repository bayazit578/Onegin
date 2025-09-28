#ifndef SORTS_H
#define SORTS_H

#include <stdio.h>
#include <stdlib.h>

#include "comparator.h"

void Run_Sorts(struct string* str, size_t count, FILE* out_file, char* bufff, size_t bytes_read);
void BUBBLEGUM(string* str, size_t count, Comparator Compare);

#endif // SORTS_H
