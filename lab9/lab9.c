#include <stdio.h>
#include <unistd.h>
#define ERROR -1
#define FORK_ERROR -1
#define FORK_VAL_FOR_CHILD 0

int main(int argc, const char** argv) {

        pid_t pid = fork();
        if (pid == FORK_ERROR) {
                perror("error in fork");
                return ERROR;
        }

        if (pid == FORK_VAL_FOR_CHILD) {
                execl("/bin/cat", "/bin/cat", "large_text.txt", NULL);
                perror("Execlp didn't execute. Error");
                return ERROR;
        }

        printf("\nParent proccess text!\n\n");

        return 0;
}

