#include<bits/stdc++.h>
using namespace std;
using LL=long long;
struct node{
    LL cval,nval,k,d,cnt;
    bool operator <(const node &o) const {
        return d<o.d;
    }
    bool operator >(const node &o) const {
        return d>o.d;
    }
};
void update(node &x){
    LL cval=x.nval;
    LL k=x.k+1;
    LL cnt=x.cnt;
    LL c=(cnt-k)/(k+1);
    LL y=(cnt-k)%(k+1);
    LL nval=5*((k+1-y)*(c*(c+1)/2)+y*((c+2)*(c+1)/2))+20*(cnt-k);
    x.d=cval-nval;
    x.k++;
    x.cval=cval;
    x.nval=nval;
}
void solve(){
    LL n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    LL ans=0;
    vector<LL> a(n+3);
    for(int i=0;i<s.size();i++){
        a[i+1]=s[i]-'0';
    }
    a[n+1]=1;
    priority_queue<node> q;
    LL cnt=0;
    for(int i=1;i<=n+1;i++){
        if(a[i]==0){
            cnt++;
        }else{
            if(cnt==0)continue;
            
            LL cval=5*(cnt+1)*cnt/2+20*cnt;
            ans+=cval;
            LL c=(cnt-1)/2;
            LL y=(cnt-1)%2;
            LL nval=5*((2-y)*(c*(c+1)/2)+y*((c+2)*(c+1)/2))+20*(cnt-1);
            //printf("{%lld,%lld}",nval,cval);
            LL d=cval-nval;
            q.push({cval,nval,1,d,cnt});
            //printf("{%lld}",cnt);
            cnt=0;
        }
    }
    // if(!q.empty()){
    //     cout<<"LLL"<<'\n';
    // }
    LL op=k;
    while(!q.empty()&&k--){
        node nd=q.top();
        //printf("{%lld}",nd.d);
        q.pop();
        ans-=nd.d;
        update(nd);
        if(nd.k!=nd.cnt+1){
            q.push(nd);
        }
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