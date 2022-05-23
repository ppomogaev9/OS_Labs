#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#define ERROR -1

int file_opening() {
        FILE * file = fopen("filefile", "r");
        if (file == NULL) {
                perror("in function \"file_opening\", fopen");
                return ERROR;
        }

        int fclose_result = fclose(file);
        if (fclose_result == EOF) {
                perror("in function \"file_opening\" fclose");
                return ERROR;
        }
        return ERROR;
}

void print_IDs() {
        printf("Real ID: %d\n", getuid());
        printf("Effective ID: %d\n", geteuid());
}

int main() {
        print_IDs();

        int file_opening_result = file_opening();

        int res_setuid = setuid(getuid());
        if (res_setuid == ERROR) {
                perror("in function \"main\" setuid");
                return ERROR;
        }

        print_IDs();

        file_opening_result = file_opening();

        return 0;
}

