#include<stdbool.h>

bool SubsetSum(const int arr[], int n, int sum) {
    bool dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int main() {
    const int n = 5; // Size of the array
    int arr[] = {1, 3, 5, 7, 10};
    int sum = 11;

    if (SubsetSum(arr, n, sum))
        printf("Subset with the number %d exists.\n", sum);
    else
        printf("No subset with the number %d exists.\n", sum);

    return 0;
}
