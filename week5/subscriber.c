#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

int main()
{
    char arr[1024];

    int fd = open("/tmp/ex1", O_RDONLY);

    while (1)
    {
        read(fd, &arr, sizeof(int));
        printf("Message is: %s\n", arr);
    }

    close(fd);
    return 0;
}