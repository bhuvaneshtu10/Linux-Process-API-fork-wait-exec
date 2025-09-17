#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        // child process
        printf("Child: My PID = %d\n", getpid());
        sleep(2);
        printf("Child: Finished work.\n");
    }
    else {
        // parent process
        printf("Parent: Waiting for child %d to finish...\n", pid);
        wait(NULL);  // parent waits
        printf("Parent: Child finished, now I continue.\n");
    }

    return 0;
}

