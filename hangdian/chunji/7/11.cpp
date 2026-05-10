#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<LL> fa;
vector<LL> siz;
void init(LL n){
    for(int i=0;i<=n;i++){
        fa[i]=i;
    }
}
LL find(LL x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void merge(LL x,LL y){
    LL fx=find(x);
    LL fy=find(y);
    if(fx!=fy){
        fa[fx]=fy;
    }
}
void solve(){
    LL n,k;
    cin>>n>>k;
    
    string s;
    cin>>s;
    fa.resize(n+1);
    siz.assign(n+1,0);
    init(n);
    vector<LL> vis(n+1,0);
    for(int i=0;i<n;i++){
        if(vis[i]==1)continue;
        LL p=i;
        while(!vis[p]){
            merge(i,p);
            vis[p]=1;
            p=(p+k)%n;
        }
    }
    set<LL> st;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            LL fx=find(i);
            st.insert(fx);
            siz[fx]++;
        }
    }
    // for(auto x:st){
    //     //printf("{%lld,%lld}",x,siz[x]);
    // }
    for(int i=0;i<n;i++){
        LL l=i;
        LL r=n-1-i;
        LL fl=find(l);
        LL fr=find(r);
        if(!st.count(fl)){
            continue;
        }
        if(siz[fl]%2==0){
            st.erase(fl);
            continue;
        }
        if(fl==fr){
            continue;
        }        
        //printf("{%lld,%lld}",fl,fr);
        if(siz[fl]%2==1&&siz[fr]%2==1){
            st.erase(fl);
            st.erase(fr);
        }
    }
    if(st.size()){
        cout<<"NO"<<'\n';
    }else{
        cout<<"YES"<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}