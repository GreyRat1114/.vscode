#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
using LL=long long;
#define mp make_pair
const LL mod=998244353;
LL a[N];
LL b[N];

void solve(){
    int n,m;
    cin>>n>>m;
    LL sa=0;
    LL sb=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sa+=a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        sb+=b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);

    if(sa>sb){
        int s=0;
        for(int i=n;i>=1;i--){

            sa-=a[i];
            s++;
            if(sa<=sb){
                cout<<n-i+1<<'\n';
                return;
            }
        }
    }else if(sa<sb){
        for(int i=m;i>=1;i--){

            sb-=b[i];
            if(sa>=sb){
                cout<<m-i+1<<'\n';
                return;
            }
        }
    }else{
        cout<<1<<'\n';
        return;
    }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}