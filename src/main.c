#include <stdio.h>
#include <string.h>

#include "hexdump.h"

int main(int argc, char *argv[]) {
	printf("NetKit ready to use !!! \n\n");
    
    if (argc > 2 && strcmp(argv[1], "hexdump") == 0) {
        printf("hexdump in use... \n");
        int result = nk_hexdump(argv[2]);
        
        if (result != 0) {
            printf("[ERROR] can't use hexdump with %c", *argv[2]);
        }
    }
   

    return 0;
}
