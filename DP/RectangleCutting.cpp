/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int mxN = 510;
i64 dp[mxN][mxN];
int w, h;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> w >> h;
    for(int i=1; i<=w; i++) {
        for(int j=1; j<=h; j++) {
            dp[i][j] = 1e12;
        }
    }
    for(int i=1; i<mxN; i++) {
        dp[i][i] = 0;
    }
    for(int i=1; i<=w; i++) {
        for(int j=1; j<=h; j++) {
            for(int hor = 1; hor < j; hor++) {
                dp[i][j] = min(dp[i][j], dp[i][hor] + dp[i][j-hor] + 1);
            }
            for(int ver = 1; ver < i; ver++) {
                dp[i][j] = min(dp[i][j], dp[ver][j] + dp[i-ver][j] + 1);
            }
        }
    }
    cout << dp[w][h] << "\n";
    return 0;
}
