#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e6+10;
void solve(){
    LL n;
    cin>>n;
    map<string,LL> mp;
    auto check=[&](string s1,string s2)->LL{
        LL n=s1.size();
        LL m=s2.size();
        LL tag=1;
        for(int i=0;i<n&&i<m;i++){
            if(s1[i]!=s2[i]){
                tag=0;
            }
        }
        return tag;
    };
    for(int i=1;i<=n;i++){
        LL op;
        cin>>op;
        string s;
        cin>>s;          
        if(op==1){
            mp[s]++;   
            cout<<mp[s]<<'\n';
        }else if(op==2){ 
            auto it=mp.lower_bound(s);  
            if(it==mp.end()){
                cout<<"NO"<<'\n';
                continue;
            }
            LL ans=check(s,it->first);
            if(ans){
                cout<<"YES"<<'\n';
            }else{
                cout<<"NO"<<'\n';
            }
        }else{
            mp.erase(s);
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