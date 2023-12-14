#include <stdio.h>
#include <string.h>

void swap(char *xp, char *yp);

static int partition(char *a[], int l, int r) {
    int i = l - 1, j = r;
    char *v = a[r];
    for (;;) {
        while (strcmp(a[++i], v) < 0)
            ;
        while (strcmp(v, a[


]) < 0)
            if (j == l)
                break;
        if (i >= j)
            break;
        swap(a[i], a[j]);
    }
    swap(a[i], a[r]);
    return i;
}

static void quicksort(char *a[], int l, int r) {
    if (r <= l)
        return;
    int i = partition(a, l, r);
    quicksort(a, l, i - 1);
    quicksort(a, i + 1, r);
}

int main(void) {
    char *months[] = {"January", "February", "March", "April", "May", "June", "July",
                      "August", "September", "October", "November", "December"};
    int n = sizeof(months) / sizeof(months[0]);
    quicksort(months, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%s\n", months[i]);

    return 0;
}

void swap(char *xp, char *yp) {
    char temp[20];
    strcpy(temp, xp);
    strcpy(xp, yp);
    strcpy(yp, temp);
}
