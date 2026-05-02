#include<bits/stdc++.h>
using namespace std;
using LL=long long;
bool cmp(pair<LL,LL> a,pair<LL,LL> b){
    return a.first>b.first;
}
void solve(){
    LL n;
    cin>>n;
    vector<pair<LL,LL>> q;
    LL maxn=0;
    LL pos=0;
    for(int i=1;i<=n;i++){
        cout<<'?'<<' '<<i<<' '<<n;
        for(int j=1;j<=n;j++){
            cout<<' '<<j;
        }
        cout<<'\n';
        cout.flush();
        LL s=0;
        cin>>s;
        if(maxn<s){
            pos=i;
            maxn=s;
        }
        q.push_back({s,i});
    }
    sort(q.begin(),q.end(),cmp);
    vector<LL> ans;
    ans.push_back(pos);
    LL len=1;
    vector<LL> vis2(n+1,0);
    vis2[len]=1;
    for(int i=1;i<n;i++){
        LL x=q[i].first;
        LL num=q[i].second;
        if(vis2[x]){
            continue;
        }
        //printf("{%lld,%lld,%lld}",len,x,num);
        cout<<'?'<<' '<<pos<<' '<<ans.size()+1;
        for(int j=0;j<ans.size();j++){
            cout<<' '<<ans[j];
        }
        cout<<' '<<num<<'\n';
        cout.flush();
        LL y;
        cin>>y;
        if(y!=len){
            len++;
            vis2[len]=1;
            ans.push_back(num);
            pos=num;            
        }
    }

    cout<<'!'<<' '<<maxn;
    for(auto i:ans){
        cout<<' '<<i;

    }
    cout<<'\n';
    cout.flush();
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

