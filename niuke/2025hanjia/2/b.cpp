#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
using LL=long long;
#define mp make_pair
const LL mod=998244353;
LL a[N];
LL cnt[N];
LL s[N];
void solve(){
    map<LL,int> tr;
    int n;
    cin>>n;
    for(int i=0;i<=n+2;i++){
        cnt[i]=0;
        s[i]=0;
    }    
    for(int i=1;i<=n;i++){
        cin>>a[i];
        tr[a[i]]++;
        tr[a[i]]=tr[a[i]]%2;
    }
    int tot=0;
    map<LL,int>inv;
    for(auto x:tr){
        tot++;
        cnt[tot]=x.second;
        inv[x.first]=tot;
    }
    // for(int i=1;i<=tot;i++){
    //     printf("{%lld}",cnt[i]);
    // }
    s[0]=0;
    for(int i=1;i<=tot;i++){
        s[i]=s[i-1]+cnt[i];
    }
    for(int i=1;i<=n;i++){
        // if(tr[a[i]]==0){
        //     cout<<0;
        //     continue;
        // }
        LL x=s[tot]-s[inv[a[i]]];
        if(x==0&&((tr[a[i]]==1)||(tr[a[i]]==0&&inv[a[i]]<tot))){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    cout<<'\n';

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}