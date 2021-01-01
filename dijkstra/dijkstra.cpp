#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
using namespace std;

const int INF = 1e9;

void dijkstra(vector<pair<int, int>> adj_list[], int s, int n){
  bool visited[n+1];
  int dist[n+1];
  priority_queue<pair<int, int>> q;
  
  for (int i = 0; i <= n; ++i){
    visited[i] = false;
    dist[i] = INF;
  }

  dist[s] = 0;
  q.push({0, s});
  
  while (!q.empty()){
    int a = q.top().second;
    q.pop();
    if (visited[a]) continue;
    visited[a] = true;
    for (pair<int, int> u : adj_list[a]){
      int b = u.first, w = u.second;
      dist[b] = min(dist[b], dist[a]+w);
      q.push({-dist[b], b});
    }
  }
  for (int i = 1; i <= n; ++i){
    cout << dist[i] << " ";
  }
}

int main(){
  int n = 5;
  vector<pair<int, int>> adj_list[n+1];

  // example graph from Guide to Competitive Programming - page 90
  adj_list[1].push_back({2, 5});
  adj_list[1].push_back({4, 9});
  adj_list[1].push_back({5, 1});

  adj_list[2].push_back({1, 5});
  adj_list[2].push_back({3, 2});

  adj_list[3].push_back({2, 2});
  adj_list[3].push_back({4, 6});
  
  adj_list[4].push_back({1, 9});
  adj_list[4].push_back({3, 6});
  adj_list[4].push_back({5, 2});

  adj_list[5].push_back({1, 1});
  adj_list[5].push_back({4, 2});
  
  dijkstra(adj_list, 1, n);

  return 0;
}
