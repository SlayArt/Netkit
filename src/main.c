#include <stdio.h>
#include <string.h>

#include "hexdump.h"

int main(int argc, char *argv[]) {
	printf("NetKit ready to use !!! \n");
    
    if (argc > 1 && strcmp(argv[1], "hexdump") == 0) {
        int result = nk_hexdump();
        printf("hexdump used... \n");
    }
   

    return 0;
}
