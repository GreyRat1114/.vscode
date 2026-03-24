#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve(){
  LL n,m;
  cin >> n >> m;
  if(n == 1){
    cout << m << "\n";
    return;
  }
  if(m == 1){
    cout << n << "\n";
    return;
  }
  if(n == 2){
    int r = m % 4;
    LL cur = 0;
    if(r == 1) cur = 2;
    else if(r >= 2) cur = 4;
    cout << m+cur << "\n";
    return;
  }
  if(m == 2){
    int r = n % 4;
    LL cur = 0;
    if(r == 1) cur = 2;
    else if(r >= 2) cur = 4;
    cout << n+cur << "\n";
    return;
  }
  LL cur = n*m;
  if(cur % 2 == 1){
    cout << cur/2LL+1LL << "\n";
  }
  else{
    cout << cur/2LL << "\n";
  }
}

int main(){

  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }
  return 0;
}