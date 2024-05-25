#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int i, count = 0;
    printf("Digite uma string: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }

    printf("O número de vogais na string é: %d\n", count);
    return 0;
}
