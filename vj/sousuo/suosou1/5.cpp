#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
const int N=10005;
#define LL long long
LL n,k;
bool vis[N];
string ans;
bool dfs(LL x,string s){
    if(x==0){
        ans=s;
        return true;
    }    
    if(s.size()>=100){
        return false;
    }

    vis[x]=true;
    for(int i=0;i<=1;i++){
        LL y=(x*10+i)%n;
        if(vis[y]){
            continue;
        }
        char c;
        if(i==0){
            c='0';
        }else{
            c='1';
        }
        if(dfs(y,s+c)){
            return true;
        }
    }
    return false;
}
void solve(){
    while(1){
        cin>>n;
        if(n==0){
            return;
        }
        ans.clear();
        memset(vis,false,sizeof(vis));
        string s="1";
        dfs(1%n,s);
        cout<<ans<<'\n';        
    }
}
int main(){
    solve();
    return 0;
}