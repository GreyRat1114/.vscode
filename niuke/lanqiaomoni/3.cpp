#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const int N=2e5+5;
void solve(){
    LL n;
    cin>>n;
    vector<string> s(n+1);
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }

    vector<pair<string,LL>> mp(n+1);
    //set<string,LL> mp;
    for(int i=1;i<=n;i++){
        LL m=s[i].size();
        string s1(26,'0');
        for(int j=0;j<m;j++){
            LL c=s1[s[i][j]-'a'];
            c++;
            s1[s[i][j]-'a']=(char)c;
        }
        mp[i]={s1,i};
        //cout<<s1<<'\n';
    }
        //     sort(vec.begin(),vec.end(),[&](array<LL,2>l,array<LL,2>r){
        //     return l[1]>r[1];
        // });
    sort(mp.begin()+1,mp.end(),[&](pair<string,LL> &a,pair<string,LL> &b){
        if(a.first==b.first){
            return s[a.second]<s[b.second];
        }else{
            return a.first>b.first;
        }
    });
    for(int i=1;i<=n;i++){
        cout<<s[mp[i].second]<<' ';
    }
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}