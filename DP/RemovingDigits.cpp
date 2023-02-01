/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

i64 dp[1000110];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N;
    cin >> N;
    dp[0] = 0; // no step required number already 0
    // dp[i] -> minimum steps required to get the number i to zero
    for(int i=1; i<=N; i++) {
        dp[i] = 1e9; // set it to some max val
        i64 W = i; 
        while(W) {
            int Y = W % 10; // unit digits of i;
            if(Y) dp[i] = min(dp[i], 1 + dp[i-Y]); // if the digit is not already 0 then we can count the min of dp[i], using Y(+1) + dp[i-Y];
            W /= 10;
        }
    }
    cout << dp[N];
    
    return 0;
}
