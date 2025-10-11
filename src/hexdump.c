#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "hexdump.h"

#define LINE_BYTES 16

int nk_hexdump(const char *filename) {
    printf("opening file %s \n", filename);

    FILE *inputFile = fopen(filename, "rb");
    if (!inputFile) {
        perror("Error opening file ");
        return 1;
    }


    unsigned char buffer[LINE_BYTES];
    size_t offset = 0;
    size_t n;

    while ((n = fread(buffer, 1, LINE_BYTES, inputFile)) > 0) {
        
        printf("%08zx\t", offset);

        for (size_t i = 0; i < n; ++i) {
            printf("%02x ", buffer[i]);
            if (i == 7) {printf(" ");}
        } printf("\t");
        
        if (n < LINE_BYTES) {
            for (size_t i = n; i < LINE_BYTES; i++) {
                printf("    ");
            }
        }

        for (size_t i = 0; i < n; i++) {
            unsigned char ch = buffer[i];
            if (isprint(ch)) {
                putchar(ch);
            } else {printf(".");}
        }

        printf("\n");
        offset += n;
    }
    
    printf("\n%zu bytes read \n", offset);
    printf("Hexdump used with succes on %s\n", filename);

    fclose(inputFile);

    return 0;
}
