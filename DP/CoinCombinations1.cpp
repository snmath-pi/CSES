/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
 
i64 dp[1000010];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, S;
    cin >> N >> S;
    vector<int> a(N);
    for(int i=0; i<N; i++) {
        cin >> a[i];
    }
    // Again dp[i] -> number of ways to form the sum == i;
    dp[0] = 1;
    constexpr int MOD = 1e9 + 7;
    for(int i=1; i<=S; i++) {
        for(int j=0; j<N; j++) {
            if(a[j] <= i) {
                (dp[i] += dp[i-a[j]]) %= MOD; // if(a[j] <= current sum (i)) dp[i] = dp[i] + dp[i-a[j]] (i.e) number of ways form sum (i-a[j]) 
            }
        }
    }

    cout << dp[S]; // total ways to form sum S -> dp[S];

    /* Note that it also counts disjoint sets forming the sum = S
    For Example: to form 9 -> (2 2 5 && 2 5 2) are counted as two separate ways.
    */
    
    return 0;
}
