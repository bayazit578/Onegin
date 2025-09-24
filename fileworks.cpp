#include "fileworks.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int Read_File(int input_descr, char** bufff) {
    struct stat input_info;
    fstat(input_descr, &input_info);
    //printf("%d\n", input_info.st_size);
    //printf("Describtor2: %d\n", input_descr);

    FILE* input_stream = fdopen(input_descr, "r");

    *bufff = (char*)calloc(input_info.st_size + 1, sizeof(char));//struct
    //printf("Buffer ptr: %p", onegin_bufff);

    size_t bytes_read = fread(*bufff, sizeof (*bufff)[0], input_info.st_size, input_stream);
    //printf("sex\n");

    (*bufff)[bytes_read] = '\0';
    return bytes_read;
}

void Add_to_File(string* str, char* title, size_t count, FILE* out_file) {

    // printf("\nPrint of ptr massive:\n");
    // for (int i = 0; i < count; i++)
    //     printf("%p : %s\n", onegin[i], onegin[i]);
    fprintf(out_file, "\n%s\n", title);

    for (int i = 0; i < count; i++) {
        fprintf(out_file, "%s\n", str[i]);
        //printf("fprintf str: %s\n", onegin[i]);
    }
    fclose(out_file);
}
