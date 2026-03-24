#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
using LL=long long;
const LL mod=998244353;


LL a[N];
LL b[N];
LL s[N];
void solve(){
    int n,m;
    cin>>n>>m;
    LL x;
    for(int i=1;i<=n;i++){
        cin>>x;
        a[i]=x;
    }
    for(int i=1;i<=m;i++){
        cin>>x;
        b[i]=x;
    }
    sort(b+1,b+1+m);
    s[0]=0;
    for(int i=1;i<=m;i++){
        s[i]=s[i-1]+b[i];
    }
    LL ans=0;
    b[m+1]=1e9;
    for(int i=1;i<=n;i++){
        x=a[i];
        int lt=1;
        int rt=m;
        while(lt<=rt){
            int mid=(lt+rt)/2;
            if(b[mid]<=x){
                lt=mid+1;
            }
            else{
                rt=mid-1;
            }
            // printf("{%d %d %d}",lt,rt,mid,b[mid]);
        }
        int p=lt-1;
        // printf("{%d,%d}",i,p);
        LL y=(x*p)-(s[p]-s[0]);
        LL z=(s[m]-s[p])-(x*(m-p));
        LL q=y+z;
        ans=(ans+q+mod)%mod;
    }
    cout<<ans<<'\n';

}
int main(){
    int t=1;

    while(t--){
        solve();
    }
    
    return 0;
}
