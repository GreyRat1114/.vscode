#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using i128=__int128;
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
struct Tree{
    LL n;
    vector<i128> s;
    void init(LL _n){
        n=_n;
        s.assign(n+1,0);
    }
    LL lowbit(LL x){
        return x&-x;
    }
    void update(LL x,i128 k){
        while(x<=n){
            s[x]+=k;
            x+=lowbit(x);
        }
    }
    i128 query(LL x){
        i128 ans=0;
        while(x){
            ans+=s[x];
            x-=lowbit(x);
        }
        return ans;
    }
};
i128 Abs(i128 v){
    return v<0?-v:v;
}
void solve(){
    LL n,x,y,k;
    cin>>n>>x>>y>>k;
    vector<LL> a(n+1);
    vector<LL> b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b.begin()+1,b.end());
    LL m=unique(b.begin()+1,b.end())-b.begin()-1;
    //cout<<m<<'\n';
    Tree tr;
    Tree tr2;

    tr.init(m+10);
    tr2.init(m+10);
    auto f=[&](i128 val,LL r,LL p)->i128{
        if(r==1){
            if(a[1]>val){
                return (a[1]-val)*y;
            }else{
                return (val-a[1])*x;
            }
        }
        i128 ans=0;
        i128 d1=Abs(a[1]-val);
        i128 d2=Abs(a[r]-val);
        if(a[1]<=val&&a[r]<=val){
            ans+=(d1+d2)*x;
        }else if(a[1]<=val&&a[r]>val){
            ans+=d1*x+d2*y;
        }else if(a[1]>val&&a[r]<=val){
            ans+=d1*y+d2*x;
        }else{
            ans+=(d1+d2)*y;
        }
        //printf("|%lld,%lld|",ans,tr.query(m)-tr.query(p));
        i128 sum=tr2.query(m)-tr2.query(p);
        ans+=y*(tr.query(m)-tr.query(p)-sum*val);

        return ans;
    };
    auto check=[&](LL r)->i128{
        i128 s=(n-r)*k;
        LL lt=1;
        LL rt=m;
        while(rt-lt>=2){
            LL mid=(lt+rt)/2;
            i128 fl=f(b[mid-1],r,mid-1);
            i128 fr=f(b[mid+1],r,mid+1);
            //printf("{%lld,%lld,%lld,%lld,%lld,%lld}",fl,fr,lt,rt,mid,r);
            if(fl>fr){
                lt=mid;
            }else{
                rt=mid;
            }
        }
        i128 val=a[r];
        LL p=lower_bound(b.begin()+1,b.begin()+m+1,val)-b.begin();
        //printf("<%lld,%lld>",lt,rt);
        i128 ans=s+min(f(b[lt],r,lt),f(b[rt],r,rt));
        if(r>1){
            tr.update(p,val);
            tr2.update(p,1);
        }
        return ans;
    };
    i128 ans=1e32;
    for(int i=1;i<=n;i++){
        i128 fx=check(i);
        //printf("{%lld}",fx);
        ans=min(ans,fx);
    }
    print(ans);
    cout<<'\n';
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