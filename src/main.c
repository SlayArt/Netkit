#include <stdio.h>
#include <string.h>

#include "hexdump.h"

int main(int argc, char *argv[]) {
    
    if (argc > 3) {
        printf("too many argument for NetKit...\n");
        return 1;
    } 

	printf("NetKit ready to use... \n\n");
    printf("----- \n\n");
    
    if (argc == 3 && strcmp(argv[1], "hexdump") == 0) {
        printf("hexdump in use... \n");
        int result = nk_hexdump(argv[2]);
        
        if (result != 0) {
            printf("[ERROR] can't use hexdump with %s \n", argv[2]);
        }
    }
   

    return 0;
}
