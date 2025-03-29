#include <stdio.h>

void recursive_function(int depth) {
    printf("Глибина рекурсії: %d\n", depth);
    recursive_function(depth + 1);
}

int main() {
    printf("Запуск рекурсії для демонстрації обмеження стеку\n");
    recursive_function(1);
    return 0;
}