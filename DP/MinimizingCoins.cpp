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
    // what does dp[i] represent?
    // dp[i] -> minimum coins required to form the sum = i;
    
    dp[0] = 0; // there is no way we can form sum == 0; so as a base case we can set dp[0] = 0;
    for(int i=1; i<=S; i++) {
        dp[i] = 1e9; // setting the total coins required to form sum i = 1e9(max value);
        for(int j=0; j<N; j++) {
            if(a[j] <= i) { // if the coin value >= sum being formed
                dp[i] = min(dp[i], dp[i-a[j]] + 1); // add 1 coin to the formation of the sum dp[i-a[j]], this coin added will be having value = a[j];
            }
        }
    }

    cout << ((dp[S] == 1e9)?-1:dp[S]); // finally if dp[S] = 1e9, this means sum S was never formed hence we return -1 else the minimum coins required to form sum S i.e. dp[S]
    
    return 0;
}
