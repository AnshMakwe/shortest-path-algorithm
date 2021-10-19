#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll ;
#define mo 1000000007
using namespace std ;
using namespace __gnu_pbds ;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds ;

vector<int> bellman_ford(int n, int src, vector<vector<int>> edges) {
    vector<int> dis(n, INT_MAX) ;
    dis[src] = 0 ;
    for(int i=0; i<n-1; ++i) {
        for(auto edge: edges) {
            int u = edge[0], v = edge[1], wt = edge[2] ;
            if (dis[u] + wt < dis[v] and dis[u] != INT_MAX)
                dis[v] = dis[u] + wt ;
        }
    }

    // negative weight cycle
    for(auto edge: edges) {
        int u = edge[0], v = edge[1], wt = edge[2] ;
        if (dis[u] + wt < dis[v] and dis[u] != INT_MAX) {
            cout << "negative weight cycle found\n" ;
            exit(0) ;
        }
    }
    return dis ;
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0) ;
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin) ;
    freopen("Output.txt", "w", stdout) ;
#endif
    vector<vector<int>> edges ;
    int n, m ;
    cin >> n >> m ;
    while(m--) {
        int x, y, wt ;
        cin >> x >> y >> wt ;
        edges.push_back({x, y, wt}) ;
    }
    vector<int> dis = bellman_ford(n, 0, edges) ;
    for (int i=0; i<n; ++i)
        cout << "node " << i << " is at distance " << dis[i] << "\n" ;
    return 0;
}