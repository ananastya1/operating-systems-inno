#include <stdio.h>
#include <stdbool.h>

#define N 5
#define M 3

typedef struct {
    int num;
    int done;
    int C[M];
    int R[M];
} processes;

int A[M], E[M];
processes proc[N];

int lookup() {
    for (int pid = 0; pid < N; pid++) {
        if (proc[pid].done) {
            continue;
        }
        char chosen = true;
        for (int j = 0; j < M; j++) {
            if (proc[pid].R[j] > A[j]) {
                chosen = false;
                break;
            }
        }
        if (chosen) {
            for (int j = 0; j < M; j++) {
                A[j] = A[j] + proc[pid].C[j];
                proc[pid].C[j] = 0;
                proc[pid].R[j] = 0;
                proc[pid].done = true;
            }
            return pid;
        }
    }
    return -1;
}


int main() {
    int candidate;
    FILE *input;
    input = fopen("input.txt", "r");
    for (int j = 0; j < M; j++) {
        fscanf(input, "%d", &E[j]);
    }
    for (int j = 0; j < M; j++) {
        fscanf(input, "%d", &A[j]);
    }
    for (int pid = 0; pid < N; pid++) {
        proc[pid].num = pid;
        proc[pid].done = false;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            fscanf(input, "%d", &proc[i].C[j]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            fscanf(input, "%d", &proc[i].R[j]);
        }
    }

    while (true) {
        if (lookup() == -1) {
            break;
        }
    }

    for (int PID = 0; PID < N; PID++) {
        printf("Process %d ", proc[PID].num);
        if (proc[PID].done == false) {
            printf("is in dead lock.\n");
        } else {
            printf("is done.\n");
        }
    }
    return 0;
}