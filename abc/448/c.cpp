#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
void solve(){
    LL n,q;
    cin>>n>>q;
    vector<LL> a(n+1),b(n+1);
    map<LL,int> tr;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        tr[a[i]]++;
    }
    int k;
    for(int i=1;i<=q;i++){
        cin>>k;
        //printf("{%d,%d}",i,k);
        for(int j=1;j<=k;j++){
            cin>>b[j];
            tr[a[b[j]]]--;
            if(tr[a[b[j]]]==0){
                tr.erase(a[b[j]]);
            }
        }
        LL minn=tr.begin()->first;
        cout<<minn<<'\n';
        for(int j=1;j<=k;j++){
            tr[a[b[j]]]++;
        }        
    }

}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}