#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void swap(char *xp, char *yp) {
  char temp[20];
  strcpy(temp, xp);
  strcpy(xp, yp);
  strcpy(yp, temp);
}

void bubbleSort(char a[][20], int n) {
  bool sorted = false;
  int last = n - 1;
  for (int i = 0; (i < last) && !sorted; i++) {
    sorted = true;
    for (int j = last; j > i; j--)
      if (strcmp(a[j - 1], a[j]) > 0) {
        swap(a[j - 1], a[j]);
        sorted = false;
      }
  }
}

int main(void) {
  char months[][20] = {"January", "February", "March", "April", "May", "June", "July",
                        "August", "September", "October", "November", "December"};
  int n = sizeof(months) / sizeof(months[0]);

  bubbleSort(months, n);

  for (int i = 0; i < n; i++)
    printf("%s\n", months[i]);

  return 0;
}
