#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char keyword[50];
    int frequency;
} Entry;

int compare_by_keyword(const void *a, const void *b) {
    return strcmp(((Entry *)a)->keyword, ((Entry *)b)->keyword);
}

int compare_by_frequency(const void *a, const void *b) {
    return ((Entry *)b)->frequency - ((Entry *)a)->frequency;
}

int compare_by_keyword_then_frequency(const void *a, const void *b) {
    int res = strcmp(((Entry *)a)->keyword, ((Entry *)b)->keyword);
    if (res == 0) {
        return ((Entry *)b)->frequency - ((Entry *)a)->frequency;
    }
    return res;
}

void print_entries(Entry arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s - %d\n", arr[i].keyword, arr[i].frequency);
    }
}

Entry *binary_search(Entry *arr, int n, const char *key) {
    Entry temp;
    strcpy(temp.keyword, key);
    return (Entry *)bsearch(&temp, arr, n, sizeof(Entry), compare_by_keyword);
}

int main() {
    Entry entries[] = {
        {"apple", 5},
        {"banana", 3},
        {"cherry", 8},
        {"date", 2},
        {"apple", 7},
        {"banana", 6}
    };
    int n = sizeof(entries) / sizeof(entries[0]);

    int choice;
    printf("Виберіть сортування: 1 - за keyword, 2 - за frequency, 3 - за keyword, потім frequency: ");
    scanf("%d", &choice);

    int (*compare_func)(const void *, const void *) = NULL;
    switch (choice) {
        case 1: compare_func = compare_by_keyword; break;
        case 2: compare_func = compare_by_frequency; break;
        case 3: compare_func = compare_by_keyword_then_frequency; break;
        default: printf("Неправильний вибір\n"); return 1;
    }

    qsort(entries, n, sizeof(Entry), compare_func);
    
    printf("\nВідсортований список:\n");
    print_entries(entries, n);

    char search_key[50];
    printf("\nВведіть слово для пошуку: ");
    scanf("%s", search_key);
    
    Entry *found = binary_search(entries, n, search_key);
    if (found) {
        printf("Знайдено: %s - %d\n", found->keyword, found->frequency);
    } else {
        printf("Не знайдено!\n");
    }

    return 0;
}