#include <stdio.h>
#include <string.h>

void insertionSort(char a[][20], int n)
{
   for (int i = 1; i < n; i++)
   {
      char tmp[20];
      strcpy(tmp, a[i]); // the element to be inserted
      int j;
      for (j = i; j > 0 && strcmp(tmp, a[j - 1]) < 0; j--)
         strcpy(a[j], a[j - 1]); // shift elements
      strcpy(a[j], tmp); // insert
   }
}

int main(void) {
    char months[][20] = {"January", "February", "March", "April", "May", "June", "July",
                         "August", "September", "October", "November", "December"};
    int n = sizeof(months) / sizeof(months[0]);

    insertionSort(months, n);

    for (int i = 0; i < n; i++)
        printf("%s\n", months[i]);

    return 0;
}
