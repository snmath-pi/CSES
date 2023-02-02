/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 dp[5050][5050];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string S, T;
    cin >> S >> T;
    int N = (int) S.length();
    int M = (int) T.length();
    /* dp[i][j] -> min moves required to change s[:i] to t[:j];
    Now 4 cases can arise
    1. we remove the s[:i-1] character so it would cost us 1 + dp[i-1][j] operations
    2. we remove the t[:j-1] character so it would cost us 1 + dp[i][j-1] operations
    3. we replace the i-1th character with j-1 so it would cost ->
    1 + dp[i-1][j-1] op if (s[i-1] != t[j-1]) else dp[i-1][j-1] operations
    */
    for(int i=0; i<=5010; i++) {
        for(int j=0; j<=5010; j++) {
            dp[i][j] = 1e9; 
        }
    }
    dp[0][0] = 0;
    for(int i=0; i<=N; i++) {
        for(int j=0; j<=M; j++) {
        
            if(i) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            if(j) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            if(i && j) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (S[i-1] != T[j-1]));
        }
    }
    
    cout << dp[N][M];
    return 0;
}
