#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e3+5;
const LL mod=1e9+7;
bool cmp(pair<LL,LL> &x,pair<LL,LL> &y){
    return x.first>y.first;
}
void solve(){
    LL n,m,q;
    cin>>n>>m>>q;
    LL tot=n+m;
    vector<pair<LL,LL>> a(n+1),b(m+1);
    vector<LL> sa(n+1,0),sb(m+1,0);
    vector<pair<LL,LL>> c(n+m+1);
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second=0;
        c[i]=a[i];
    }
    sort(a.begin()+1,a.end(),cmp);
    for(int i=1;i<=n;i++){
        sa[i]=sa[i-1]+a[i].first;
    }
    for(int i=1;i<=m;i++){
        cin>>b[i].first;
        b[i].second=1;
        c[i+n]=b[i];
    }
    sort(b.begin()+1,b.end(),cmp);
    for(int i=1;i<=m;i++){
        sb[i]=sb[i-1]+b[i].first;
    }
    sort(c.begin()+1,c.end(),cmp);
    // for(int i=1;i<=tot;i++){
    //     printf("{%lld}",c[i].first);
    // }
    vector<pair<LL,LL>> op(tot+1);
    vector<vector<LL>> cnt(tot+1,vector<LL>(2,0));
    vector<LL> sum(tot+1,0);
    for(int i=1;i<=tot;i++){
        sum[i]=sum[i-1]+c[i].first;
        cnt[i][c[i].second]=cnt[i-1][c[i].second]+1;
        cnt[i][c[i].second^1]=cnt[i-1][c[i].second^1];
        //printf("{%lld,%lld}",cnt[i][c[i].second],cnt[i][c[i].second^1]);
    }

    LL x,y,z;
    for(int i=1;i<=q;i++){
        cin>>x>>y>>z;
        LL x1=cnt[z][0];
        LL y1=cnt[z][1];
        
        if(x>=x1&&y>=y1){
            cout<<sum[z]<<'\n';
        }else if(x<x1){
            LL d1=sa[x1]-sa[x];
            LL d2=sb[y1+(x1-x)]-sb[y1];
            cout<<sum[z]-d1+d2<<'\n';
        }else if(y<y1){
            LL d1=sb[y1]-sb[y];
            LL d2=sa[x1+(y1-y)]-sa[x1];
            cout<<sum[z]-d1+d2<<'\n';
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