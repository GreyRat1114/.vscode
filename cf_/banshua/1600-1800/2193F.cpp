#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
void solve(){
    
    LL n,q;
    cin>>n>>q;
    LL m=1<<n;
    vector<vector<LL>> a(20,vector<LL>(m+1,0));
    vector<LL> b(q+1,0),c(q+1,0);
    
    for(int i=1;i<=m;i++){
        cin>>a[0][i];
    }
    for(int i=1;i<=q;i++){
        cin>>b[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=(1<<(n-i));j++){
            a[i][j]=a[i-1][2*j-1]^a[i-1][2*j];
            //cout<<a[i][j]<<' ';
        }
        //cout<<'\n';
    }

    for(int i=1;i<=q;i++){
        LL p=b[i];
        LL x=c[i];
        LL s=0;
        for(int j=0;j<=n-1;j++){
            if(p%2==1){
                if(a[j][p+1]>x){
                    s+=(1<<j);
                }
                x=x^a[j][p+1];
            }else{
                if(a[j][p-1]>=x){
                    s+=(1<<j);
                }        
                x=x^a[j][p-1];
            }
            p=(p-1)/2+1;
        }
        cout<<s<<'\n';
        //printf("{%lld}",s);
    }
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}