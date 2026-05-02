#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,z;
    cin>>n>>z;
    vector<LL> b(n+1);
    vector<pair<LL,LL>> q1,q2;
    LL pos=0;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        if(b[i]==0)continue;
        if(b[i]>=2){
            pos=i;
        }
        if(i==n)continue;
        if(b[i]%2==1){  
            q1.push_back({b[i],i});
        }else{  
            q2.push_back({b[i],i});
        }
    }
    LL n1=q1.size();
    LL n2=q2.size();
   // printf("{%lld,%lld}",n1,n2);
    vector<LL> ans(n+1,0);
    LL tag=1;
    for(int i=n;i>=pos+1;i--){
        ans[i]=tag;
        tag=tag^1;
    }

    if(b[pos]%2==0){
        tag=tag^1;
        if(z%2==1){
            tag=tag^1;
        }
        ans[pos]=tag;
    }else{
        if(z%2==1){
            tag=tag^1;
        }
        ans[pos]=tag;   
    }
    tag^=1;

    for(int i=n1-1;i>=0;i--){
        if(q1[i].second>=pos)continue;
        ans[q1[i].second]=tag;
        tag=tag^1;
    }

    tag=tag^1;
    for(int i=0;i<n2;i++){
        if(q2[i].second==pos)continue;
        ans[q2[i].second]=tag;
    }
    for(int i=n;i>=1;i--){
        cout<<ans[i];
    }
    cout<<'\n';

}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}



