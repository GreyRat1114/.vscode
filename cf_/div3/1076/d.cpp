#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
LL a[N];
LL b[N];
LL s[N];
LL inv[N];
LL cnt[N];
LL s2[N];
int tot,n;
int check(LL x){
    int lt=1;
    int rt=n;
    while(lt<=rt){
        int mid=(lt+rt)/2;
        if(s2[mid]<=x){
            lt=mid+1;
        }else{
            rt=mid-1;
        }
    }
    return lt-1;
}
void solve(){
    cin>>n;
    map<int,int> tr;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        tr[a[i]]++;
    }
    s2[0]=0;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        s2[i]=s2[i-1]+b[i];
    }    

    tot=0;
    for(auto x:tr){
        tot++;
        inv[tot]=x.first;
        cnt[tot]=x.second;
    }
    s[0]=0;
    for(int i=1;i<=tot;i++){
        s[i]=s[i-1]+cnt[i];
    }
    // for(int i=1;i<=tot;i++){
    //     printf("{%lld}",s[i]);
    // }    
    LL maxn=0;
    for(int i=1;i<=tot;i++){
        
        LL x=inv[i];

        LL y=s[tot]-s[i-1];
        int p=check(y);
        //printf("{%d %lld %lld %d}\n",i,x,y,p);
        LL ans=x*p;
        maxn=max(maxn,ans);
    }
    cout<<maxn<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}