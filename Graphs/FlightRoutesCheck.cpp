/*亲爱的上帝，我求你给我力量来赢得这场战斗。*/
#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
vector<int> adj[200100][2];
vector<bool> vis(200100);
int i1 = -1;
void dfs(int i, int j) {
    vis[i] = 1;
    for(auto y:adj[i][j]) {
        if(!vis[y]) dfs(y, j);
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        adj[--a][0].push_back(--b);
        adj[b][1].push_back(a);
    }
    dfs(0,0);
    for(int i=0; i<N; i++) {
        if(!vis[i]) {
            cout << "NO\n";
            cout << 1 << " " << i + 1 << "\n";
            return 0;
        }
    }
    vis.assign(N, 0);
    dfs(0,1);
    for(int i=0; i<N; i++) {
        if(!vis[i]) {
            cout << "NO\n";
            cout << i+1 << " " << 1 << "\n";
            return 0;
        }
    }
    cout << "YES\n";
 
    
    return 0;
}
