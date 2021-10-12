#include <stdio.h>

int tara[5][5], tarr[5][5], avail[5];
int alloc[5];
int max[5], ctr[5], safe = 0;
int counter = 0, i, j, exec, tot, p, k = 1, inc = 0, total = 0;

int main() {
  printf("\nEnter number of Process: ");
  scanf("%d", & p);

  for (i = 0; i < p; i++) {
    ctr[i] = 1;
    counter++;
  }
  int arr[p];
  printf("\nEnter number of Resource: ");
  scanf("%d", & tot);

  printf("\nEnter maximum availabe:");
  for (i = 0; i < tot; i++) {
    scanf("%d", & max[i]);
  }

  printf("\nEnter Resource Allocation Table:\n");
  for (i = 0; i < p; i++) {
    for (j = 0; j < tot; j++) {
      scanf("%d", & tara[i][j]);
    }
  }

  printf("Enter Maximum Need Table:\n");
  for (i = 0; i < p; i++) {
    for (j = 0; j < tot; j++) {
      scanf("%d", & tarr[i][j]);
    }
  }

  for (i = 0; i < p; i++) {
    for (j = 0; j < tot; j++) {
      alloc[j] += tara[i][j];
    }
  }
  for (i = 0; i < tot; i++) {
    avail[i] = max[i] - alloc[i];
  }
  while (counter != 0) {
    safe = 0;
    for (i = 0; i < p; i++) {
      if (ctr[i]) {
        exec = 1;
        for (j = 0; j < tot; j++) {
          if (tarr[i][j] - tara[i][j] > avail[j]) {
            exec = 0;
            break;
          }
        }
        if (exec) {
          arr[inc] = i + 1;
          inc++;
          ctr[i] = 0;
          counter--;
          safe = 1;

          for (j = 0; j < tot; j++) {
            avail[j] += tara[i][j];
          }
          break;
        }
      }
    }
    if (!safe) {
      break;
    } else {
      total++;
    }
  }
  if (total == p) {
    printf("Safe sequence is\n");
    for (int x = 0; x < inc; x++)
      printf("P[%d]->", arr[x]);
  } else
    printf("\n Not safe.\n");
  return 0;
}
