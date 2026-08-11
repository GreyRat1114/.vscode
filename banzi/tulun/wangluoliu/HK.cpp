#include<bits/stdc++.h>
using namespace std;
struct HK{
    int n,m;
    vector<vector<int>> e;
    vector<int> l,r,d,cur;

    void init(int _n,int _m){
        n=_n;m=_m;
        e.assign(n+1,{});
        l.assign(n+1,0);
        r.assign(m+1,0);
        d.resize(n+1);
        cur.resize(n+1);
    }

    void add(int u,int v){
        e[u].push_back(v);
    }

    bool bfs(){
        queue<int> q;
        bool f=0;
        for(int i=1;i<=n;i++){
            if(!l[i])d[i]=0,q.push(i);
            else d[i]=-1;
        }
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int v:e[u]){
                int x=r[v];
                if(!x)f=1;
                else if(d[x]==-1)
                    d[x]=d[u]+1,q.push(x);
            }
        }
        return f;
    }

    bool dfs(int u){
        for(int &i=cur[u];i<e[u].size();i++){
            int v=e[u][i],x=r[v];
            if(!x||(d[x]==d[u]+1&&dfs(x))){
                l[u]=v;r[v]=u;
                return 1;
            }
        }
        d[u]=-1;
        return 0;
    }

    int work(){
        int ans=0;
        while(bfs()){
            fill(cur.begin(),cur.end(),0);
            for(int i=1;i<=n;i++)
                if(!l[i]&&dfs(i))ans++;
        }
        return ans;
    }
};