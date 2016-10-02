/* Dijikstra algo */

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
 
#define MAX 100001
#define INF (1<<20)
#define pii pair< int, int >
#define pb(x) push_back(x)
 
struct comp {
    bool operator() (const pii &a, const pii &b) {
        return a.second > b.second;
    }
};
 
priority_queue< pii, vector< pii >, comp > Q;
vector< pii > G[MAX];		
int dist[MAX];
bool done[MAX];
 
int main() {
    int i, u, v, w, sz, nodes, edges, starting;
 
    // input graph
    scanf("%d %d", &nodes, &edges);
    for(i=0; i<edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        G[u].pb(pii(v, w));
        G[v].pb(pii(u, w)); // for undirected
    }
    scanf("%d", &starting); // starting node of dijikstra
 
    // initialize distance vector to INF 
    for(i=1; i<=nodes; i++) 
    	dist[i] = INF;
    	
    dist[starting] = 0;
    Q.push(pii(starting, 0));
 
    // dijkstra
    while(!Q.empty()) {
        u = Q.top().first;
        Q.pop();
        if(done[u]) continue;
        sz = G[u].size();
        for(i=0; i<sz; i++) {
            v = G[u][i].first;
            w = G[u][i].second;
            if(!done[v] && dist[u]+w < dist[v]) {
                dist[v] = dist[u] + w;
                Q.push(pii(v, dist[v]));
            }
        }
        done[u] = 1; // done with u
    }
 
    // result
    for(i=1; i<=nodes; i++) 
    	printf("Node %d, min distance = %d\n", i, dist[i]);
    return 0;
}
