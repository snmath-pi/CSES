/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int mxN = 1e6 + 10;
constexpr int MOD = 1e9 + 7;
i64 dp[mxN][8];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T, N;
    cin >> T;
    for(int i=0; i<8; i++) {
        dp[0][i] = 1;
    }
    for(int i=1; i<mxN; i++) {
        for(int j=0; j<8; j++) {
            if(j == 0 || j == 2 || j == 3 || j == 4 || j == 5) {
                dp[i][j] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4] + dp[i-1][5] ) % MOD;
            } else {
                dp[i][j] = (dp[i-1][2] + dp[i-1][7] + dp[i-1][6]) % MOD;
            }
        }
    }
    while(T--) {
        cin >> N;
        cout << (dp[N-1][2] + dp[N-1][6]) % MOD << "\n";
    }
    
    return 0;
}
