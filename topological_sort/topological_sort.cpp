#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int v = 6;
bool visited[v+1];
vector<int> adj_list[v+1];
vector<int> ans;

void dfs(int s){
  if (visited[s]) return;
  visited[s] = true;
  for (auto u : adj_list[s]){
    if (visited[u]) continue;
    dfs(u);
  }
  ans.push_back(s);
}

void topological_sort(){
  for (int i = 1; i <= v; ++i){
    if (visited[i]) continue;
    dfs(i);
  }
  reverse(ans.begin(), ans.end());
  
  for (auto u : ans){
    cout << u << " ";
  }
}

int main(){
  // graph from Guide to Competitive Programming -> page 95 
  adj_list[1].push_back(2);
  adj_list[2].push_back(3);
  adj_list[3].push_back(6);
  adj_list[4].push_back(1);
  adj_list[4].push_back(5);
  adj_list[5].push_back(2);
  adj_list[5].push_back(3);

  topological_sort();
  
  return 0;
}
