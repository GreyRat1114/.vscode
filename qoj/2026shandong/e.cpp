#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int num1[2][3]={{0,4,2},{3,1,5}};
int num2[3][2]={{3,0},{1,4},{5,2}};
int num3[3][3]={{0,6,3},{5,2,8},{1,7,4}};
void solve(){
    LL n,m;
    cin>>n>>m;
    if((n==1&&m<=4)||(m==1&n<=4)){
        cout<<"No"<<'\n';
        return;
    }
    if(n==2&&m==2){
        cout<<"No"<<'\n';
        return;
    }    
    cout<<"Yes"<<'\n';
    if(n==2&&m==3){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<num1[i][j]<<' ';
            }
            cout<<'\n';
        }
        return;
    }else if(n==3&&m==2){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<num2[i][j]<<' ';
            }
            cout<<'\n';
        }
        return;
    }
    if(n==3&&m==3){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<num3[i][j]<<' ';
            }
            cout<<'\n';
        }      
        return;  
    }
    vector<vector<LL>> ans(n+1,vector<LL>(m+1,0));
    if(n<m){
        LL tot=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j+=2){
                ans[i][j]=tot;
                tot++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=2;j<=m;j+=2){
                ans[i][j]=tot;
                tot++;
            }
        }        
    }else{
        LL tot=0;
        for(int j=1;j<=m;j++){
            for(int i=1;i<=n;i+=2){
                ans[i][j]=tot;
                tot++;
            }
        }
        for(int j=1;j<=m;j++){
            for(int i=2;i<=n;i+=2){
                ans[i][j]=tot;
                tot++;
            }
        }           
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }       
}
int main(){
    LL t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}