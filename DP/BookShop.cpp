//This Problem is just a variation of 0/1 knapsack we are not allowed to choose the same book again. I am used 0 based indexing !
#include<bits/stdc++.h>
using namespace std ;
void solve(){
	int n , x ;
	cin >> n >> x ;
	vector<int> h(n) , s(n) ;
	for(int i=0; i<n; i++) 
		cin >> h[i] ;
	for(int i=0; i<n; i++)
		cin >> s[i] ;
	vector<vector<int>> dp(n+1 , vector<int>(x+1,0)) ;
	for(int i=0; i<n; i++){
		for(int j=0; j<=x; j++){
			dp[i+1][j] = dp[i][j] ;
		   	if(j >= h[i]){
				dp[i+1][j] = max(dp[i+1][j] , s[i] + dp[i][j - h[i]]) ;
			}	
		}
	}
	cout << dp[n][x] ;
	
}
int main(){
	ios::sync_with_stdio(false) ;
	cin.tie(nullptr) ;
	cout.tie(nullptr) ;
	solve() ;
}
