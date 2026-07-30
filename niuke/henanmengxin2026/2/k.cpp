#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e6+10;
vector<vector<LL>> a;    
LL x;
LL getmid(LL dx,LL dy){
    vector<LL> q;
    for(int i=1+dx;i<=x+dx;i++){
        for(int j=1+dy;j<=x+dy;j++){
            q.push_back(a[i][j]);
        }
    }
    LL siz=q.size();
    sort(q.begin(),q.end());
    return q[(siz-1)/2];
}
void solve(){
    LL n,m;
    cin>>n>>m;
    a.assign(n+1,vector<LL>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    LL k;
    cin>>x>>k;
    vector<LL> q;
    for(int i=0;i+x<=n;i++){
        for(int j=0;j+x<=m;j++){
            q.push_back(getmid(i,j));
        }
    }    
    LL g=q[0];
    for(auto x:q){
        g=__gcd(g,x);
    }
    if(k%g==0){
        cout<<"YES"<<'\n';
    }else{
        cout<<"NO"<<'\n';
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