#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    int fd[2];
    // fd[0] - read end
    // fd[1] - write end
    if(pipe(fd) == -1) { 
        printf("Error");
        return 1;
    };

    int id = fork();
    if (id == 0) {
        int sendings[5] = {3, 4, 4, 2, 6};
        close(fd[0]);
        int x;
        for(int i = 0; i < 5; ++i) {
            write(fd[1], &sendings[i], sizeof(int));
        }
        close(fd[1]);
    } else {
        close(fd[1]);
        int y;
        int * res;
        for(int i = 0; i < 5; ++i) {
            read(fd[0], &res[i], sizeof(int));
        }
        close(fd[0]);
        for(int i = 0; i < 5; ++i) {
            printf("Got from child process: %d\n", res[i]);
        }
    }

// Important: Don't forget error checking
    return 0;
}