#include <iostream>
#include <vector>
using namespace std;

// Function to count number of ways to make change
long long getWays(int n, vector<int> coins) {
    vector<long long> dp(n + 1, 0);
    dp[0] = 1; // 0 amount ke liye 1 tareeka

    // Har coin ke liye loop
    for (int i = 0; i < coins.size(); i++) {
        int coin = coins[i];
        
        // Us coin se banne wale sabhi amounts ke liye loop
        for (int amount = coin; amount <= n; amount++) {
            dp[amount] += dp[amount - coin];
        }
    }

    return dp[n];
}

int main() {
    int n, m;
    cin >> n >> m; // Amount and number of coins

    vector<int> coins(m);
    for (int i = 0; i < m; i++) {
        cin >> coins[i]; // Coin values
    }

    cout << getWays(n, coins) << endl;

    return 0;
}
