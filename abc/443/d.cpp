#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
using LL=long long;
#define mp make_pair
LL a[N];
LL d[N];
LL b[N];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        
    }
    for(int i=1;i<=n-1;i++){
        if(a[i+1]<=a[i]){
            d[i]=1;
        }
    }
    b[1]=a[1];
    LL s=0;
    int tag=0;
    for(int i=1;i<=n;i++){
        cout<<d[i]<<' ';
    }
    cout<<'\n';
    for(int i=n;i>=1;i--){
        if(d[i-1]==1&&d[i]==0){
            tag=1;
            b[i]=a[i];
            continue;
        }
        if(d[i]==1&&tag){
            b[i]=min(b[i+1]+1,a[i]);
            //printf("{%d %lld}",i,b[i]);
        }else{
            tag=0;
        }
    }
    tag=0;
    for(int i=1;i<=n;i++){
        if(d[i]==0){
            tag=1;
        }
        if(d[i]==0&&tag){
            b[i+1]=min(b[i]+1,a[i+1]);
        }else{
            tag=0;
        }
    }    
    LL ans=0;
    
    for(int i=1;i<=n;i++){
        ans+=a[i]-b[i];
    }
    cout<<ans<<'\n';
    // for(int i=1;i<=n;i++){
    //     cout<<b[i]<<' ';
    // }
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}