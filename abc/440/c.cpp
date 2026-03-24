#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
LL c[N];
LL sum[N];
void solve(){
    
    LL n,w;
    cin>>n>>w;
    for(int i=0;i<=n+5;i++){
        sum[i]=0;
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
        sum[i]=sum[i-1]+c[i];
    }
    LL minn=1e18;
    LL ans;
    LL ling=0;
    for(int i=0;i<2*w;i++){
        LL s=0;
        LL k=2*w-i;

        for(int j=0;i+j*2*w<=n;j++){
            
            LL p=i+j*2*w;
            LL d=sum[min(p+w-1,n)]-sum[max(p-1,ling)];
            
            //printf("{%d %d %d %lld}\n",i,j,p,d);
            s+=d;
            // if(p+1<=n){
            //     s+=c[p+1];
            // }
        }
        for(int j=1;i-j*2*w+w-1>=1;j++){
            LL p=i-j*2*w;
            LL d=sum[p+w-1]-sum[max(p-1,ling)];
            //printf("{%d %d %d %lld}\n",i,j,p,d);
            s+=d;
        }
        minn=min(minn,s);
    }
    cout<<minn<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}