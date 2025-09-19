#ifndef FUNCS_H
#define FUNCS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int CPABHEHUE_CTPOK(const char* str1, const char* str2);                    //strcmp()
int CPABHEHUE_CTPOK_back(const char* str1, const char* str2);            //reverse strcmp()
void KOnUPOBAHUE_CTPOKU(const char* str1, char* str2);                    //strcpy()
void COEDUHEHUE_CTPOK (char* str1, const char* str2);                    //strcat()
char* nOUCK_CUMBOVA_B_CTPOKE(const char* str1, char symbol);            //strchr()
char* nOUCK_CTPOKU_B_CTPOKE(const char* str1, const char* target_str); //strstr()
int DVUHA_CTPOKU (const char* str);                                   //strlen()
char* DY6VUKAT_CTPOKU (const char* str);                             //strdup()
int CTPOKY_B_INT (char* str);                                       //atoi()
int GetLine (char** str, size_t* size, FILE* stream);              //getline()
char* Fgets (char* str, size_t size, FILE* stream);               //fgets()

#endif // FUNCS_H
