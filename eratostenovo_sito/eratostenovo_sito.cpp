#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>
using namespace std;

void eratostenovo_sito(int n){
  assert (n > 1); // broj mora bit veci od 1
  bool prime[n+1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p*p<=n; ++p){
    if (prime[p] == true){
      // eliminiraj sve visekratnike trenutnog broja
      for (int i = p*p; i <= n; i+=p){
        prime[i] = false;
      }
    }
  }
  for (int p = 2; p <= n; ++p){
    if (prime[p]){
      cout << p << " ";
    }
  }
  cout << "\n";
}

int main(){
  int n;
  cin >> n;
  eratostenovo_sito(n);
  return 0;
}
