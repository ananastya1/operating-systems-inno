#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define N 50
#define M 30

typedef struct {
    int num;
    int done;
    int C[M];
    int R[M];
} processes;

int A[M], E[M];
processes proc[N];

int lookup(int n, int m) {
    for (int pid = 0; pid < n; pid++) {
        if (proc[pid].done) {
            continue;
        }
        char chosen = true;
        for (int j = 0; j < m; j++) {
            if (proc[pid].R[j] > A[j]) {
                chosen = false;
                break;
            }
        }
        if (chosen) {
            for (int j = 0; j < m; j++) {
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
    char st[100];
    FILE *input;
    char *strings;
    input = fopen("input.txt", "r");
    int n = 0, m = 0, k = 0;

    getdelim(&strings, &k, '\0', input);
    fclose(input);
    char * strE = strtok(strings, "\n");
    char * strA = strtok(NULL, "\n");
    char ** matr = malloc(sizeof(char *) * 100);
    char * elemMatr = strtok(NULL, "\n");
    n = 0;
    while (elemMatr != NULL)
    {
        matr[n] = malloc(sizeof(char) * 100);
        strcpy(matr[n++], elemMatr);
        elemMatr = strtok (NULL, "\n");
    }

    
    char * elemE = strtok(strE, " ");
    while (elemE != NULL)
    {
        sscanf(elemE, "%d", &E[m++]);
        elemE = strtok (NULL, " ");
    }

    char * elemA = strtok(strA, " ");
    m = 0;
    while (elemA != NULL)
    {
        sscanf(elemA, "%d", &A[m++]);
        elemA = strtok (NULL, " ");
    }

    for (int pid = 0; pid < n / 2; pid++) {
        proc[pid].num = pid;
        proc[pid].done = false;
    }
    for (int i =  0; i < n / 2; i++) {
        char * elemC = strtok(matr[i], " ");
        for (int j = 0; j < m; j++) {
            sscanf(elemC, "%d", &proc[i].C[j++]);
        }
    }
    for (int i = n / 2; i < n; i++) {
        char * elemR = strtok(matr[i], " ");
        for (int j = 0; j < m; j++) {
            sscanf(elemR, "%d", &proc[i].R[j++]);
        }
    }

    while (true) {
        if (lookup(n / 2, m) == -1) {
            break;
        }
    }

    for (int PID = 0; PID < n / 2; PID++) {
        printf("Process %d ", proc[PID].num);
        if (proc[PID].done == false) {
            printf("is in dead lock.\n");
        } else {
            printf("is done.\n");
        }
    }
    return 0;
}