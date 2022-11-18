#include <stdio.h>
#include <dirent.h>

int main(){
   struct dirent *files;
   DIR *dir = opendir("/");
   while ((files = readdir(dir)) != NULL)
   printf("%s\n", files->d_name);
   closedir(dir);
   return 0;
}