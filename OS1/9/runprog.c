#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    pid_t pid = fork();
    if (pid > 0) {
        int ret;
        waitpid(pid, &ret, 0);
        if (ret != 0)
            printf("ERROR: child returned %d\n", ret);
    }
    else {
        char* cmd[argc];
        for (int i=0; i<argc; i++) {
            cmd[i] = argv[i+1];
        }
        cmd[argc] = NULL;
        return execvp(cmd[0], cmd);
    }
}