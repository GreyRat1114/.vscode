#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
using i128=__int128_t;

string r = "Rounddo";

void solve(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    string r1 = r;
    while(k--) r1 += "g";
    auto check=[&](string &s1,string &tar,LL p)->LL{
       // printf("\n{%lld}",p);
        LL tag=1;
        LL n=tar.size();
        for(int i=0;i<n;i++){
            if(s1[p+i]!=tar[i]){
                tag=0;
                //printf("{%lld,%lld,%c,%c}",p,i,s1[p+i],tar[i]);
            };
        }
        return tag;
    };
    int num = 0;
    
    auto it = s.find(r1);
    if(it != string::npos) num++;

    if(it != string::npos) {
        auto e = s.find(r1,it+r1.size());
        if(e != string::npos) num++;
    }
    
    string w = s + s;
    for(int i=s.size()-r1.size()+1;i<s.size();i++){
        
        if(check(w,r1,i))num++;
    }
    // auto v = w.find(r1,it+1);
    // if(v != string::npos) num++;
    //printf("{%lld,%lld}",num,s.size());
    if(num==0)cout << 0 << "\n";
    else if(num == 1) cout << s.size() - r1.size() + 1 << "\n";
    else {cout << s.size() << "\n";}
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