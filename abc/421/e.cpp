#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ld=long double;
map<pair<vector<LL>,LL>,ld> mp;
vector<LL> a(10);
ld dfs(vector<LL> q,LL s){
    if(mp.count({q,s}))return mp[{q,s}];
    if(!s){
        ld maxn=0;
        for(int i=1;i<=6;i++){
            LL val=a[i];
            ld sum=0;
            for(int j=0;j<q.size();j++){
                if(q[j]==val){
                    sum+=val;
                }
            }
            maxn=max(maxn,sum);
        }
        mp[{q,0}]=maxn;
        return maxn;
    }
    LL pow=1;
    LL n=5-q.size();
    for(int i=1;i<=n;i++){
        pow*=6;
    }
    ld sum=0;
    for(int i=0;i<pow;i++){
        vector<LL> add;
        LL x=i;
        ld maxn=0;
        for(int j=0;j<n;j++){
            add.push_back(a[x%6+1]);
            x=x/6;
        }
        for(int j=0;j<(1<<n);j++){
            vector<LL> w=q;
            for(int k=0;k<n;k++){
                if(j&(1<<k))w.push_back(add[k]);                
            }
            maxn=max(maxn,dfs(w,s-1));
        }
        sum+=maxn;
    }
    mp[{q,s}]=sum/pow;
    return sum/pow;
}
void solve(){
    for(int i=1;i<=6;i++){
        cin>>a[i];
    }
    ld ans=dfs({},3);
    cout<<fixed<<setprecision(10)<<ans<<'\n';
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}