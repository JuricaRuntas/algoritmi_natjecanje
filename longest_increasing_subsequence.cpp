#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> pp(n);
  for (auto &kk : pp) cin >> kk;
  
  // This runs in O(n²) time
  /*
  vector<int> dp(n, 1);
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < i; ++j){
      if (pp[j] < pp[i]) dp[i] = max(dp[i], dp[j]+1);
    }
  }

  int ans = *max_element(dp.begin(), dp.end());
  cout << ans << " ";
  */

  // This runs in O(n*logn) or O(logn) time not sure
  const int INF = 1e9;
  vector<int> dp(n+1, INF);
  dp[0] = -INF;

  for (int i = 0; i < pp.size(); ++i){
    int j = upper_bound(dp.begin(), dp.end(), pp[i]) - dp.begin();
    if (dp[j-1] < pp[i] && pp[i] < dp[j]) dp[j] = pp[i];
  }

  int ans = 0;
  for (int i = 0; i <= n; ++i){
    if (dp[i] < INF) ans = i;
  }
  cout << ans << " ";

  return 0;
}
