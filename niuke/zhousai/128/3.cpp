#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
LL a[N];
void solve(){
    
    LL n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    LL m=(n-1)/2+1;
    LL x=(m-1)/2+1;
    for(int i=1;i<=n;i++){
        if(a[i]<=m){
            cout<<x<<' ';
        }else{
            cout<<a[i]<<' ';
        }
    }
    cout<<'\n';

}
int main(){
    solve();
    return 0;
}