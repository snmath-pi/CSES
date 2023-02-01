/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int mxN = 1000010;
i64 dp[mxN];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    cin >> N;
    constexpr int MOD = 1e9 + 7;
    dp[0] = 1; // the only way to form sum 0 is by not rolling the dice at all (1 way)
    for(int i=1; i<=N; i++) {
        // dp[i] -> the number of ways to form sum i
        // we have choices uptil min(i, number on the die);
        for(int j=1; j<=min(i, 6); j++) {
            (dp[i] += dp[i-j]) %= MOD;
        }
    }
    cout << dp[N];
    
    return 0;
}
