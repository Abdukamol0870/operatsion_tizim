
#include <stdio.h>
#include <string.h>

int tekshirish(char *str) {
    char *chap = str;
    char *ong = str + strlen(str) - 1;

    while (chap < ong) {
        if (*chap != *ong) {
            return 0;
        }

        chap++;
        ong--;
    }

    return 1;
}

int main() {
    char satr[100];

    printf("Satr kiriting: ");
    fgets(satr, 100, stdin);

    satr[strcspn(satr, "\n")] = '\0';

    if (strlen(satr) == 0) {
        printf("Satr bo'sh!\n");
        return 1;
    }

    if (tekshirish(satr)) {
        printf("PALINDROM!\n");
    } else {
        printf("Palindrom emas.\n");
    }

    return 0;
}

