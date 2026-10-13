#include <stdio.h>
#include <string.h>
#include <ctype.h>


int isPalindromePointers(char *str) {
    char *chap = str;
    char *ong = str + strlen(str) - 1;


    printf("Chap pointer manzili: %p\n", (void*)chap);
    printf("O'ng pointer manzili: %p\n", (void*)ong);

    while (chap < ong) {
        if (!isalnum(*chap)) {
            chap++;
        }
        else if (!isalnum(*ong)) {
            ong--;
        }
        else {

            if (tolower(*chap) != tolower(*ong)) {
                return 0;
            }
            chap++;
            ong--;
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

    if (isPalindromePointers(satr)) {
        printf("PALINDROM!\n");
    } else {
        printf("Palindrom EMAS.\n");
    }

    return 0;
}
