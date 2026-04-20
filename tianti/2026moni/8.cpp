#include<bits/stdc++.h>
using namespace std;
using LL=long long;

void solve(){
    LL n;
    cin>>n;
    string s;
    cin>>s;
    auto check=[&](string s1)->LL{

    };    
    for(int i=1;i<=n;i++){
        string s1;
        LL op;
        cin>>op;

        if(op==1){
            cin>>s1;
            LL m=s1.size();
            LL pos=s.find(s1);
            cout<<pos<<'\n';
        }else if(op==2){
            cin>>s1;
            LL pos=s.find(s1);
            LL m=s1.size();
            s.replace(pos,m,s1);

        }else{

        }

    }
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}