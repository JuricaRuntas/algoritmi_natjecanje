#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
vector<vector<int>> visited;

int solve(vector<vector<int>> ploca, int r, int s, int x, int y){
  vector<int> pomicanja_po_x = {-1, -1, -2, -2, 1, 1, 2, 2};
  vector<int> pomicanja_po_y = {-2, 2, -1, 1, -2, 2, -1, 1};
  int suma = ploca[x][y];
  deque<pair<int,int>> q;
  q.push_back({x, y});
  while (!q.empty()){
    pair<int,int> curr = q.front();
    q.pop_front();
    if (visited[curr.first][curr.second] == 1) continue;
    visited[curr.first][curr.second] = 1;
    for (int i = 0; i < 8; ++i){
      int novi_x = curr.first+pomicanja_po_x[i];
      int novi_y = curr.second+pomicanja_po_y[i];
      if (novi_x < 0 || novi_y < 0 || novi_x >= r || novi_y >= s) continue;
      if (visited[novi_x][novi_y] != 1 && find(q.begin(), q.end(), make_pair(novi_x, novi_y)) == q.end()){
        q.push_back({novi_x, novi_y});
        suma += ploca[novi_x][novi_y];
      }
    }
  }
  return suma;
}

int main(){
  int r,s;
  cin >> r >> s;
  vector<vector<int>> ploca(r, vector<int>(s));
  visited.resize(r);
  for (int i = 0; i < r; ++i) visited[i].resize(s, 0);
  for (int i = 0; i < r; ++i){
    for (int j = 0; j < s; ++j){
      cin >> ploca[i][j];
      if (ploca[i][j] == 0) visited[i][j] = 1;
    }
  }
  int max_rezultat = 0;
  for (int i = 0; i < r; ++i){
    for (int j = 0; j < s; ++j){
      if (visited[i][j] != 1){
        max_rezultat = max(max_rezultat, solve(ploca, r, s, i, j));
      }
    }
  }
  cout << max_rezultat << " ";
  return 0;
}
