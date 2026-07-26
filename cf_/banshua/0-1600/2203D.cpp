#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,m;
    cin>>n>>m;
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<LL> b(m+1);
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    vector<LL> cnt(n+m+1,0),c(n+m+1,0);
    for(int i=1;i<=n;i++){
        cnt[a[i]]++;
    }
    for(int i=1;i<=n+m;i++){
        for(int j=1;i*j<=n+m;j++){
            c[i*j]+=cnt[i];
        }
    }
    LL ac=0,bc=0,both=0;
    for(int i=1;i<=m;i++){
        if(c[b[i]]==n){
            ac++;
        }else if(c[b[i]]==0){
            bc++;
        }else{
            both++;
        }
    }
    LL ansa=ac+(both+1)/2;
    LL ansb=bc+both/2;
    if(ansa>ansb){
        cout<<"Alice"<<'\n';
    }else{
        cout<<"Bob"<<'\n';
    }
    
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}