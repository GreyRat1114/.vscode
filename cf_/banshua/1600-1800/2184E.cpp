#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+15;
#define mp make_pair
//pragma GCC optimize(3)
LL fa[N];
LL cnt[N];
void init(int n){
    for(int i=0;i<=n+3;i++){
        fa[i]=i;
        cnt[i]=1;
    }
    //printf("&");
}
LL find(LL x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(LL x,LL y){
    LL fx=find(x);
    LL fy=find(y);
    if(fx!=fy){
        fa[fy]=fx;
        cnt[fx]+=cnt[fy];        
    }
}
void solve(){
    int n;
    cin>>n;
    vector<LL> a(n+1);
    vector<LL> ans(n+1,0);
    init(n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    priority_queue<pair<LL,LL>> q;

    for(int i=1;i<=n-1;i++){
        LL d=abs(a[i+1]-a[i]);
        q.push(mp(d,i));
    }
    while(!q.empty()){
        LL x=q.top().first;
        LL y=q.top().second;
        //printf("{%lld,%lld}\n",x,y);
        q.pop();
        LL p1=y;
        LL p2=y+1;
        LL pt1=cnt[find(p1)];
        LL pt2=cnt[find(p2)];
        merge(p1,p2);
        LL pt3=pt1*pt2;
        ans[x]+=pt3;
    }
    LL s=0;
    for(int i=1;i<=n;i++){
        s+=ans[i];
        //printf("{%lld}",ans[i]);
    }
    for(int i=1;i<=n-1;i++){
        cout<<s<<' ';
        s-=ans[i];
    }
    cout<<'\n';
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}