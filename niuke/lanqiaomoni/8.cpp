#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const int N=3e5+5;
const int M=3e5+5;
int n,m;
struct Node{
	int v;
	int w;
	int next;
};
Node a[2*M];
int last[N];
int tot;
int dist[N];
bool vis[N];
int s,t;
void add(int u,int v,int w)
{
	tot++;
	a[tot].v=v;
	a[tot].w=w;
	a[tot].next=last[u];
	last[u]=tot;
}
void dijkstra()
{
    priority_queue<pair<int,int>> q;
	for(int i=1;i<=n;i++)
	{
		dist[i] = 1e9+5;
	}
	memset(vis,false,sizeof(vis));
	dist[s]=0;
	vis[s]=true;
	q.push(make_pair(0,s));	
	int u,v,w;
	while(!q.empty())
	{
		u=q.top().second;
		q.pop();
		vis[u]=false;
        //printf("{%lld,%lld,%lld,%lld}",s,t,u,dist[u]);
        if(u==t){
            return;
        }
		for(int i=last[u];i>0;i=a[i].next)
		{
			v=a[i].v;
			w=a[i].w;
			if(dist[u]+w<dist[v])
			{

				dist[v]=dist[u]+w;
				if(vis[v]==false)
				{
					q.push(make_pair(-dist[v],v));
					vis[v]=true;
				}
				
			}
		}
	}
}
void solve(){
    tot=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        last[i]=0;
    }    
    LL x,y,c;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>c;
        add(x,y,c);
        add(y,x,c);
    }
    LL k;
    cin>>k;
    vector<LL> a(k+1);
    for(int i=1;i<=k;i++){
        cin>>a[i];
    }
    LL ans=1e9;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            if(i==j){
                continue;
            }
            s=a[i];
            t=a[j];
            dijkstra();
            ans=min(ans,dist[t]*1ll);
        }
    }
    cout<<ans<<'\n';

}
int main(){
    int tt=1;
    cin>>tt;
    while(tt--){
        solve();
    }
    return 0;
}