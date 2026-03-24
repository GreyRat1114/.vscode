#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
void solve(){
    int n;
    cin>>n;
    vector<LL> a(n+1);
    int tag=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==67&&tag==0){
            cout<<"Yes"<<'\n';
            tag=1;
        }
    }
    if(tag==0){
        cout<<"No"<<'\n';
    }
    
    
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}