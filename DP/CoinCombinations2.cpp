/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
 
i64 dp[1000010];
int main() {
    // Read the Notes!!
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 N, S;
    cin >> N >> S;
    vector<int> a(N);
    for(int i=0; i<N; i++) {
        cin >> a[i];
    }
    //dp[i] -> now represents number of ways to form sum S using only one coin at a time;
    dp[0] = 1;
    constexpr int MOD = 1e9 + 7;
    
    for(int j=0; j<N; j++) {
        for(int i=1; i<=S; i++) {
            if(a[j] <= i) {
                (dp[i] += dp[i-a[j]]) %= MOD; // if(a[j] <= current sum (i)) dp[i] = dp[i] + dp[i-a[j]] (i.e) number of ways form sum (i-a[j]) 
            }
        }
    }
    

    cout << dp[S]; // total ways to form sum S -> dp[S];

    /* Note that it also counts disjoint sets forming the sum = S
    For Example: to form 9 -> (2 2 5 && 2 5 2) are counted as two separate ways.
    */

    /* Note that this problem asks us to find ordered ways i.e non disjoint sets forming sum S
    dp[i] -> now represents number of ways to form sum S using only one coin at a time;
    so this makes it ordered as we only use a coin once and its never repeated!
    */
    
    return 0;
}
