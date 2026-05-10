#include<bits/stdc++.h>
using namespace std;

void print(int n){
    for(int i=1;i<=n;i++){
        cout << "DR";
    }
    cout << "UL";
    for(int i=1;i<=n;i++){
        cout << "DL";
    }
    cout << "UR";
}

void solve(){
    int n;
    cin >> n;
    int num = 0;
    int p = 4*n+4;
    int k = 30*n/p;
    cout << k*p << "\n";
    for(int i=1;i<=k;i++){
        print(n);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}