#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=5e3+5;
void solve(){
    int n;
    cin>>n;
    vector<int> e[5];
    if(n%3==1){
        cout<<n<<' ';
        for(int i=1;i<=n-1;i++){
            cout<<i<<' ';
        }
    }else{
        cout<<-1<<'\n';
    }
}
int main(){
    solve();
    return 0;
}