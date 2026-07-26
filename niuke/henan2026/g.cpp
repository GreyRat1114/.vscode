#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e6+5;
struct node1{
    LL l,r;
    mutable LL v;
    bool operator < (const node1 &o)const{
        return l<o.l;
    }
};
set<node1> odt;
void split(LL x){//切割区间
    auto it=odt.lower_bound({x,0,0});
    if(it!=odt.end()&&it->l==x){
        LL l=x+1;
        LL r=it->r;   
        odt.erase(it); 
        if(r>=l)odt.insert({l,r,0});     
        return;
    }
    --it;
    LL l=it->l;
    LL r=it->r;
    LL v=it->v;
    odt.erase(it);  
    LL r1=x-1;
    LL l1=x+1;
    if(r1>=l)odt.insert({l,r1,v});
    if(l1<=r)odt.insert({l1,r,v});
}
void perform(){//暴力遍历区间
    for(auto it=odt.begin();it!=odt.end();it++){
        printf("<%lld,%lld>",it->l,it->r);
    }
}
void solve(){
    odt.clear();
    LL n;
    cin>>n;
    vector<LL> a(n+1);
    map<LL,vector<LL>> mp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]].push_back(i);
    }
    odt.insert({1,n,0});
    sort(a.begin()+1,a.end());
    LL m=unique(a.begin()+1,a.end())-a.begin()-1;    
    a[0]=0;
    LL ans=0;
    for(int i=1;i<=m;i++){
        LL h=a[i]-a[i-1];
        LL cnt=odt.size();
        ans+=h*cnt;
        for(auto p:mp[a[i]]){
            //printf("(%lld)",p);
            split(p);
        }
        //perform();
        //cout<<'\n';
    }
    cout<<ans<<'\n';
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}