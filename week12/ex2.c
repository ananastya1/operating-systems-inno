#include <errno.h>
#include <linux/input.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>


int main() {
    const char *file = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    struct input_event ev;
    FILE *ffile = fopen(file, "r");
    if (ffile == NULL) {
        fprintf(stderr, "Error to open the file\n");
        return 1;
    }
    while (1) {
        fread(&ev, sizeof (struct input_event), 1, ffile);
        if (ev.type == EV_KEY) {
            if (ev.value == 1) {
                    printf("%s 0x%04x (%d) \n", "PRESSED", ev.code, ev.code); // PRESSED
            }
            else if (ev.value == 0) {
                printf("%s 0x%04x (%d) \n", "RELEASED", ev.code, ev.code); // RELEASED
            }
        }
    }
    fclose(ffile);
    fflush(stdout);
    fprintf(stderr, "%s\n", strerror(errno));
    return 1;
}