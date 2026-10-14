#include <stdio.h>
#include <stdlib.h>

struct Node {
    int son;
    struct Node *oldingi;
    struct Node *keyingi;
};

int main() {
    struct Node *bosh = NULL;
    struct Node *yangi;
    struct Node *p;
    int n, x;

    printf("Nechta son kiritasiz? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Son: ");
        scanf("%d", &x);

        yangi = malloc(sizeof(struct Node));

        if (yangi == NULL)
            return 1;

        yangi->son = x;
        yangi->oldingi = NULL;
        yangi->keyingi = bosh;

        if (bosh != NULL)
            bosh->oldingi = yangi;

        bosh = yangi;
    }

    printf("Oldinga: ");
    p = bosh;

    while (p != NULL) {
        printf("%d ", p->son);
        p = p->keyingi;
    }

    p = bosh;

    while (p != NULL && p->keyingi != NULL)
        p = p->keyingi;

    printf("\nOrqaga: ");

    while (p != NULL) {
        printf("%d ", p->son);
        p = p->oldingi;
    }

    printf("\nQaysi sonni o'chiramiz? ");
    scanf("%d", &x);

    p = bosh;

    while (p != NULL && p->son != x)
        p = p->keyingi;

    if (p == NULL) {
        printf("Son topilmadi!\n");
    } else {
        if (p->oldingi != NULL)
            p->oldingi->keyingi = p->keyingi;
        else
            bosh = p->keyingi;

        if (p->keyingi != NULL)
            p->keyingi->oldingi = p->oldingi;

        free(p);
    }

    printf("Natija: ");
    p = bosh;

    while (p != NULL) {
        printf("%d ", p->son);
        p = p->keyingi;
    }

    while (bosh != NULL) {
        p = bosh;
        bosh = bosh->keyingi;
        free(p);
    }

    return 0;
}
