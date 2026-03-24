#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
LL a[N];
bool cmp(LL x,LL y){
    return x>y;
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    LL tk=0;
    LL ans=0;
    for(int i=1;i<=n;i++){
        if(tk>a[i]){
            break;
        }
        else{
            ans+=a[i]-tk;
            tk++;
        }
    }    
    cout<<ans<<'\n';
}
int main(){
    solve();
    return 0;
}