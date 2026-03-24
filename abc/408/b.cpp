#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
int a[N];
void solve(){
    int n,s;
    int x,y;
    cin>>n;
    set<int> st;
    for(int i=1;i<=n;i++){
        cin>>x;
        st.insert(x);
    }
    cout<<st.size()<<'\n';
    for(auto ans:st){
        cout<<ans<<' ';
    }
    cout<<'\n';


}
int main(){
    solve();
    return 0;
}