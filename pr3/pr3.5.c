#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 10485760

void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (src == NULL) {
        printf("Не вдалося відкрити файл %s для читання\n", source);
        exit(1);
    }

    fseek(src, 0, SEEK_END);
    long file_size = ftell(src);
    fseek(src, 0, SEEK_SET);
    
    if (file_size > MAX_FILE_SIZE) {
        printf("Розмір файлу перевищує ліміт %d байт\n", MAX_FILE_SIZE);
        fclose(src);
        exit(1);
    }

    FILE *dest = fopen(destination, "wb");
    if (dest == NULL) {
        printf("Не вдалося відкрити файл %s для запису\n", destination);
        fclose(src);
        exit(1);
    }

    char buffer[1024];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    printf("Файл успішно скопійовано!\n");

    fclose(src);
    fclose(dest);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Програмі потрібно два аргументи\n");
        return 1;
    }

    copy_file(argv[1], argv[2]);

    return 0;
}