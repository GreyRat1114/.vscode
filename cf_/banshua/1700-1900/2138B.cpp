#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL n;
vector<LL> s1,s2;
LL lowbit(LL x){
    return x&-x;
}
void update(LL x,LL k,LL op){
    while(x<=n){
        if(op==0){
            s1[x]=max(s1[x],k);
        }else{
            s2[x]=min(s2[x],k);
        }
        x+=lowbit(x);
    }
}
LL query(LL x,LL op){
    LL ans=0;
    if(op==0){
        ans=0;
    }else{
        ans=1e9;
    }
    while(x){
        if(op==0){
            ans=max(ans,s1[x]);
        }else{
            ans=min(ans,s2[x]);
            //printf("{%lld}",s2[x]);
        }
        x-=lowbit(x);
    }
    return ans;
}
void solve(){
    LL q;
    cin>>n>>q;
    s1.assign(n+1,0);
    s2.assign(n+1,1e9);
    vector<LL> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<LL> l(n+1),r(n+1);
    for(int i=1;i<=n;i++){
        LL pos=n-a[i];
        l[i]=query(pos,0);
        update(pos+1,i,0);
    }
    for(int i=n;i>=1;i--){
        LL pos=a[i];
        r[i]=query(pos,1);
        update(pos,i,1);
    }
    vector<LL> inv(n+1,0);
    for(int i=1;i<=n;i++){
        if(l[i]==0||r[i]==1e9){
            continue;
        }
        //inv[r[i]]=inv[r[i]];
        inv[r[i]]=max(l[i],inv[r[i]]);
        //printf("{%lld,%lld}",l[i],r[i]);
    }
    for(int i=1;i<=n;i++){
        inv[i]=max(inv[i-1],inv[i]);
        //printf("{%lld,%lld}",inv[i],i);
    }
    //vector<LL> 
    LL lt,rt;
    for(int i=1;i<=q;i++){
        cin>>lt>>rt;
        if(rt-lt+1<3){
            cout<<"Yes"<<'\n';
        }else{
            if(inv[rt]==0){
                cout<<"Yes"<<'\n';
                continue;
            }
            if(inv[rt]<lt){
                cout<<"Yes"<<'\n';
            }else{
                cout<<"No"<<'\n';
            }
        }
    }
    //cout<<'\n';

}
int main(){
    ios::sync_with_stdio(false),cout.tie(0),cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}