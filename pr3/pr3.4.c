#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <signal.h>
#include <unistd.h>

#define MAX_CPU_TIME 1  

void handle_cpu_limit(int sig) {
    printf("\nЛіміт часу ЦП вичерпано! Програма завершена.\n");
    exit(1);
}

void set_cpu_limit() {
    struct rlimit limit;
    limit.rlim_cur = MAX_CPU_TIME;
    limit.rlim_max = MAX_CPU_TIME;
    if (setrlimit(RLIMIT_CPU, &limit) != 0) {
        perror("Не вдалося встановити ліміт CPU");
        exit(1);
    }
}

void generate_unique_numbers(int *array, int count, int max_value) {
    int used[max_value + 1];
    for (int i = 0; i <= max_value; i++) {
        used[i] = 0;
    }

    for (int i = 0; i < count; i++) {
        int num;
        do {
            num = rand() % max_value + 1;
        } while (used[num]);
        used[num] = 1;
        array[i] = num;
    }
}

void print_numbers(const char *label, int *numbers, int count) {
    printf("%s: ", label);
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int main() {
    signal(SIGXCPU, handle_cpu_limit);
    set_cpu_limit();
    
    srand(time(NULL));

    int lottery_7_49[7], lottery_6_36[6];
    generate_unique_numbers(lottery_7_49, 7, 49);
    generate_unique_numbers(lottery_6_36, 6, 36);

    print_numbers("Лотерея 7 з 49", lottery_7_49, 7);
    print_numbers("Лотерея 6 з 36", lottery_6_36, 6);

    printf("Програма завершена успішно.\n");
    while (1) {}
    return 0;
}