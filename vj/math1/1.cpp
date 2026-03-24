#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    LL x1=ceil(sqrt(n));
    //printf("{%lld}",x1);
    LL h=x1*x1;
    LL t=(x1-1)*(x1-1)+1;
    LL mid=(h+t)/2;
    if(x1%2==0){
        if(n>=mid){
            cout<<x1<<' '<<x1+mid-n<<'\n';
        }
        else{
            cout<<x1+n-mid<<' '<<x1<<'\n';
        }
    }else{
        if(n>=mid){
            cout<<x1-n+mid<<' '<<x1<<'\n';
        }
        else{
            cout<<x1<<' '<<x1-mid+n<<'\n';
        }
    }

    // cout<<x1<<'\n';
}
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        printf("Case %d: ",i);
        solve();
    }
    
    return 0;
}