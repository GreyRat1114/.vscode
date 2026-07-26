#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<LL> prim;
vector<LL> not_prim;
void get_prim(LL n){
    for(int i=2;i<=n;i++){
        if(!not_prim[i]){
            prim.push_back(i);
        }
        for(LL p:prim){
            if(i*p>n)break;
            not_prim[i*p]=1;
            if(i%p==0)break;
        }
    }
}
multiset<LL> st;
vector<LL> re;
void get(LL n){
    for(auto i:prim){
        if(i*i>n)break;
        while(n%i==0){
            n=n/i;
            re.emplace_back(i);
        }
    }
    if(n!=1)re.emplace_back(n);
}
void solve(){
    st.clear();
    re.clear();
    LL a,b,q;
    cin>>a>>b>>q;
    if(a==1&&b==1){
        for(int i=1;i<=q;i++){
            LL k;
            cin>>k;
            cout<<1<<' '<<1<<'\n';
        }
        return;
    }
    LL tag=0;
    if(a>b)tag=1;
    LL x=abs(a-b);
    //printf("(%lld,%lld,%lld)",a,b,x);
    get(x);
    LL t=a;
    LL tot=0;
    map<LL,pair<LL,LL>> mp;
    LL m=re.size();
    vector<LL> vis(m+1,0);
    mp[0]={a,b};
    // for(auto y:st){
    //     printf("{%lld}",y);
    // }
    while(x!=1){
        LL minn=1e18;
        LL mine;
        LL minp;
        for(int i=0;i<m;i++){
            if(vis[i])continue;
            LL e=re[i];
            LL t1=(t-1)/e+1;
            LL cnt=t1*e-t;
            if(cnt<minn){
                minn=cnt;
                mine=e;
                minp=i;
            }            
        }
        vis[minp]=1;
        LL t2=(t-1)/mine+1;
        tot+=t2*mine-t;
        t=t2;
        x=x/mine;
        //printf("{%lld,%lld}",t,x);
        if(tag){
            mp[tot]={t,t-x};
        }else{
            mp[tot]={t,t+x};
        }
        
    }
    // for(auto y:mp){
    //     printf("{%lld,%lld,%lld}",y.first,y.second.first,y.second.second);
    // }
    for(int i=1;i<=q;i++){
        LL k;
        cin>>k;
        auto it=mp.upper_bound(k);
        it--;
        LL d=k-it->first;
        cout<<it->second.first+d<<' '<<it->second.second+d<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    not_prim.assign(1e6+10,0);
    get_prim(1e6+10);

    LL t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}