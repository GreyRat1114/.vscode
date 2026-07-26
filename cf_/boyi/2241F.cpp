#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using i128=__int128_t;
const LL mod=998244353;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+2);
    
    string s;
    cin>>s;
    map<LL,LL> mp;
    LL cnt=0;
    for(int i=0;i<n;i++){
        LL d=s[i]-'0';
        mp[d%2]++;
        if(d==0){
            cnt+=mp[1];
        }
    }
    if((cnt%2)==1){
        cout<<"Alice"<<'\n';
        return;
    }    
    LL l=0;
    while(s[l]!='1'&&l<=n-1){
        l++;
    }
    LL r=n-1;
    while(s[r]!='0'&&r>=0){
        r--;
    }
    LL tot=0;
    for(;l<=r;l++){
        tot++;
        a[tot]=s[l]-'0';
    }
    a[tot+1]=9;
    cnt=1;
    LL tag=1;
    for(int i=2;i<=tot+1;i++){
        if(a[i]==a[i-1]){
            cnt++;
        }else{
            if(cnt%2==1){
                tag=0;
                break;
            }else{
                cnt=1;
            }
        }

    }
    if(tag){
        cout<<"Bob"<<'\n';
    }else{
        cout<<"Alice"<<'\n';
    }

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