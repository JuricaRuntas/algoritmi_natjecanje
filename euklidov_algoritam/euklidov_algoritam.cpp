#include <iostream>
using namespace std;

int gcd(int a, int b){
  while (b != 0){
    a = b;
    b = a % b;
  }
  return a;
}

int main(){
  int a,b;
  cin >> a >> b;
  cout << gcd(a,b) << "\n";
  return 0;
}
