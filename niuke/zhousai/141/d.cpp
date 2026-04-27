#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
const LL N=1e5+5;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    map<LL,LL> mp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    for(auto p:mp){
        LL x=p.first;
        LL cnt=0;
        if(x==1){
            if(mp[1]>=2){
                cout<<"YES"<<'\n';
                return;
            }else{
                continue;
            }
        }
        LL y=x;
        while(x<=1e9){
            cnt++;
            //printf("{%lld,%lld}",x,cnt);
            if(mp.count(cnt)&&mp.count(x)){
                if(cnt==1){
                    if(mp[x]>=2){
                        cout<<"YES"<<'\n';
                        return;                    
                    }else{
                        x=x*x;
                        continue;
                    }
                }
                cout<<"YES"<<'\n';
                return;
            }
            x=x*y;
            
        }
    }
    cout<<"NO"<<'\n';
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}