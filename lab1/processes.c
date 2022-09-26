#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>


int main() {
  int n = 4;

  int pid = fork();

  if (pid != 0) {
    kill(pid, SIGKILL);
   }
  printf("Hello, from {PID - % d - %d - %p}\n", pid, n, &n);
  exit(EXIT_SUCCESS);
  return 0;
}