#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1),b(n+1);
    map<LL,map<LL,LL>> mp;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        mp[-a[i]][-b[i]]++;
    }
    LL premax=0;
    vector<LL> ans;
    for(auto x:mp){
        LL rk=-x.first;
        LL siz=mp.size();
        LL s=0;
        LL maxn=0;
        LL p=0;
        for(auto y:x.second){
            LL need=-y.first;
            LL cnt=y.second;
            s+=cnt;
            if(max(0ll,premax-need)<s){
                maxn=max(maxn,premax+s-max(0ll,premax-need));
                
            }
        }
        premax=max(premax,maxn);
    }
    cout<<premax<<'\n';
}
int main(){
    LL t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}