#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll ;
#define mo 1000000007
#define INF 100000000
using namespace std ;
using namespace __gnu_pbds ;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds ;

vector<vector<int>> floyd_warshall(vector<vector<int>> graph) {
    vector<vector<int>> dis(graph) ;
    int v = graph.size() ;
    for (int k=0; k<v; ++k) {
        for (int i=0; i<v; ++i) {
            for (int j=0; j<v; ++j) {
                // if vertices k is included and we can minimise the distance ?
                if (dis[i][j] > dis[i][k] + dis[k][j])
                    dis[i][j] = dis[i][k] + dis[k][j] ;
            }
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
    vector<vector<int>> graph = {
            {0, INF, -2, INF},
            {4, 0, 3, INF},
            {INF, INF, 0, 2},
            {INF, -1, INF, 0}
    } ;
    return 0;
}