#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main(int argc, char *argv[]) {
    unsigned int counter[1000];
    float hit = 0, miss = 0;
    bool page_found;

    unsigned int frames_num = atoi(argv[1]);
    unsigned int *page_table = malloc(frames_num * sizeof(unsigned int));
    int page;
    FILE *file = fopen("ex1.txt", "r");

    while (fscanf(file, "%d", &page) == 1) {
        page_found = false;
        for (int i = 0; i < frames_num; i++) {
            if (page == page_table[i]) {
                hit++;
                page_found = true;
                break;
            }
        }

        if (!page_found) {
            miss++;
            unsigned int sw_c = UINT_MAX;
            int sw_i = 0;
            for (int i = 0; i < frames_num; i++) {
                if (counter[page_table[i]] < sw_c) {
                    sw_c = counter[page_table[i]];
                    sw_i = i;
                }
            }
            page_table[sw_i] = page;
        }

        for (int i = 0; i < 1000; i++) {
            counter[i] >>= 0x1;
        }
        counter[page] |= 0x1 << 31;
    }

    printf("Hit/Miss ratio: %f\n", hit / miss);
    fclose(file);
    free(page_table);

    return 0;
}