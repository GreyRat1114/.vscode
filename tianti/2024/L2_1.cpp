#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,m;
    cin>>n>>m;
    vector<set<int>> a(n+1);
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x;
            cin>>x;

            a[i].insert(x);
        }
    }
    int q;
    cin>>q;
    int x,y;
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        int tot=0;
        for(int i=1;i<=n;i++){
            if(a[i].count(x)&&a[i].count(y)){
                tot++;
            }
        }
        cout<<tot<<'\n';
    }
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}