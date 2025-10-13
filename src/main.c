#include <stdio.h>
#include <string.h>
#include <string.h>

#include "hexdump.h"

int main(int argc, char *argv[]) {
    
    if (argc > 3) {
        printf("too many argument for NetKit...\n");
        
        return 1;

    } else if (argc == 1) {
        const char *command[] = {"exit", "help", "hexdump", NULL};

	    printf("NetKit ready to use in interactive mode... \n\n");
        printf("----- \n\n");
        
        while(1) {
            #define INPUT_SIZE 256
            char input[INPUT_SIZE];

            printf("> ");

            if (fgets(input, INPUT_SIZE, stdin) == NULL) {
                printf("NetKit interactive mode stopped...\n");

                return 1;
            } 

            input[strcspn(input, "\n")] = '\0';

            char *cmd = strtok(input, " \t");
            char *arg = strtok(NULL, " \t");

            if (cmd == NULL) {
                continue;
            }
            
            int found_command = 0;
            int i = 0;
            while (command[i] != NULL && found_command == 0) {
                if (strcmp(cmd, command[i]) == 0) {
                    found_command = 1;
                }
                i++;
            }

            if (found_command == 0) {
                printf("%s not a NetKit command...\n", cmd);
                printf("type 'help' to now all avalaible command!\n");

            } else if (strcmp(cmd, "exit") == 0) {
                printf("Netkit interactive mode stopped...\n");

                return 1;
              
            } else if (strcmp(cmd, "help") == 0) {
                printf("Here is all NetKit command : \n\n");
                
                int i = 0;
                while (command[i] != NULL) {
                    printf("%s\n", command[i]);
                    i++;
                }

            } else if (strcmp(cmd, "hexdump") == 0){
                
                if (arg == NULL) {
                    printf("2 arguments are required for hexdump...\n");
                    printf("Here is the right command : hexdump {FileName}\n");
                } else {
                    int result = nk_hexdump(arg);
                    
                    if (result != 0) {
                        printf("[ERROR] can't use hexdump with %s \n", arg);
                    }
                }
            }
        }

    } else {
        printf("Netkit is ready to use... \n\n");
        printf("----- \n\n");

        if (argc == 3 && strcmp(argv[1], "hexdump") == 0) {
            int result = nk_hexdump(argv[2]);
        
            if (result != 0) {
                printf("[ERROR] can't use hexdump with %s \n", argv[2]);
            }
        }
    }
   

    return 0;
}
