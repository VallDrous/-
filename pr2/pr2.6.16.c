#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

int main() {
    size_t old_size = 4096;
    size_t new_size = 8192;

    char *data = mmap(NULL, old_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (data == MAP_FAILED) {
        perror("mmap");
        return EXIT_FAILURE;
    }

    strcpy(data, "some text");

    printf("Before mremap: %s\n", data);

    data = mremap(data, old_size, new_size, MREMAP_MAYMOVE);
    if (data == MAP_FAILED) {
        perror("mremap");
        return EXIT_FAILURE;
    }

    strcat(data, " Extended memory");

    printf("After mremap: %s\n", data);

    if (munmap(data, new_size) == -1) {
        perror("munmap");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}