#include <errno.h>
#include <linux/input.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define NUM_OF_KEYS 7777


int main() {
    const char *file = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    struct input_event ev;
    FILE *ffile = fopen(file, "r");
    int key_status[NUM_OF_KEYS];
    for (int i = 0; i < NUM_OF_KEYS; i++) {
        key_status[i] = 0;
    }

    while (1) {
        fread(&ev, sizeof (struct input_event), 1, ffile);
        if (ev.type == EV_KEY) {
            if (ev.value == 0) {
                key_status[ev.code] = 0;
            }
            else if (ev.value == 1) {
                key_status[ev.code] = 1;
                if(key_status[25] && key_status[18]) {
                    printf("I passed the Exam!\n");
                }
                else if(key_status[46] && key_status[30] && key_status[25]) {
                    printf("Get some cappuccino!\n");
                }
            }
        }
    }
    fclose(ffile);
    fflush(stdout);
    fprintf(stderr, "%s\n", strerror(errno));
    return 1;
}