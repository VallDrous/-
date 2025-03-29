#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <limits.h>

int main() {
    time_t max_time = (time_t) LONG_MAX;

    printf("Максимальне значення time_t: %lld\n", (long long)max_time);

    char *time_str = ctime(&max_time);
    if (time_str) {
        printf("Дата і час останнього значення: %s", time_str);
    } else {
        printf("Дата і час останнього значення: переповнене\n");
    }

    return 0;
}