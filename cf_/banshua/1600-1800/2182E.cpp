#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
#define mp make_pair
void solve(){
    LL n,m,k;
    cin>>n>>m>>k;
    vector<LL> a(m+1);
    vector<array<LL,3>> b(n+1);
    vector<bool> vis(n+1,false);
    //set<pair<LL,LL>> tr;

    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());

    // for(int i=1;i<=m;i++){
    //     printf("%lld",a[i]);
    // }    
    LL xx,yy,zz;
    LL s=0;
    for(int i=1;i<=n;i++){
        cin>>xx>>yy>>zz;
        s+=yy;
        b[i][0]=xx;
        b[i][1]=zz-yy;
        b[i][2]=i;
    }
    k-=s;
    priority_queue<pair<LL,LL>> tr;
    sort(b.begin(),b.end());
    // for(int i=1;i<=n;i++){
    //     printf("{%lld,%lld,%lld}",b[i][0],b[i][1],b[i][2]);
    // }
    for(int i=1,j=1;i<=m;i++){
        while(b[j][0]<=a[i]&&j<=n){
            tr.push(mp(b[j][1],j));
            //printf("{%d,%d,%lld}\n",i,j,b[j][1]);
            j++;
        }
        if(!tr.empty()){
            LL x=tr.top().first;
            LL num=tr.top().second;
            tr.pop();      
            vis[num]=true;
            //printf("{%lld}",num);
        }
    }
    priority_queue<LL,vector<LL>,greater<LL>> q;
    LL ans=0;
    for(int i=1;i<=n;i++){
        if(vis[i]){
            ans++;
            continue;
        }
        q.push(b[i][1]);
    }
    //printf("<%lld>",ans);
    while(!q.empty()){
        LL x=q.top();
        q.pop();
        if(k>=x){
            k-=x;
            ans++;
        }else{
            break;
        }
    }
    cout<<ans<<'\n';

}
int main(){
    // std::ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();

    }
    return 0;
}