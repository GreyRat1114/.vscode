#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
void solve(){
    LL q;
    cin>>q;
    LL op,num;
    set<LL> st;
    for(int i=1;i<=q;i++){
        cin>>op;
        if(op==1){
            cin>>num;
            st.insert(num);
        }else if(op==2){
            cin>>num;
            if(st.count(num)){
                cout<<"Yes"<<'\n';
            }else{
                cout<<"No"<<'\n';
            }
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