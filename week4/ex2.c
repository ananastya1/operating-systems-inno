#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int u[120], v[120], c = 1;
    FILE * pFile = fopen("myfile.txt", "w+");
    printf("Enter a number: ");
    int n, right = 0, left = 0, result;
    scanf("%d", &n);
    srand(time(0));
    for (int i = 0; i < 120; i++) {
        u[i] = rand() % 100;
        v[i] = rand() % 100;
    }
    int parts = 120/n;
    right = parts;
    pid_t pid = getpid();
    for (int i = 0; i < n; ++i) {
        left += parts * ((i==0) ? 0 : 1);
        right += parts * ((i==0) ? 0 : 1);
        result = 0;
        if (getpid() == pid && fork() == 0) break;
    }
    while(left < right && getpid() != pid) result += u[left] * v[left++];
    if(getpid()!=pid){
        char r[10];
        sprintf(r,"%d", result);
        fputs(r, pFile);
        fputs("\n", pFile);
        exit(0);
    }
 
    if (getpid()==pid) {  
        for (int i = 0; i < n; ++i) {
            wait(NULL);
        }
        fseek(pFile, 0, SEEK_SET);
        char line[10];
        int dot = 0;
        for (int i = 0; i < n; i++) {
            if (pFile!=NULL)
            {
                fgets(line, 10, pFile);
                dot += atoi(line);
            }
        }
        fclose(pFile);
        printf("%d\n", dot);
    }

    return 0;
}