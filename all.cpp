#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int v = 6;
const int v_dijkstra = 5;
const int v_floyd = 5;
const int INF = 1e9;

vector<int> adj_list[v+1];
bool visited[v+1];
vector<int> topological_sort_answer;
vector<int> adj_list_topological_sort[v+1];
vector<pair<int,int>> adj_list_dijkstra[v_dijkstra+1];
int dijkstra_distances[v_dijkstra+1];
vector<vector<int>> adj_mat(v_floyd+1, vector<int>(v_floyd+1));

// graphs
void bfs(vector<int> graph[], int start, int destination, int v){
  int distance[v+1];
  int parent[v+1];
  visited[start] = true;
  distance[start] = 0;
  parent[start] = -1; 
  queue<int> q;
  q.push(start);
  while (!q.empty()){
    int curr = q.front();
    q.pop();
    cout << curr << " ";
    for (int node : graph[curr]){
      if (!visited[node]){
        visited[node] = true;
        distance[node] = ++distance[curr];
        parent[node] = curr;
        q.push(node);
      }
    }
  }
  cout << "\nDistance to node " << destination << " from node " << start << " equals " << distance[destination] << "\n";
  cout << "Reconstructed path looks like: ";
  vector<int> restored_path;
  for (int i = destination; i != -1; i = parent[i]) restored_path.push_back(i);
  reverse(restored_path.begin(), restored_path.end());
  for (int v : restored_path) cout << v << " ";
  cout << "\n";
};

void dfs(int s, bool print_bfs=true){
  if (visited[s]) return;
  visited[s] = true;
  if (print_bfs) cout << s << " ";
  for (int node : adj_list[s]){
    if (!visited[node]) dfs(node);
  }
  topological_sort_answer.push_back(s);
};

void topological_sort(){
  for (int i = 1; i <=v ; ++i){
    if (!visited[i]) dfs(i, false);
  }
  reverse(topological_sort_answer.begin(), topological_sort_answer.end());
  for (int node : topological_sort_answer) cout << node << " ";
  cout << "\n [4,5,1,2,3,6] is the answer\n";
};

void dijkstra(int source){
  priority_queue<pair<int,int>> q;
  for (int i = 0; i <= v_dijkstra; ++i){
    visited[i] = false;
    dijkstra_distances[i] = INF;
  }
  dijkstra_distances[source] = 0;
  q.push({0, source});
  while (!q.empty()){
    int curr_vertex = q.top().second;
    q.pop();
    if (visited[curr_vertex]) continue;
    visited[curr_vertex] = true;
    for (auto u : adj_list_dijkstra[curr_vertex]){
      int b = u.first, w = u.second;
      dijkstra_distances[b] = min(dijkstra_distances[b], dijkstra_distances[curr_vertex]+w);
      q.push({-dijkstra_distances[b], b});
    }
  }
  cout << "Distances: ";
  for (int i = 1; i <= v_dijkstra; ++i){
    cout << dijkstra_distances[i] << " ";
  }
  cout << "\n";
};

void floyd_warshall(vector<vector<int>> &adj_mat){
  for (int i = 1; i <= v_floyd; ++i){
    for (int j = 1; j <= v_floyd; ++j){
      if (i == j) adj_mat[i][j] = 0;
      else if (adj_mat[i][j] == 0) adj_mat[i][j] = INF;
    }
  }

  for (int k = 1; k < adj_mat.size(); ++k){
    for (int i = 1; i < adj_mat.size(); ++i){
      for (int j = 1; j < adj_mat.size(); ++j){
        adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k]+adj_mat[k][j]);
      }
    }
  }
  cout << "Distances\n";
  for (int i = 1; i < adj_mat.size(); ++i){
    for (int j = 1; j < adj_mat.size(); ++j){
      if (adj_mat[i][j] == INF) cout << "I" << " ";
      else cout << adj_mat[i][j] << " ";
    }
    cout << "\n";
  }
};

// dp
void coin_problem(){};
void lcs(){};
void lis(){};
void max_subarray_sum(){};

void print_array(vector<int> arr){
  for (int n : arr){
    cout << n << " ";
  }
  cout << "\n";
}

void create_graph_1(){
  // graph from Guide to Competitive Programming - page 85
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
}

void create_graph_2(){
  // graph from Guide to Competitive Programming -> page 95 
  adj_list_topological_sort[1].push_back(2);
  adj_list_topological_sort[2].push_back(3);
  adj_list_topological_sort[3].push_back(6);
  adj_list_topological_sort[4].push_back(1);
  adj_list_topological_sort[4].push_back(5);
  adj_list_topological_sort[5].push_back(2);
  adj_list_topological_sort[5].push_back(3);
}

void create_graph_3(){
  // example graph from Guide to Competitive Programming - page 90
  adj_list_dijkstra[1].push_back({2, 5});
  adj_list_dijkstra[1].push_back({4, 9});
  adj_list_dijkstra[1].push_back({5, 1});

  adj_list_dijkstra[2].push_back({1, 5});
  adj_list_dijkstra[2].push_back({3, 2});

  adj_list_dijkstra[3].push_back({2, 2});
  adj_list_dijkstra[3].push_back({4, 6});
  
  adj_list_dijkstra[4].push_back({1, 9});
  adj_list_dijkstra[4].push_back({3, 6});
  adj_list_dijkstra[4].push_back({5, 2});

  adj_list_dijkstra[5].push_back({1, 1});
  adj_list_dijkstra[5].push_back({4, 2});
}

void create_graph_4(){
  // graph from Guide to Competitive Programming - page 92
  adj_mat[1][2] = 5;
  adj_mat[1][4] = 9;
  adj_mat[1][5] = 1;

  adj_mat[2][1] = 5;
  adj_mat[2][3] = 2;

  adj_mat[3][2] = 2;
  adj_mat[3][4] = 7;

  adj_mat[4][1] = 9;
  adj_mat[4][3] = 7;
  adj_mat[4][5] = 2;

  adj_mat[5][1] = 1;
  adj_mat[5][4] = 2;
}

int main(){
  create_graph_1();
  cout << "### BFS ###\n";
  bfs(adj_list, 1, 6, 6);
  cout << "\n### DFS ###\n";
  memset(visited, 0, sizeof(visited));
  dfs(1);
  cout << "\n";
  memset(visited, 0, sizeof(visited));
  cout << "\n### Topological Sort ###\n";
  create_graph_2();
  memset(visited, 0, sizeof(visited));
  topological_sort();
  cout << "\n### Dijkstra ###\n";
  memset(visited, 0, sizeof(visited));
  create_graph_3();
  dijkstra(1);
  cout << "\n### Floyd Warshall ###\n";
  memset(visited, 0, sizeof(visited));
  create_graph_4();
  floyd_warshall(adj_mat);
  return 0;
}