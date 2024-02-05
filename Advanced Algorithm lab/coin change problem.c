#include <stdio.h>
int count(int coins[], int n, int ways)
{
 int i, j, a, b;
 int table[ways + 1][n];
 for (i=0; i < n; i++){
     table[0][i] = 1;
 }
 for (i=1; i < ways + 1; i++){
   for (j = 0; j < n; j++){
     a = (i- coins[j] >= 0)? table[i - coins[j]][j]: 0;
     b = (j >= 1)? table[i][j - 1]:0;
     table[i][j]=a + b;
   }
 }
 return table[ways][n-1];
}
  int main()
  {
  int coins[] = {1, 2, 3, 5};
  int n = sizeof(coins)/ sizeof(coins[0]);
  int ways = 5;
    printf("Coin change can be possible in %d ways\n" , count(coins, n, ways));
 return 0;
}
