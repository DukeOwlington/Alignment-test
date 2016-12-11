#include <stdio.h>
#include <stdlib.h>

char str[15] = "100001000010000";

struct TestOne {
  char a;
  int b;
};

struct TestTwo {
  char a;
  int b;
}__attribute__((__packed__));

int main()
{
  int i = 3;
  struct TestOne *test1;
  struct TestTwo *test2;
  test1 = (struct TestOne*)str;
  test2 = (struct TestTwo*)str;
  printf("Size of not aligned structure: %d\n", sizeof(struct TestOne));
  printf("Size of aligned structure: %d\n\n", sizeof(struct TestTwo));

  printf("Reading with not aligned structure:\n");
  for (i = 0; i < 3; i++) {
    printf("%c\n",test1->a);
    printf("%d\n", test1->b);
    test1++;
  }

  printf("\nReading with aligned structure:\n");
  for (i = 0; i < 3; i++) {
    printf("%c\n",test2->a);
    printf("%d\n", test2->b);
    test2++;
  }

  return 0;
}
