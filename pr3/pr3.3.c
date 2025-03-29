#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILE_SIZE 1024 * 10  
#define NUM_ROLLS 1000           

int roll_dice() {
    return rand() % 6 + 1;
}

int main() {
    FILE *file;
    size_t file_size;
    int roll;
    
    file = fopen("/home/mint/Desktop/file1.txt", "w");
    if (file == NULL) {
        perror("Не вдалося відкрити файл");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < NUM_ROLLS; i++) {
        roll = roll_dice();
        
        fseek(file, 0, SEEK_END);
        file_size = ftell(file);

        if (file_size >= MAX_FILE_SIZE) {
            printf("Перевищено максимальний розмір файлу, припиняємо запис.\n");
            break;
        }

        fprintf(file, "%d\n", roll);
    }

    fclose(file);

    printf("Програма завершена.\n");
    return 0;
}