#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **aux;

static void merge(char *a[], int l, int m, int r) {
    int i, j;
    for (i = m + 1; i > l; i--)
        aux[i - 1] = a[i - 1];
    for (j = m; j < r; j++)
        aux[r + m - j] = a[j + 1];
    for (int k = l; k <= r; k++)
        if (strcmp(aux[j], aux[i]) < 0)
            a[k] = aux[j--];
        else
            a[k] = aux[i++];
}

static void mergesort(char *a[], int l, int r) {
    if (r <= l)
        return;
    int m = (r + l) / 2;
    mergesort(a, l, m);
    mergesort(a, m + 1, r);
    merge(a, l, m, r);
}

int main(void) {
    char *months[] = {"January", "February", "March", "April", "May", "June", "July",
                      "August", "September", "October", "November", "December"};
    int n = sizeof(months) / sizeof(months[0]);
    aux = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        aux[i] = (char *)malloc(strlen(months[i]) + 1);
        strcpy(aux[i], months[i]);
    }

    mergesort(months, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%s\n", months[i]);

    // Uvoľnenie pamäte pre pomocné pole reťazcov
    for (int i = 0; i < n; i++)
        free(aux[i]);
    free(aux);

    return 0;
}
