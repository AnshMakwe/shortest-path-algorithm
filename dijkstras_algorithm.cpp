#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll ;
#define mo 1000000007
using namespace std ;
using namespace __gnu_pbds ;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds ;

class graph{
    int v ;
    list<pair<int, int>> *l ;
public:
    graph(int v) {
        this->v = v ;
        l = new list<pair<int, int>> [v] ;
    }
    void addEdge(int u, int v, int wt, bool undir = true) {
        l[u].push_back({wt, v}) ;
        if (undir)
            l[v].push_back({wt, u}) ;
    }

    int dijkstra(int src, int des) {
        // datastructure
        vector<int> dis(v, INT_MAX) ;
        set<pair<int, int>> s ;

        // intialization
        dis[src] = 0 ;
        s.insert({0, 0}) ;

        while (!s.empty()) {
            auto it = s.begin() ;
            int node = it->second ;
            int disTillNow = it->first ;
            s.erase(it) ;

            // iterate over the edges of node
            for (auto nbrPair: l[node]) {
                int nbr = nbrPair.second ;
                int currentEdge = nbrPair.first ;

                if (disTillNow + currentEdge < dis[nbr]) {
                    // remove if nbr already exisit in the set
                    auto f = s.find({dis[nbr], nbr}) ;
                    if (f != s.end())
                        s.erase(f) ;
                    // insert the updated value of new distance
                    dis[nbr] = disTillNow + currentEdge ;
                    s.insert({dis[nbr], nbr}) ;
                }
            }
        }
        return dis[des] ;
    }
};
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0) ;
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin) ;
    freopen("Output.txt", "w", stdout) ;
#endif
    int n, m ;
    cin >> n >> m ;
    graph g(n) ;
    while (m--) {
        int u, v, wt ;
        cin >> u >> v >> wt ;
        g.addEdge(u, v, wt) ;
    }

    cout << g.dijkstra(0, n-1) << "\n" ;
    return 0;
}