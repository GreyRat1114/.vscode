#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e3+5;
const LL mod=1e9+7;
void solve(){
    LL n;
    cin>>n;
    vector<LL> p(n+1);
    vector<LL> mex(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    mex[n]=n;
    LL pre=n;
    for(int i=n-1;i>=1;i--){
        mex[i]=min(mex[i+1],p[i+1]);
        pre+=mex[i];
        //printf("{%lld}",mex[i]);
    }
    deque<pair<LL,LL>> q;
    LL cnt=1;
    mex[0]=-1;
    for(int i=1;i<=n;i++){
        if(mex[i]!=mex[i-1]){
            //if(!q.empty())printf("{%lld,%lld}",q.back().first,q.back().second);
            q.push_back({mex[i],1});
        }else{
            q.back().second++;
        }
    }
    //printf("{%lld,%lld}",q.back().first,q.back().second);
    LL ans=pre;
    for(int i=1;i<=n;i++){
        pre-=q.front().first;
        if(q.front().second==1){
            q.pop_front();
        }else{
            q.front().second--;
        }
        LL x=p[i];
        LL c=0;
        LL s=0;
        while(!q.empty()&&q.back().first>x){
            c+=q.back().second;
            s+=q.back().second*q.back().first;
            q.pop_back();
        }
        pre=pre-s+x*c;
        
        if(c!=0)q.push_back({x,c});
        pre+=n;;
        q.push_back({n,1});
        //printf("{%lld}",pre);
        ans=max(ans,pre);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}