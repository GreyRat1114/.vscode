#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+2),px(n+1),lp(n+1),rp(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    stack<LL> stk;
    a[0]=1e18;
    a[n+1]=1e18;
    stk.push(0);
    for(int i=1;i<=n;i++){
        while(!stk.empty()&&a[i]>=a[stk.top()]){
            stk.pop();
        }
        lp[i]=stk.top();
        stk.push(i);
    }
    stk=stack<LL>();

    stk.push(n+1);
    for(int i=n;i>=1;i--){
        while(!stk.empty()&&a[i]>a[stk.top()]){
            stk.pop();
        }
        rp[i]=stk.top();
        stk.push(i);
    }    

    unordered_map<LL,vector<LL>> mp;
    for(int i=1;i<=n;i++){
        mp[a[i]].push_back(i);
        //printf("{%lld,%lld}",lp[i],rp[i]);
    }
    auto check=[&](LL l,LL r,LL x)->LL{
        auto it=mp.find(x);
        if(it==mp.end()){
            return 0;
        }
        auto cl=lower_bound(it->second.begin(),it->second.end(),l);
        auto cr=upper_bound(it->second.begin(),it->second.end(),r);
        return cr-cl;

    };
    LL s=0;
    for(int i=1;i<=n;i++){
        LL k=a[i];
        if(k%2==0){
            continue;
        }
        LL p1=lp[i]+1;
        LL p2=rp[i]-1;
        if(i-p1+1<p2-i+1){
            for(int j=p1;j<=i;j++){
                LL x=k+1-a[j];
                s+=check(i,p2,x);
            }
        }else{
            for(int j=i;j<=p2;j++){
                LL x=k+1-a[j];
                s+=check(p1,i,x);
            }
        }
    }
    LL total=n*n;
    cout<<total-s*2<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}