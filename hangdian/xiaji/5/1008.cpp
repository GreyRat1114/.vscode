#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using i128=__int128_t;
struct Tree{
    LL n;
    vector<LL> s;
    void init(LL _n){
        n=_n;
        s.assign(n+1,0);
    }
    LL lowbit(LL x){
        return x&-x;
    }
    void update(LL x,LL k){
        while(x<=n){
            s[x]=max(s[x],k);
            x+=lowbit(x);
        }
    }
    LL query(LL x){
        LL ans=0;
        while(x){
            ans=max(ans,s[x]);
            x-=lowbit(x);
        }
        return ans;
    }
};
struct node{
    LL l,r;
    bool operator < (const node &o) const{
        if(l==o.l)return r<o.r;
        return l<o.l;
    }   
};
void solve(){
    LL n,q;
    cin>>n>>q;
    vector<node> a;
    vector<LL> b;
    map<LL,vector<LL>> mp;
    map<pair<LL,LL>,LL> ans;
    vector<node> check;
    for(int i=1;i<=n;i++){
        LL l,r;
        cin>>l>>r;
        a.push_back({l,r});
        b.push_back(l);
        b.push_back(r);
    }
    for(int i=1;i<=q;i++){
        LL l,r;
        cin>>l>>r;
        check.push_back({l,r});
        mp[l].push_back(r);
    }    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    LL m=unique(b.begin(),b.end())-b.begin();
    //printf("|%lld|",m);
    LL p=n-1;
    Tree tr;
    tr.init(m+5);
    for(auto it=mp.rbegin();it!=mp.rend();it++){
        //printf("{%lld,%lld}",it->first,p);
        while(p>=0&&a[p].l>=it->first){
            LL inv=lower_bound(b.begin(),b.begin()+m,a[p].r)-b.begin()+1;
            //printf("(%lld,%lld)",inv,p);
            tr.update(inv,a[p].r-a[p].l+1);
            p--;
        }
        LL l=it->first;
        for(auto r:it->second){
            LL inv=upper_bound(b.begin(),b.begin()+m,r)-b.begin();

            ans[{l,r}]=tr.query(inv);
        }
    }
    for(int i=0;i<q;i++){
        cout<<ans[{check[i].l,check[i].r}]<<'\n';
    }

}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    LL t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
