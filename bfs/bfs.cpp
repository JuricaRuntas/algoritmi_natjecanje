#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void vanilla_bfs(vector<int> adj_list[], int s, int v){
  bool visited[v+1];
  queue<int> q;
  visited[s] = true;
  q.push(s);
  while (!q.empty()){
    int current_vertex = q.front();
    q.pop();
    cout << current_vertex << " ";
    for (auto i : adj_list[current_vertex]){
      if (visited[i]) continue;
      visited[i] = true;
      q.push(i);
    }
  }
}

void shortest_path_bfs(vector<int> adj_list[], int s, int d, int v){
  int distance[v+1];
  bool visited[v+1];
  queue<int> q;
  distance[s] = 0;
  visited[s] = true;
  q.push(s);
  while (!q.empty()){
    int current_vertex = q.front();
    q.pop();
    for (auto i : adj_list[current_vertex]){
      if (visited[i] == true) continue;
      visited[i] = true;
      distance[i] = distance[current_vertex]+1;
      q.push(i);
    }
  }
  cout << distance[d];
}

void restore_shortest_path_bfs(vector<int> adj_list[], int s, int d, int v){
  int distance[v+1];
  bool visited[v+1];
  int parent[v+1];
  queue<int> q;
  distance[s] = 0;
  visited[s] = true;
  parent[s] = -1;
  q.push(s);
  while (!q.empty()){
    int current_vertex = q.front();
    q.pop();
    for (int i : adj_list[current_vertex]){
      if (visited[i]) continue;
      visited[i] = true;
      distance[i] = distance[current_vertex]+1;
      parent[i] = current_vertex;
      q.push(i);
    }
  }

  vector<int> restored_path;
  for (int v = d; v != -1; v = parent[v]){
    restored_path.push_back(v);
  }
  reverse(restored_path.begin(), restored_path.end());
  for (auto u : restored_path){
    cout << u << " ";
  }
}

int main(){
  // graph from Guide to Competitive Programming - page 85
  int v = 6;
  vector<int> adj_list[v+1];
  adj_list[1].push_back(2);
  adj_list[1].push_back(4);

  adj_list[2].push_back(1);
  adj_list[2].push_back(3);
  adj_list[2].push_back(5);

  adj_list[3].push_back(2);
  adj_list[3].push_back(6);

  adj_list[4].push_back(1);

  adj_list[5].push_back(2);
  adj_list[5].push_back(6);
  
  adj_list[6].push_back(3);
  adj_list[6].push_back(5);
  
  vanilla_bfs(adj_list, 1, v);
  cout << "\n";
  shortest_path_bfs(adj_list, 1, 3, v); 
  cout << "\n";
  restore_shortest_path_bfs(adj_list, 1, 3, v);
  
  return 0;
}
