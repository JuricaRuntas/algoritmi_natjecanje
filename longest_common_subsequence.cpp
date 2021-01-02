#include <iostream>
#include <string>
#include <vector>
using namespace std;

void lcs(string ss1, string ss2){
  vector<vector<int>> dp(ss1.length()+1, vector<int>(ss2.length()+2));
  for (int i = 0; i <= ss2.length(); ++i){
    for (int j = 0; j <= ss1.length(); ++j){
      if (i == 0 || j == 0) dp[i][j] = 0;
      else if (ss2[i-1] == ss1[j-1]){
        dp[i][j] = dp[i-1][j-1]+1;
      }
      else{
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  cout << dp[ss1.length()][ss2.length()];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string ss1, ss2;
  cin >> ss1 >> ss2;
  lcs(ss1, ss2);
  return 0;
}
