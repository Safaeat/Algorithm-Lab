// Function to find the floor of the square root of `x`
#include <stdio.h>
int findSqrt(int x)
{
// find the first positive number `i` such that `i×i` is greater than `x`
  int i = 1;
  while (i*i <= x) {
  i++;
  }
 return i - 1;
}

int main(void)
{
for (int i = 0; i <= 16; i++) {
printf("sqrt(%d) = %d\n", i, findSqrt(i));
}

return 0;
}
