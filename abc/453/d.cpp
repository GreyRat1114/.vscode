#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL sx,sy,gx,gy;
LL dx[]={-1,0,0,1};
LL dy[]={0,-1,1,0};
char inv[]={'U','L','R','D'};

LL h,w;
vector<vector<vector<int>>> vis;
vector<vector<char>> a;
struct node{
    LL x,y;
    LL k;
    LL cnt;
};
vector<vector<vector<node>>> lst;
LL bfs(){
    queue<node> q;
    q.push({sx,sy,-1,0});
    vis[sx][sy][0]=1;
    vis[sx][sy][1]=1;
    vis[sx][sy][2]=1;
    vis[sx][sy][3]=1;
    while(!q.empty()){
        LL x=q.front().x;
        LL y=q.front().y;
        LL k=q.front().k;
        LL cnt=q.front().cnt;
        //printf("{%lld,%lld,%lld,%lld}",x,y,k,cnt);
        q.pop();
        if(a[x][y]=='G'){
            //printf("{%lld}",k);
            return k;
        }
        for(int i=0;i<4;i++){
            LL x1=x+dx[i];
            LL y1=y+dy[i];
            if(x1<1||x1>h||y1<1||y1>w)continue;
            if(vis[x1][y1][i])continue;
            if(a[x1][y1]=='#')continue;
            if(a[x][y]=='o'&&i!=k){
                continue;
            }
            if(a[x][y]=='x'&&i==k){
                continue;
            }            
            //printf("{%lld,%lld,%lld,%lld}",x1,y1,pre,cnt);
            q.push({x1,y1,i,cnt+1});
            lst[x1][y1][i]={x,y,k};
            vis[x1][y1][i]=1;
        }
    }
    return -1;                                  
}
void solve(){
    cin>>h>>w;
    vis.assign(h+1,vector<vector<int>>(w+1,vector<int>(4,0)));
    a.assign(h+1,vector<char>(w+1));
    lst.assign(h+1,vector<vector<node>>(w+1,vector<node>(4)));
    for(int i=1;i<=h;i++){
        string s;
        cin>>s;
        for(int j=1;j<=w;j++){
            a[i][j]=s[j-1];
            if(a[i][j]=='S'){
                sx=i;
                sy=j;
            }
            if(a[i][j]=='G'){
                gx=i;
                gy=j;
            }
        }
    }
    LL x=gx,y=gy;
    LL k=bfs();
    if(k==-1){
        cout<<"No"<<'\n';
        return;
    }
    cout<<"Yes"<<'\n';
    vector<char> op;
    while(1){
        //printf("{%lld,%lld,%lld}",x,y,k);
        node nd=lst[x][y][k];
        op.push_back(inv[k]);
        x=nd.x;
        y=nd.y;
        k=nd.k;
        if(k==-1)break;
        
    }
    for(int i=op.size()-1;i>=0;i--){
        cout<<op[i];
    }
    cout<<'\n';

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