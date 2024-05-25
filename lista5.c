#include <stdio.h>
#include <ctype.h>

void toUpperCase(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

int main() {
    char str[100];
    printf("Digite uma string: ");
    scanf("%s", str);

    toUpperCase(str);

    printf("String convertida para maiúsculas: %s\n", str);
    return 0;
}
