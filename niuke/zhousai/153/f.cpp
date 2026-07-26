#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,m,k;
    cin>>n>>m>>k;
    LL min1=(n/2)*(m/2);
    LL max1=n*m-min1;
    
    if(k<min1||k>max1){
        cout<<"No"<<'\n';
        return;
    }
    LL cut;
    if((n%2==1)&&(m%2==1)){
        LL c1=((n-1)/2+1)*(m/2);
        LL c2=((m-1)/2+1)*(n/2);
        cut=n*m-min(c1,c2);
    }

    if((n%2==1)&&(m%2==1)){
        if(k<=cut){
            vector<vector<LL>> vis(n+1,vector<LL>(m+1,0)),ans(n+1,vector<LL>(m+1,0));
            LL need=k-min1;
            for(int i=2;i<=n;i+=2){
                for(int j=2;j<=m;j+=2){
                    ans[i][j]=1;
                }   
            }            
            
        }else{

        }
    }else{

    }
    vector<vector<LL>> vis(n+1,vector<LL>(m+1,0)),ans(n+1,vector<LL>(m+1,0));
    LL need=k-min1;
    for(int i=2;i<=n;i+=2){
        for(int j=2;j<=m;j+=2){
            ans[i][j]=1;
        }   
    }


}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}