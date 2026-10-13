#include <stdio.h>
#include <string.h>
#include <ctype.h>

int tekshirish(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (!isalnum(str[left])) {
            left++;
        }
        else if (!isalnum(str[right])) {
            right--;
        }
        else {
            if (tolower(str[left]) != tolower(str[right])) {
                return 0;
            }
            left++;
            right--;
        }
    }
    return 1;
}

int main() {
    char satr[100];

    printf("Satr kiriting: ");
    fgets(satr, 100, stdin);

    satr[strcspn(satr, "\n")] = '\0';

    if (strlen(satr) == 0) {
        printf("Xato: Bo'sh satr kiritdingiz!\n");
        return 1;
    }

    if (tekshirish(satr)) {
        printf("PALINDROM!\n");
    } else {
        printf("Palindrom EMAS.\n");
    }

    return 0;
}
