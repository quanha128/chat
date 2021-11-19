#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    while (1) {
        pid_t pid = fork();
        if (pid > 0) {
        /* Parent */
            int ret;
            waitpid(pid, &ret, 0);
            if (ret != 0)
                printf("ERROR: child returned %d\n", ret);
        }
        else {
            /* Child */
            char buf[256];
            int cnt = 0;

            printf("> ");
            int idx=0;
            while ((buf[idx] = fgetc(stdin)) != '\n') {
                idx++;
            }
            buf[idx] = '\0';

            // split string
            char** argv = (char**)malloc(256);
            argv[0] = strtok(buf, " ");
            while (argv[cnt] != NULL) {
                cnt ++;
                argv[cnt] = strtok(NULL, " ");
            }
            argv = realloc(argv, (cnt+1)*sizeof(char**));

            // exec argv
            argv[cnt] = NULL;

            return execvp(argv[0], argv);

            fprintf(stderr, "Should not reach here\n");
            return -1;
        } 
    }
}