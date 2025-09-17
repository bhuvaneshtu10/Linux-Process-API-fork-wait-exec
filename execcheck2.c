#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        // child process
        printf("Child: Running ls -l using exec...\n");
        execl("/bin/ls", "ls", "-l", NULL);
        // If exec fails
        printf("Exec failed!\n");
    }
    else {
        // parent process
        wait(NULL);  // wait for child
        printf("Parent: Child finished exec.\n");
    }

    return 0;
}

