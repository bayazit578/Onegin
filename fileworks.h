#ifndef FILEWORKS_H
#define FILEWORKS_H

#include <stdio.h>
#include "struct.h"

void Add_to_File(string* str, char* title, size_t count, FILE* out_file);
void Print_Title_to_File(FILE* out_file, int cond);
int Read_File(int input_descr, char** bufff);

#endif // FILEWORKS_H
