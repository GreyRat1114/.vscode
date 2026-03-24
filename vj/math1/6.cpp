#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=1e6+5;
int cnt[N];
int a[N];
void solve(){
    
    int n,m;
    cin>>n;
    LL x;
    LL ans=0;
    for(int i=1;i<=n;i++){
        cin>>x;
        a[i]=x;
        if(cnt[x]==0){
            cnt[x]=x;
            ans+=x;
        }else{
            cnt[x]--;
            ans--;
        }
    }
    for(int i=1;i<=n;i++){
        cnt[a[i]]=0;
    }
    cout<<ans+n<<'\n';
}
int main(){
    memset(cnt,0,sizeof(cnt));
    int t;
    cin>>t;    
    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}