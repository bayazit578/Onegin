#ifndef FILEWORKS_H
#define FILEWORKS_H

#include <stdio.h>

void ADD_to_File(const char* const* onegin, int count, int cond);
void Print_Title_to_File(FILE* out_file, int cond);
int Read_File(int input_descr, char** bufff);

#endif // FILEWORKS_H
