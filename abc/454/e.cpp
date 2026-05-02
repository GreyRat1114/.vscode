#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
char dir[]={'D','R','U','L'};
vector<vector<LL>> vis;
LL px,py;
LL n,a,b;
vector<char> ans;
void dfs(LL x,LL y,LL d){
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        LL d1=(d+i)%4;
        LL x1=x+dx[d1];
        LL y1=y+dy[d1];
        if(x1<=(px-1)*2||x1>px*2||y1<1||y1>n)continue;
        if(vis[x1][y1]||x1==a&&y1==b)continue;
        ans.push_back(dir[d1]);
        //printf("{%lld,%lld,%c}",x,y,dir[i]);
        dfs(x1,y1,(d1+1)%4);
    }
}
void solve(){
    cin>>n>>a>>b;
    vis.assign(n+1,vector<LL>(n+1,0));
    if(n%2==1||n%2==0&&(a+b)%2==0){
        cout<<"No"<<'\n';
        return;
    }else{
        cout<<"Yes"<<'\n';
    }
    px=(a-1)/2+1;
    py=(b-1)/2+1;
    //printf("{%lld,%lld,}",px,py);
    ans.clear();
    for(int i=1;i<px;i++){
        for(int j=1;j<=n-1;j++){
            ans.push_back('R');
        }
        ans.push_back('D');
        for(int j=n-1;j>=1;j--){
            ans.push_back('L');
        }
        ans.push_back('D');
    }
    LL x=(px-1)*2+1;
    LL y=1;
    dfs(x,y,0);
    ans.push_back('D');
    for(int i=px+1;i*2<=n;i++){
        for(int j=n-1;j>=1;j--){
            ans.push_back('L');
        }
        ans.push_back('D');        
        for(int j=1;j<=n-1;j++){
            ans.push_back('R');
        }
        ans.push_back('D');
    }    
    LL tot=ans.size();
    for(int i=0;i<tot-1;i++){
        cout<<ans[i];
    }
    cout<<'\n';
    //vector<LL> vis(3,vector<>)
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