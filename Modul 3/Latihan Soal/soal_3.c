#include <stdio.h>

int MAX_T = 10000;
int INF = 1000000000;

int minCoins(int coins[], int K, int T) {
    int dp[MAX_T + 1];
    int t, i;

    dp[0] = 0;
    for (t = 1; t <= T; t++) {
        dp[t] = INF;
    }

    for (t = 1; t <= T; t++) {
        for (i = 0; i < K; i++) {
            if (coins[i] <= t && dp[t - coins[i]] != INF) {
                if (dp[t - coins[i]] + 1 < dp[t]) {
                    dp[t] = dp[t - coins[i]] + 1;
                }
            }
        }
    }

    if (dp[T] == INF) {
        return -1;
    }
    return dp[T];
}

int main() {
    int K, T;
    int coins[100];

    scanf("%d %d", &K, &T);
    for (int i = 0; i < K; i++) {
        scanf("%d", &coins[i]);
    }

    printf("%d", minCoins(coins, K, T));
    return 0;
}