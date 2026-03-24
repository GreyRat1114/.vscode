#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
LL a[N];
void solve(){
    int n;
    cin>>n;
    double m=(n-1)*0.8;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    LL s=0;
    for(int i=1;i<=n;i++){
        LL cnt=0;
        for(int j=1;j<=n;j++){
            if(j==i){
                continue;
            }
            if(a[j]<=a[i]){
                cnt++;
            }
        }
        //printf("{%lld %lld}",i,cnt);
        if(cnt>=m){
            s+=a[i];
        }

    }    
    cout<<s<<'\n';
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}