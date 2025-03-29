#include <stdio.h>
#include <stdlib.h>

int globalVar = 42;

void check_heap(){
	int *heap = (int *)malloc(sizeof(int));
	printf("Змінна у купі знаходиться %p\n", heap);
}

void stack_array(int depth){
	int a[1000];
	printf("Вершина стека на глибині %d знаходиться %p\n", depth, &a);
 	if (depth < 3) {
        	stack_array(depth + 1);
    	}
}

int main() {
	int i;
	printf("The stack top is near %p\n", &i);
	printf("Сегмент коду знаходиться %p\n", (void*)main);
    	printf("Глобальна змінна знаходиться %p\n", &globalVar);

	check_heap();

	stack_array(1);

	return 0;
}