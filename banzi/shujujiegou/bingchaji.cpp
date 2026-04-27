#include<bits/stdc++.h>
using namespace std;
using LL=long long;
struct DSU{
    vector<LL> fa;
    LL cnt;//连通块数量
    void init(LL n){
        fa.resize(n+1); 
        cnt=n;  
        for(int i=0;i<=n;i++){
            fa[i]=i;
        }
    }
    LL find(LL x){
        if(fa[x]==x)return x;
        return fa[x]=find(fa[x]);
    }
    void merge(LL x,LL y){
        LL fx=find(x);
        LL fy=find(y);
        if(fx!=fy){
            fa[fx]=fy;
            cnt--;
        }
    }
};