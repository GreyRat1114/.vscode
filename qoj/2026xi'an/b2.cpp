#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using i128=__int128_t;
i128 floor_div(i128 a, i128 b) {
    if (a >= 0) return a / b;
    return -((-a + b - 1) / b);
}
i128 ceil_div(i128 a, i128 b) {
    if (a >= 0) return (a + b - 1) / b;
    return -((-a) / b);
}
bool check(i128 q,i128 x,i128 lp,i128 up,i128 ls,i128 us){
    if(lp>up||ls>us)return false;
    if(q==0){
        return lp<=x&&x<=up;
    }
    i128 L=lp;
    i128 R=up;
    L=max(L,ceil_div(x-q*us,q+1));
    R=min(R,floor_div(x-q*ls,q+1));
    if(L>R)return false;
    i128 rem=x%q;
    i128 cand=rem;
    if(cand<L){
        cand+=ceil_div(L-cand,q)*q;
    }
    return cand<=R;
}
void solve(){
    LL n,xx,yy;
    cin>>n>>xx>>yy;
    string s;
    cin>>s;
    i128 x=xx;
    i128 y=yy;
    i128 T=x+y;
    i128 q=T/n;
    LL r=(T%n);
    i128 lp=0,up=0;
    i128 ls=0,us=0;
    for(int i=0;i<n;i++){
        bool pre=i<r;
        if(s[i]=='0'){
            if(pre){
                lp++;
                up++;
            }else{
                ls++;
                us++;
            }
        }else if(s[i]=='2'){
            if(pre){
                up++;
            }else{
                us++;
            }
        }
    }
    if(!check(q,x,lp,up,ls,us)){
        cout<<-1<<'\n';
        return;
    }
    string ans=s;
    for(int i=0;i<n;i++){
        if(s[i]!='2')continue;
        bool pre=i<r;
        if(pre){
            lp++;
            if(check(q,x,lp,up,ls,us)){
                ans[i]='0';
            }else{
                lp--;
                up--;
                ans[i]='1';
            }
        }else{
            ls++;
            if(check(q,x,lp,up,ls,us)){
                ans[i]='0';
            }else{
                ls--;
                up--;
                ans[i]='1';
            }
        }
    }    
    cout<<ans<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}