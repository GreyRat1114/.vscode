#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<pair<LL,LL>> a;
LL n;
LL check(LL mid){
    vector<LL> b; 
    //set<LL> st;
    vector<LL> c;
    b.push_back(0);
    c.push_back(0);
    LL m=0;
    LL tot=0; 
    for(int i=1;i<=n;i++){
        if(a[i].first>=mid){
            tot++;
            //st.insert(a[i].first+a[i].second);
            b.push_back(a[i].first+a[i].second);
        }else{
            m++;
            c.push_back(a[i].second+mid);
        }
    }
    sort(b.begin()+1,b.end());
    // for(int i=1;i<=tot;i++){
    //     printf("{%lld}",b[i]);
    // }
    sort(c.begin()+1,c.end());
    LL p=1;
    LL cnt=0;
    for(int i=1;i<=m;i++){
        while(b[p]<c[i]){
            p++;
            if(p>tot)break;
        }
        //printf("<%lld>",b[p]);
        if(p>tot)break;
        cnt++;
        p++;
    }
    //printf("|%lld,%lld,%lld,%lld|\n",mid,cnt,m,tot);
    if(cnt==m){
        return 1;
    }else{
        return 0;
    }

}
LL work(LL lt,LL rt){
    LL ans=rt;
    LL l=lt,r=rt;
    while(l<=r){
        LL mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
        //printf("{%lld,%lld,%lld}",l,r,mid);
    }
    return ans;
}
void solve(){
    cin>>n;
    a.resize(n+1);
    LL minn=1e9;
    LL maxn=0;
    //printf("{%lld}",n);
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        //printf("{%lld,%lld,%lld}",i,a[i].first,a[i].second);
        maxn=max(maxn,a[i].first);
        minn=min(minn,a[i].first);
    }
    //printf("{%lld,%lld}",maxn,minn);
    //LL ans=0;
    LL ans=work(minn,maxn);
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