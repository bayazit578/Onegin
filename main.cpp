#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>

#include "funcs.h"
#include "sorts.h"
#include "comparator.h"
#include "fileworks.h"
#include "create_structs.h"
#include "struct.h"

const char* in_fi = "EngEvgeniyOnegin.txt";
const char* out_fi = "sigma_poem.txt";

int main() {
    int onegin_descr = open(in_fi, O_RDONLY);
    // if (onegin_descr == -1) {
    //     printf("Error %d: %s\n", errno, strerror(errno));
    //     switch(errno) {
    //         case ENOENT: fprintf(stderr, "File doesn't exist\n");
    //                      break;
    //         case EACCES: fprintf(stderr, "No acces rights\n");
    //                      break;
    //         case EMFILE: fprintf(stderr, "Too many open files\n");
    //                      break;
    //         default: fprintf(stderr, "Unknown error\n");
    //     }
    // }

    char* onegin_bufff = {};
    Read_File(onegin_descr, &onegin_bufff);
    // printf("\nBuffer contents:\n");
    // for (int i = 0; i < onegin_info.st_size; i++)
    //     putchar(onegin_bufff[i]);

    close(onegin_descr);

    size_t count = 0;
    struct string* str = {};
    Split_Lines(&str, onegin_bufff, &count);
    // printf("\nPrint of struckture massive:\n");
    // for (int i = 0; i < count; i++)
    //     printf("%p : %s\n", *onegin_ptr[i], onegin_ptr[i]);

    //printf("count2: %d\n", count);
    FILE* clear_file = fopen(out_fi, "w");
    fclose(clear_file);
    FILE* onega_out = fopen(out_fi, "a");

    Run_Sorts(str, count, onega_out);

    int res = fclose(onega_out);
    assert(res == 0);

    free(onegin_bufff);
    free(str);
}

