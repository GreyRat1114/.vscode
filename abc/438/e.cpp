#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
LL f[N][35];
LL g[N][35];
int a[N];

void solve(){
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i][0]=a[i];
        g[i][0]=i;
    }
    
    for(int i=1;i<=30;i++){
        for(int j=1;j<=n;j++){
            f[j][i]=f[f[j][i-1]][i-1];
            g[j][i]=g[f[j][i-1]][i-1]+g[j][i-1];
        }
    }
    int t,b;
    for(int i=1;i<=q;i++){
        cin>>t>>b;
        LL s=0;
        int p=b;
        for(int j=0;j<30;j++){
            if(t&(1<<j)){
                s+=g[p][j];
                p=f[p][j];
            }
        }
        cout<<s<<'\n';
    }
}
int main(){
    solve();
    return 0;
}