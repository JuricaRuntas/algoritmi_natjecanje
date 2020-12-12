#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> adj_mat, int start){
  vector<int> visited(adj_mat.size(), false);
  queue<int> q;
  q.push(start);
  visited[start] = true;
  while (!q.empty()){
    int vertex = q.front();
    q.pop();
    cout << vertex << " ";
    for (int i = 0; i < adj_mat.size(); i++){
      if (!visited[i] && adj_mat[vertex][i]){
        visited[i] = true;
        q.push(i);
      }
    }
  }
}

int main(){
  int v, e;
  cin >> v >> e;

  // redovi predstavljaju koji node je povezan
  // stupci predstavlja s cim je neki node povezan
  vector<vector<int>> adj_mat;
  
  // v * v matrica popunjena s nulama
  for (int i = 0; i < v; ++i){
    vector<int> row(v, 0);
    adj_mat.push_back(row);
  }
   
  // primjer za v = 5
  adj_mat[0][1] = 1;
  adj_mat[0][4] = 1;
  adj_mat[1][0] = 1;
  adj_mat[1][2] = 1;
  adj_mat[1][3] = 1;
  adj_mat[1][4] = 1;
  adj_mat[2][1] = 1;
  adj_mat[2][3] = 1;
  adj_mat[3][1] = 1;
  adj_mat[3][2] = 1;
  adj_mat[3][4] = 1;
  adj_mat[4][0] = 1;
  adj_mat[4][1] = 1;
  adj_mat[4][3] = 1;
 
  bfs(adj_mat, 0);

  return 0;
}
