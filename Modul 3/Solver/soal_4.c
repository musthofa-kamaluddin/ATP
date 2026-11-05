#include <stdio.h>
int N, K;
int W[100];
long long V[100];
long long dp[101][1001];

int max(long long a, long long b) { return (a > b)? a : b; }
int knapsack(){//dikasih bacaan, aq baca di https://www.thecrazyprogrammer.com/2016/10/knapsack-problem-c-using-dynamic-programming.html dan nemu klw ini knapsack dari https://cgi.cse.unsw.edu.au/~cs4128/20t3/lectures/3-dp.pdf at slide 31
    for (int i = 0; i <= N; i++){
        for(int j = 0; j <= K; j++){
            if (i == 0 || j == 0){
                dp[i][j] = 0;
            }else if(W[i-1] <= j){
                dp[i][j] = max(V[i-1] + dp[i-1][j - W[i-1]],  dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[N][K];
}
int main(){
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++){
        scanf("%d %lld", &W[i], &V[i]);
    }
    printf("%lld", knapsack());
    return 0;
}