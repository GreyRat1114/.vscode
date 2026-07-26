#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
void solve(){
    string s;
    cin>>s;
    LL n=s.size();
    string s1="execute";
    auto check=[&](LL p)->LL{
        LL tag=1;
        for(int i=0;i<7;i++){
            if(s[p+i]!=s1[i])tag=0;
        }
        return tag;
    };
    LL tot=0;
    vector<LL> a(n+1,0);
    for(int i=0;;i++){
        LL cnt=0;
        LL pre=i;
        while(check(i)){
            cnt++;
            i+=6;
            if(i>=n)break;
        }
        if(i>=n)break;
        if(cnt==0)continue;
        //if(cnt==1){s[pre]='1';continue;}
        if(cnt%2==0){
            pre+=6;
        }else{
            s[pre]='1';
            pre+=12;
        }
        while(pre<=i){
            s[pre]='1';
            pre+=12;
        }
    }
    cout<<s<<'\n';
    // for(int i=0;i<n;i++){
    //     tot+=a[i];
    // }
    //cout<<tot<<'\n';
    //cout<<(int)' '<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}