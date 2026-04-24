#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
void solve(){
    LL n,s,x;
    cin>>n>>s>>x;
    vector<LL> a(n+2);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    LL ans=0;
    vector<pair<LL,LL>> q;
    LL l=0,r;
    a[n+1]=1e18;
    for(int i=1;i<=n+1;i++){
        if(a[i]>x&&l){
            r=i-1;
            q.push_back({l,r});
            l=0;
        }else if(a[i]<=x&&l==0){
            l=i;
        }
    }
    for(int j=0;j<q.size();j++){
        l=q[j].first;
        r=q[j].second;
        //printf("{%lld,%lld}",l,r);
        map<LL,vector<LL>> mp;
        mp[0].push_back(0);   
        LL pre=0;
        LL cur=0;        
        for(int i=l;i<=r;i++){ 
            pre+=a[i];
            //printf("<%lld>",pre);
            if(a[i]==x){
                cur=i;
            }
            LL y=pre-s;
            //if(!mp.count(y))continue;
            auto it=lower_bound(mp[y].begin(),mp[y].end(),cur);
            LL cnt=it-mp[y].begin();
            auto it1=mp[y].begin();
            //printf("{%lld}",*it1);
            //printf("{%lld,%lld}",cnt,y);
            if(it!=mp[y].end()&&*it!=cur){
                //cnt--;
            }
            //cnt=max(0ll,cnt);
            ans+=cnt;
            mp[pre].push_back(i);
        }             
    }
    cout<<ans<<'\n';
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