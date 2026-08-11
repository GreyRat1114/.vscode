#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    LL c0=0,c1=0,c2=0;
    vector<vector<LL>> a(3,vector<LL>(n+1,0));
    for(int i=1;i<=2;i++){
        for(int j=1;j<=n;j++){
            LL x;
            cin>>x;
            x=x%3;
            if(x==0)c0++;
            if(x==1)c1++;
            if(x==2)c2++;
            a[i][j]=x;
        }
    }
    if(n==1){
        if((a[1][1]+a[2][1])%3==0){
            cout<<"NO"<<'\n';
        }else{
            cout<<"YES"<<'\n';          
        }
        return; 
    }
    if(c0>n){
        cout<<"NO"<<'\n';
        return;
    }
    if(c1==0||c2==0){
        cout<<"YES"<<'\n';
        return;        
    }     
    if(c0<2){
        cout<<"NO"<<'\n';
        return;
    }       
    if(c0==2&&(c1%2==0)){
        cout<<"NO"<<'\n';
        return;
    }
    cout<<"YES"<<'\n';
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