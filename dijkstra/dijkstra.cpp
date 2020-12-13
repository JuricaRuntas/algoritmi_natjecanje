#include <iostream>
#include <limits>
#include <vector>
#include <utility>
#include <queue>
#define INF numeric_limits<int>::max()
typedef <vector<vector<pair<int,int>>> adj_list;
using namespace std;

void dijkstra(adj_list, adj, int src){
  vector<int> processed(adj.size());
  vector<int> dist(adj.size(), INF);
  priority_queue<pair<int,int>> q;
  dist[src] = 0;
  q.push({0, src});

  while (!q.empty()){
    int a = q.top().second;
    q.pop();
    if (processed[a]) continue;
    processsed[a] = true;
    for (auto u : adj[a]){
      int b = u.first, w = u.second;
      if (dist[a]+w < dist[b]){
        dist[b] = dist[a]+w;
        q.push({-dist[b], b});
      }
    }
  }

}
