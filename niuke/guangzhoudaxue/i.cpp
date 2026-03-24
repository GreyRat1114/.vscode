#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
LL a[N];
LL b[N];
void solve(){
    int n,m;
    cin>>n>>m;
    set<LL> s1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s1.insert(a[i]);
    }
    int s=0;
    LL sum=0;
    for(int i=1;i<=m;i++){
        cin>>b[i];
        if(s1.count(b[i])){
            sum+=b[i];
            s++;
        }
    }
    int x=n-s;
    int y=m-s;
    if(x>y){
        cout<<sum<<' '<<0<<'\n';
    }else{
        cout<<0<<' '<<sum<<'\n';
    }

}
int main(){
    solve();
    return 0;
}