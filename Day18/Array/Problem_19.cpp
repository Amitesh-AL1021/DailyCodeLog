#include <bits/stdc++.h>
using namespace std;

/*
    Function: getWays
    ------------------
    Calculates the number of ways to make 'n' using given coin denominations.

    Parameters:
        - n: The total amount to form using coins.
        - coins: A vector of available coin denominations.

    Returns:
        - Number of combinations (ways) to make amount 'n'.
*/
long long getWays(int n, vector<int>& coins) {
    // dp[i] will store the number of ways to form amount 'i'
    vector<long long> dp(n + 1, 0);

    // Base case: There is one way to make amount 0 (use no coins)
    dp[0] = 1;

    // Loop through each coin
    for (int coin : coins) {
        // Update dp table for all amounts >= coin
        for (int amount = coin; amount <= n; ++amount) {
            dp[amount] += dp[amount - coin];
        }
    }

    return dp[n];
}

int main() {
    int n, m; // n = target amount, m = number of coin types
    cin >> n >> m;

    vector<int> coins(m);
    for (int i = 0; i < m; ++i) {
        cin >> coins[i];
    }

    // Call the function and print result
    cout << getWays(n, coins) << endl;
    return 0;
}
