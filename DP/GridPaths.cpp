/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

bool grid[1100][1100];
i64 dp[1100][1100];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            char C; cin >> C;
            if(C == '*') grid[i][j] = 0;
            else grid[i][j] = 1;
        }
    }
    // dp[i][j] -> number of ways to get to N * N through the cell (i, j);
    constexpr int MOD = 1e9 + 7;
    dp[0][0] = (grid[0][0])?1:0; // base case for 1 x 1 grid
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(grid[i][j]) {
                if(i-1 >= 0) (dp[i][j] += dp[i-1][j]) %= MOD; // when we move right
                if(j-1 >= 0) (dp[i][j] += dp[i][j-1]) %= MOD; // when we move down
                
            } else {
                dp[i][j] = 0; // else if we find a trap there is no way to get to N * N through this path
            }
        }
    }
    cout << dp[N-1][N-1];
    return 0;
}
