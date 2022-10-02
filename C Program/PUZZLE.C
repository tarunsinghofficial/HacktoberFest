#include<stdio.h>

#include<conio.h>

#include<values.h>

int p[4][4], u[4][4], r[4][4], d[4][4], l[4][4], less[16], s[4][4], pr1[4][4], pr2[4][4];
int cost, x, ucost, dcost, lcost, rcost, f = 0, node = 1, level = 0;
char result[50];
void display(int[4][4]);
void lessf();
int costf(int[4][4]);
int pos(int);
int up(int[4][4]);
int right(int[4][4]);
int down(int[4][4]);
int left(int[4][4]);
int isgoal(int[4][4]);
int decide();
void transfer(int[4][4], int[4][4]);
void main() {
  int i, j, choice;
  printf("\n\nWould you like to initialize the 15 Puzzle Problem.\n");
  printf("Press 1 if Yes or Press 0 if No : ");
  scanf("%d", & choice);
  if (choice == 0) {
    for (i = 0; i < 4; i++)

    {
      for (j = 0; j < 4; j++) {
        p[i][j] = ((4 * i) + (j + 1) + 1) % 16;
        s[i][j] = p[i][j];
        if (p[i][j] == 16) {
          if ((i + j) % 2 == 1)
            x = 1;
          else
            x = 0;
        }
      }
    }
  } else {
    printf("\nEnter the values of 15 Puzzle Problem Row-wise.\n");
    printf("Enter value 16 for empty slot.\n");
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        scanf("%d", & p[i][j]);
        s[i][j] = p[i][j];
        if (p[i][j] == 16) {
          if ((i + j) % 2 == 1)
            x = 1;
          else
            x = 0;
        }
      }
    }
  }
  display(p);
  printf("\nX=%d", x);
  lessf();
  cost = costf(p);
  printf("\nCost of Initial Arrangement(Node%d) is %d.", node++, cost);
  while (!isgoal(p)) {
    f++;
    level++;
    ucost = up(p);
    if (ucost != 0)
      printf("Cost of UP Move(Node%d) is %d.\n", node++, ucost);

    else
      ucost = MAXINT;
    rcost = right(p);
    if (rcost != 0)
      printf("Cost of RIGHT Move(Node%d) is %d.\n", node++, rcost);
    else
      rcost = MAXINT;
    dcost = down(p);
    if (dcost != 0)
      printf("Cost of DOWN Move(Node%d) is %d.\n", node++, dcost);
    else
      dcost = MAXINT;
    lcost = left(p);
    if (lcost != 0)
      printf("Cost of LEFT Move(Node%d) is %d.\n", node++, lcost);
    else
      lcost = MAXINT;
    choice = decide();
    getch();
    switch (choice) {
    case 1:
      printf("\nYou have selected UP Move.\n");
      printf("And Puzzle Arrangement is:\n");
      display(p);
      result[level] = 'U ';
      break;
    case 2:
      printf("\nYou have selected RIGHT Move.\n");
      printf("And Puzzle Arrangement is:\n");
      display(p);
      result[level] = 'R ';
      break;
    case 3:
      printf("\nYou have selected DOWN Move.\n");
      printf("And Puzzle Arrangement is:\n");
      display(p);
      result[level] = 'D ';
      break;
    case 4:
      printf("\nYou have selected LEFT Move.\n");

      printf("And Puzzle Arrangement is:\n");
      display(p);
      result[level] = 'L ';
      break;
    }
    if (level % 2 == 1) {
      transfer(pr1, p);
      if (level >= 3)
        transfer(s, pr2);
    } else {
      transfer(pr2, p);
      if (level >= 2)
        transfer(s, pr1);
    }
  }
  getch();
  printf("\n\nGoal Arrangement is as follows:\n");
  display(p);
  printf("\nSequence of Moves are as follows:\n");
  for (i = 1; i <= level; i++)
    printf("%c", result[i]);
  getch();
}
int decide() {
  int m;
  cost = ucost;
  m = 1;
  if (cost > rcost) {
    cost = rcost;
    m = 2;
  }
  if (cost > dcost) {
    cost = dcost;
    m = 3;
  }

  if (cost > lcost) {
    cost = lcost;
    m = 4;
  }
  switch (m) {
  case 1:
    transfer(p, u);
    break;
  case 2:
    transfer(p, r);
    break;
  case 3:
    transfer(p, d);
    break;
  case 4:
    transfer(p, l);
    break;
  }
  return (m);
}
int issame(int a[4][4]) {
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (s[i][j] != a[i][j])
        return (0);
    }
  }
  return (1);
}
void transfer(int a[4][4], int b[4][4]) {
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++)

    {
      a[i][j] = b[i][j];
    }
  }
}
int isgoal(int p[4][4]) {
  int i, j, m;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      m = (4 * i) + j + 1;
      if (p[i][j] != m)
        return (0);
    }
  }
  return 1;
}
int up(int p[4][4]) {
  int i, j, m, n;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (p[i][j] == 16) {
        m = i;
        n = j;
        break;
      }
    }
  }
  if (m == 0) {
    printf("\nUP move is not possible.\n");
    return (0);
  } else {
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        u[i][j] = p[i][j];
      }
    }

    u[m][n] = u[m - 1][n];
    u[m - 1][n] = 16;
    getch();
    if (issame(u)) {
      printf("\nThe UP Move is giving Parent Node\n");
      printf("Hence UP Move is not possible.\n");
      return (0);
    } else {
      printf("\nPuzzle after UP move is:\n");
      display(u);
      ucost = costf(u);
      return (ucost);
    }
  }
}
int right(int p[4][4]) {
  int i, j, m, n;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (p[i][j] == 16) {
        m = i;
        n = j;
        break;
      }
    }
  }
  if (n == 3) {
    printf("\nRIGHT move is not possible.\n");
    return (0);
  } else {
    for (i = 0; i < 4; i++)

    {
      for (j = 0; j < 4; j++) {
        r[i][j] = p[i][j];
      }
    }
    r[m][n] = u[m][n + 1];
    r[m][n + 1] = 16;
    getch();
    if (issame(r)) {
      printf("\nThe RIGHT Move is giving Parent Node\n");
      printf("Hence RIGHT Move is not possible.\n");
      return (0);
    } else {
      printf("\nPuzzle after RIGHT move is:\n");
      display(r);
      rcost = costf(r);
      return (rcost);
    }
  }
}
int down(int p[4][4]) {
  int i, j, m, n;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (p[i][j] == 16) {
        m = i;
        n = j;
        break;
      }
    }
  }
  if (m == 3) {
    printf("\nDOWN move is not possible.\n");
    return (0);
  } else {
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        d[i][j] = p[i][j];
      }
    }
    d[m][n] = d[m + 1][n];
    d[m + 1][n] = 16;
    getch();
    if (issame(d)) {
      printf("\nThe DOWN Move is giving Parent Node\n");
      printf("Hence DOWN Move is not possible.\n");
      return (0);
    } else {
      printf("\nPuzzle after DOWN move is:\n");
      display(d);
      dcost = costf(d);
      return (dcost);
    }
  }
}
int left(int p[4][4]) {
  int i, j, m, n;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (p[i][j] == 16) {
        m = i;
        n = j;

        break;
      }
    }
  }
  if (n == 0) {
    printf("\nLEFT move is not possible.\n");
    return (0);
  } else {
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        l[i][j] = p[i][j];
      }
    }
    l[m][n] = l[m][n - 1];
    l[m][n - 1] = 16;
    getch();
    if (issame(l)) {
      printf("\nThe LEFT Move is giving Parent Node\n");
      printf("Hence LEFT Move is not possible.\n");
      return (0);
    } else {
      printf("\nPuzzle after LEFT move is:\n");
      display(l);
      lcost = costf(l);
      return (lcost);
    }
  }
}
void display(int p[4][4]) {
  int i, j;
  for (i = 0; i < 4; i++)

  {
    printf("|---------------------------------------------------------------|\n");
    for (j = 0; j < 4; j++) {
      if (p[i][j] != 16)
        printf("|\t%d\t", p[i][j]);
      else
        printf("|\t \t");
    }
    printf("|\n");
  }
  printf("|---------------------------------------------------------------|\n");
}
void lessf() {
  int i, j, k, count, m, total = 0, posi, posm;
  for (i = 2; i <= 16; i++) {
    count = 0;
    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++) {
        m = (4 * j) + k + 1;
        if (m < i) {
          posm = pos(m);
          posi = pos(i);
          if (posm > posi) {
            count++;
          }
        }
      }
    }
    less[i - 1] = count;
    total = total + count;
  }
  less[1] = 0;
  printf("The less array is as following:\n");
  for (i = 0; i < 16; i++)

  {
    printf("%d ", i + 1);
  }
  printf("\n");
  for (i = 0; i < 16; i++) {
    printf("%d ", less[i]);
  }
  if ((total + x) % 2 == 0)
    printf("\nSOLUTION IS POSSIBLE.\n");
  else {
    printf("\nSOLUTION IS NOT POSSIBLE.\n");
    getch();
    exit(0);
  }
}
int pos(int m) {
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (p[i][j] == m)
        return ((4 * i) + j + 1);
    }
  }
  return (0);
}
int costf(int p[4][4]) {
  int i, j, m;
  cost = 0;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      m = 4 * i + j + 1;
      if (p[i][j] != m)
        cost++;

    }
  }
  m = isgoal(p);
  printf("\nf(x)=%d\tg(x)=%d\n", f, (cost - 1 + m));
  cost = f + cost - 1 + m;
  return (cost);
}