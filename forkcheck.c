#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();  // create a new process

    if (pid < 0) {
        printf("Fork failed!\n");
    }
    else if (pid == 0) {
        // child process
        printf("Hello from Child! My PID = %d, Parent PID = %d\n", getpid(), getppid());
    }
    else {
        // parent process
        printf("Hello from Parent! My PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}
//C Program to create new process using Linux API system calls fork() and exit()
