#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

void floyd_warshall(vector<vector<int>> &adj_mat){
  for (int k = 1; k < adj_mat.size(); ++k){
    for (int i = 1; i < adj_mat.size(); ++i){
      for (int j = 1; j < adj_mat.size(); ++j){
        adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k]+adj_mat[k][j]);
      }
    }
  }
}

int main(){
  int n = 5;
  vector<vector<int>> adj_mat(n+1, vector<int>(n+1, 0));
  
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
  
  for (int i = 1; i <= n; ++i){
    for (int j = 1; j <= n; ++j){
      if (i == j) adj_mat[i][j] = 0;
      // else if (adj[i][j]) dist[i][j] = adj_mat[i][j];
      else if (adj_mat[i][j] == 0) adj_mat[i][j] = INF;
    }
  }
  
  floyd_warshall(adj_mat);
  
  for (int i = 1; i < adj_mat.size(); ++i){
    for (int j = 1; j < adj_mat.size(); ++j){
      if (adj_mat[i][j] == INF) cout << "I" << " ";
      //else cout << adj_mat[i][j] << " ";
      cout << adj_mat[i][j] << " ";
    }
    cout << "\n";
  } 
  
  return 0;
}
