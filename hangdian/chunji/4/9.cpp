#include<bits/stdc++.h>
using namespace std;
using LL=long long;
vector<LL> a,b;
vector<vector<LL>> f;
void init(LL n){
    for(int i=1;i<=n;i++){
        f[i][0]=b[i];
    }
    for(int j=1;j<=20;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
}
LL query(LL l,LL r){
    LL len=log2(r-l+1);
    //printf("{%lld}",max(f[l][len],f[r-(1<<len)+1][len]));
    return max(f[l][len],f[r-(1<<len)+1][len]);
}
void solve(){
    LL n,q;
    cin>>n>>q;
    a.resize(n+1);
    b.resize(n+1);
    f.assign(n+1,vector<LL>(30,0));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }    
    init(n);
    vector<vector<pair<LL,LL>>> vec(n+1);
    for(int i=1;i<=n;i++){
        vector<pair<LL,LL>> cur;
        cur.push_back(make_pair(i,a[i]));

        LL r=i;
        for(auto &pr:vec[i-1]){
            //printf("{&&}");
            LL l=pr.first;
            LL g=__gcd(pr.second,a[i]);
            if(cur.back().second==g){
                cur.back().first=l;
            }else{
                cur.push_back(make_pair(l,g));
            }
        }
        // for(auto x:cur){
        //     printf("{%lld,%lld,%lld}",x.first,i,x.second);
        // }
        //cout<<'\n';
        vec[i].swap(cur);
        // for(auto x:vec[i]){
        //     printf("{%lld,%lld,%lld}",x.first,i,x.second);
        // }        
    }
    LL l,r;
    for(int i=1;i<=q;i++){
        cin>>l>>r;
        //printf("{%lld,%lld}",l,r);
        LL pos;
        LL cnt=0;
        LL d=0;
        LL pre;
        for(int j=vec[r].size()-1;j>=0;j--){
            LL lt=max(vec[r][j].first,l);
            LL rt;
            if(j==0){
                rt=r;
            }else{
                rt=vec[r][j-1].first-1;
            }
            LL g=vec[r][j].second;
            if(rt<l)continue;
            LL maxn=query(lt,rt)-d;
            if(maxn<=0)continue;
            cnt+=(maxn-1)/g+1;
            d+=((maxn-1)/g+1)*g; 
            //printf("{%lld,%lld,%lld,%lld}",lt,rt,g,maxn);
        }
        cout<<cnt<<'\n';
    }
}
int main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}