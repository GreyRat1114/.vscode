#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
using i128=__int128;
map<LL,map<LL,LL>> mpl,mpr;
map<pair<LL,LL>,LL> mp;
vector<LL> minr,maxl;
vector<LL> prer,prel;
void check(LL s,LL t){
    if(mp[{s,t}]){
        if(mp[{s,t}]>=2){
            cout<<"Yes"<<'\n';
        }else{
            if(prer[s]<t||prel[t]>s){
                //printf("{%}");
                cout<<"Yes"<<'\n';
            }else{
                cout<<"No"<<'\n';
            }
        }
    }else if(mpl.count(s)&&mpr.count(t)){
        //printf("{%lld,%lld}",s,t);
        auto it=mpl[s].upper_bound(t);
        // if(it==mpl[s].end()){

        // }
        if(it==mpl[s].begin()){
            cout<<"No"<<'\n';
            return;           
        }
        it--;
        LL rt=it->first;
        //printf("{%lld}",rt);
        it=mpr[t].lower_bound(s);
        if(it==mpr[t].end()){
            //printf("{$}");
            cout<<"No"<<'\n';
            return;                     
        }
        // it--;
        LL lt=it->first;   
        //printf("{%lld,%lld}",lt,rt);  
        if(rt<lt-1){
            cout<<"No"<<'\n';
            return;                    
        }
        cout<<"Yes"<<'\n';
    }else{
        cout<<"No"<<'\n';
    }
}
void solve(){
    LL n,m;
    cin>>n>>m;
    minr.assign(n+1,1e9);
    prer.assign(n+2,1e9);
    maxl.assign(n+1,0);
    prel.assign(n+2,0);
    for(int i=1;i<=m;i++){
        LL l,r;
        cin>>l>>r;
        mpl[l][r]++;
        mpr[r][l]++;
        mp[{l,r}]++;
        minr[l]=min(r,minr[l]);
        maxl[r]=max(l,maxl[r]);
    }
    for(int i=n;i>=1;i--){
        prer[i]=min(prer[i+1],minr[i]);
        //printf("{%lld}",pre[i]);
    }
    for(int i=1;i<=n;i++){
        prel[i]=max(prel[i-1],maxl[i]);
        //printf("{%lld}",prel[i]);
    }
    LL q;
    cin>>q;
    for(int i=1;i<=q;i++){
        LL s,t;
        cin>>s>>t;
        check(s,t);
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