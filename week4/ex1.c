#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<sys/wait.h>

int main() {
    clock_t tp = clock();

    pid_t child_a, child_b;

    child_a = fork();
    clock_t ta = clock();

    if (child_a == 0) {
        clock_t enda = clock();
        printf("child_a %d %d %f ms\n", getpid(), getppid(), (float) (enda - ta) * 1000/ CLOCKS_PER_SEC) ;
        exit(0);
    } else {
        child_b = fork();
        clock_t tb = clock();

        if (child_b == 0) {
            clock_t endb = clock();
            printf("child_b %d %d %f ms\n", getpid(), getppid(), (float) (endb - tb) * 1000 / CLOCKS_PER_SEC);
            exit(0);
        } else {
            for (int i = 0; i < 2; ++i) {
                wait(NULL);
            }
            clock_t endp = clock();
            printf("parent %d %d %f ms\n", getpid(), getppid(), (float) (endp - tp) * 1000 / CLOCKS_PER_SEC);
        }
    }
}