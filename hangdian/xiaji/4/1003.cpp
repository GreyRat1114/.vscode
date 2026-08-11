#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
using i128=__int128_t;
void solve(){
    LL n,q;
    cin>>n>>q;
    vector<set<LL>> st(3);
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        st[a[i]].insert(i);
    }
    for(int i=1;i<=q;i++){
        LL op;
        cin>>op;
        if(op==1){
            LL p,x;
            cin>>p>>x;
            st[a[p]].erase(p);
            a[p]=x;
            st[x].insert(p);
        }else{
            LL l,r;
            cin>>l>>r;
            LL maxn=0;
            auto it2=st[2].lower_bound(l);
            if(it2==st[2].end()||(*it2)>r){
                auto it1=st[1].lower_bound(l);
                if(it1==st[1].end()||(*it1>r)){
                    maxn=0;
                }else{
                    auto it0=st[0].lower_bound(*it1);
                    if(it0==st[0].end()||(*it0>r)){
                        maxn=0;
                    }else{
                        maxn=1;
                    }
                }                
            }else{
                auto it1=st[1].lower_bound(*it2);
                if(it1==st[1].end()||(*it1>r)){
                    auto it0=st[0].lower_bound(*it2);
                    if(it0==st[0].end()||(*it0>r)){
                        maxn=0;
                    }else{
                        maxn=1;
                    }
                }else{
                    auto it0=st[0].lower_bound(*it1);
                    if(it0==st[0].end()||(*it0>r)){
                        maxn=1;
                    }else{
                        maxn=2;
                    }                    
                }
            }
            auto it3=st[1].lower_bound(l);
            if(it3!=st[1].end()&&(*it3<=r)){
                auto it4=st[0].lower_bound(*it3);
                if(it4!=st[0].end()&&(*it4<=r)){
                    maxn=max(maxn,1ll);
                }
            }
            cout<<maxn<<'\n';
        }
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