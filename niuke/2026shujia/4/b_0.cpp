#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using i128=__int128_t;
void solve(){
    LL x1,x2,p,q;
    cin>>p;
    for(LL k=sqrt(p)+1;;k++){
        q=k*k-p;
        x1=k%q;
        x2=k%p;
        if(x1>=1&&x1<q&&x2>=1&&x2<p){
            cout<<x1<<' '<<x2<<' '<<q<<'\n';
            break;
        }
    }

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