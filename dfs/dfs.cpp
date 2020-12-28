#include <iostream>
#include <vector>
using namespace std;

const int v = 5;
bool visited[v+1];
vector<int> adj_list[v+1];

void dfs(int s){
  if (visited[s]) return;
  visited[s] = true;
  cout << s << " ";
  for (auto u : adj_list[s]){
    if (visited[u]) continue;
    dfs(u);
  }
}

int main(){
  // graph from Competitive Programmer's Handbook - page 117
  adj_list[1].push_back(2);
  adj_list[1].push_back(4);

  adj_list[2].push_back(1);
  adj_list[2].push_back(3);
  adj_list[2].push_back(5);
  
  adj_list[3].push_back(2);
  adj_list[3].push_back(5);
  
  adj_list[4].push_back(1);
  
  adj_list[5].push_back(2);
  adj_list[5].push_back(3);
  
  dfs(1);
  
  return 0;
}
