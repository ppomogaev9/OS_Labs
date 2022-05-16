#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#define ERROR -1
#define WAIT_ERROR -1
#define FORK_ERROR -1
#define FORK_VAL_FOR_CHILD 0

int main(int argc, const char** argv) {

        pid_t pid = fork();
        if (pid == FORK_ERROR) {
                perror("error in fork");
                return ERROR;
        }

        if (pid == FORK_VAL_FOR_CHILD) {
                execlp("cat", "cat", "large_text.txt", NULL);
                perror("Execlp didn't execute. Error");
                return ERROR;
        }

        pid_t wait_ret_val = wait(NULL);
        if (wait_ret_val == WAIT_ERROR) {
                perror("wait(2) crashed with error");
                return ERROR;
        }

        printf("\nParent proccess text!\n\n");

        return 0;
}

