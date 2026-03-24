#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=3e5+5;
#define m make_pair
const LL mod=1e9+7;


int check(LL a1,LL b1,LL c1,LL a2,LL b2,LL c2){
    if(a1>a2){
        return 0;
    }
    if(a1==a2){
        return (b1==b2)&c1<c2;
    }
    LL pt1=(b1-b2)*(b1-b2)-4*(a1-a2)*(c1-c2);
    return pt1<0;
}
void bfs(vector<vector<int>> &e,vector<int> &d,vector<LL> &dp,int n){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(d[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:e[u]){
            d[v]--;
            dp[v]=max(dp[v],dp[u]+1);
            if(d[v]==0){
                q.push(v);
            }
        

        }
    }
}
void solve(){

    int n;
    cin>>n;
    vector<vector<int>> e1(n+1),e2(n+1);
    vector<int> d1(n+1),d2(n+1);    
    vector<LL> a(n+1),b(n+1),c(n+1);
    vector<LL> dp1(n+1,0),dp2(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!check(a[i],b[i],c[i],a[j],b[j],c[j])){
                continue;
            }
            e1[i].push_back(j);
            e2[j].push_back(i);
            d1[j]++;
            d2[i]++;
        }
    }
    bfs(e1,d1,dp1,n);
    bfs(e2,d2,dp2,n);
    for(int i=1;i<=n;i++){
        cout<<dp1[i]+dp2[i]+1<<' ';
    }
    cout<<'\n';

}
int main(){
    int t=1;
    cin>>t;
    while(t--){

        solve();
    }
    return 0;
}