#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    int n;
    cin >> n;
    int odd = -1;
    int num = 0;
    int ji = -1;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        if(x % 2 == 0){
            odd = max(odd,x);
        }
        else{
            num++;
            ji = max(ji,x);
        }
    }

    if(num == 0){
        cout << odd / 2 << "\n";
    }
    else{
        if(num % 2 == 1){
            if(odd != -1){
                ji = max(ji,odd-1);
            }
            cout << (ji + 1) / 2 << "\n";
        }
        else{
            int ans = max(odd,(ji-1));
            cout << ans / 2 << "\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}