#include <stdio.h>

void function() {
    int localvar = 42;
    printf("In function: localvar = %d, address = %p\n", localvar, &localvar);
}

void wrapper() {
    int localvar = 24;
    printf("In wrapper: localvar = %d, address = %p\n", localvar, &localvar);
    function();
}

int main() {
    int localvar = 10;
    printf("In main: localvar = %d, address = %p\n", localvar, &localvar);
    wrapper();
    return 0;
}

//Ні не можна обійтися без IP так як IP зберігає посилання на наступну інструкцію, а стек зберігає адрес повернення