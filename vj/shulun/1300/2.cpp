//cf1294C
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<LL> prim;
vector<LL> not_prim;
vector<LL> minp;
void get_prim(LL n){
    for(int i=2;i<=n;i++){
        if(!not_prim[i]){
            prim.push_back(i);
        }
        for(LL p:prim){
            if(i*p>n)break;
            not_prim[i*p]=1;
            minp[i*p]=p;
            if(i%p==0)break;
        }
    }
}
void init(LL n){
    not_prim.assign(n+10,0);
    minp.assign(n+10,0);
    get_prim(n+1);
}
void solve(){
    LL n;
    cin>>n;
    LL x=n;
    vector<LL> q;
    for(auto y:prim){
        while(x%y==0){
            x=x/y;
            q.push_back(y);
        }
    }
    if(x!=1)q.push_back(x);
        // for(int i=0;i<q.size();i++){
        //     printf("{%lld}",q[i]);
        // }    
    if(q.size()<=2){
        cout<<"NO"<<'\n';
    }else{
        vector<LL> ans;
        sort(q.begin(),q.end());
        map<LL,LL> vis;
        LL c=0;
        LL cur=1;
        for(int i=0;i<q.size();i++){
            cur*=q[i];
            if(!vis[cur]){
                vis[cur]=1;
                ans.push_back(cur);
                cur=1;
            }
            if(ans.size()==2){
                cur=1;
                for(int j=i+1;j<q.size();j++){
                    cur*=q[j];
                    //printf("{%lld,%lld}",j,cur);
                }
                ans.push_back(cur);
                break;
            }
        }
        if(ans[2]==1||ans[0]==ans[1]||ans[1]==ans[2]||ans[0]==ans[2]){
            cout<<"NO"<<'\n';
        }else{
            cout<<"YES"<<'\n';
            cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<'\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    init(1e6+5);
    while(t--){
        solve();
    }
    return 0;
}