#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> adj_mat, int start, vector<int>& visited){
  visited[start] = true;
  cout << start << " ";
  for (int i = 0; i < adj_mat.size(); ++i){
    if (!visited[i] && adj_mat[start][i]){
      dfs(adj_mat, i, visited);
    }
  }
}

int main(){
  int v, e;
  cin >> v >> e;
  vector<vector<int>> adj_mat;
  vector<int> visited(v, false);

  for (int i = 0; i < v; ++i){
    vector<int> row(v, 0);
    adj_mat.push_back(row);
  }
  
  adj_mat[0][1] = 1;
  adj_mat[0][2] = 1;
  adj_mat[0][3] = 1;
  adj_mat[1][0] = 1;
  adj_mat[1][2] = 1;
  adj_mat[2][0] = 1;
  adj_mat[2][1] = 1;
  adj_mat[2][4] = 1;
  adj_mat[3][0] = 1;
  adj_mat[4][2] = 1;

  dfs(adj_mat, 0, visited);

  return 0;
}
