#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void ispis_ploce(vector<int> &pozicije, int n){
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j){
      cout << (pozicije[i] == j ? " X " : " - ");
    }
    cout << "\n";
  }
  cout << "\n";
}

bool nema_napada(vector<int> &pozicije, int row, int col){
  for (int i = 0; i < pozicije.size(); ++i){
    if (i == row || pozicije[i] == col || abs(row-i) == abs(col-pozicije[i])) return false;
  }
  return true;
}

void razmjestaj_kraljica(int n){
  vector<int> pozicije;
  int col = 0, row = 0;
  while(true){
    while (col < n && !nema_napada(pozicije, row, col)) ++col;
    if (col < n){
      pozicije.push_back(col);
      if (row+1 >= n){
        ispis_ploce(pozicije, n);
        pozicije.pop_back();
        col = n;
      }
      else{
        col = 0;
        ++row;
      }
    }
    else{
      if (row == 0) return;
      col = ++pozicije.back();
      pozicije.pop_back();
      --row;
    }
  }
}

int main(){
  int n;
  //cin >> n;
  razmjestaj_kraljica(4);  
  return 0;
}
