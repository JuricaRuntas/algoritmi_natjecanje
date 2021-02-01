#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int v = 6;
vector<int> adj_list[v+1];
bool visited[v+1];
vector<int> topological_sort_answer;

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

void dijkstra(){};
void floyd_warshall(){};

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
  for (int i = 0; i <= v; ++i) adj_list[i].clear();
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
  for (int i = 0; i <= v; ++i) adj_list[i].clear();
  adj_list[1].push_back(2);
  adj_list[2].push_back(3);
  adj_list[3].push_back(6);
  adj_list[4].push_back(1);
  adj_list[4].push_back(5);
  adj_list[5].push_back(2);
  adj_list[5].push_back(3);
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
  return 0;
}