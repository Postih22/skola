#include <stdio.h>
#include <string.h>

void swap(char *xp, char *yp) {
  char temp[20];
  strcpy(temp, xp);
  strcpy(xp, yp);
  strcpy(yp, temp);
}

void selectionSort(char a[][20], int size) {
  for (int i = 0; i < size; i++) {
    int minIndex = i; // find index of smallest element
    for (int j = i + 1; j < size; j++) {
      if (strcmp(a[j], a[minIndex]) < 0) {
        minIndex = j;
      }
    }
    swap(a[i], a[minIndex]); // swap smallest element with a[i]
  }
}

int main(void) {
  char months[][20] = {"January", "February", "March", "April", "May", "June", "July",
                        "August", "September", "October", "November", "December"};
  int n = sizeof(months) / sizeof(months[0]);

  selectionSort(months, n);

  for (int i = 0; i < n; i++)
    printf("%s\n", months[i]);

  return 0;
}
