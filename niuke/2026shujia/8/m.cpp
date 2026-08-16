#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=100005;
struct trie{
    vector<vector<int>> nex;
    LL cnt;
    vector<int> exist;
    void init(LL n){
        nex.assign(n+1,vector<int>(30,0));
        exist.assign(n+1,0);
        cnt=0;
    }
    void insert(string &s,LL l){
        LL p=0;
        for(int i=0;i<l;i++){
            LL c=s[i]-'a';
            if(!nex[p][c])nex[p][c]=++cnt;
            p=nex[p][c];
        }
        exist[p]=true;
    }
};  
void solve(){
    LL n,m;
    cin>>n>>m;
    string s;
    vector<string> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    auto check=[&](string &s1,string &s2)->LL{
        LL p=0;
        LL siz=min(s1.size(),s2.size());
        for(int i=0;i<siz;i++){
            if(s1[i]!=s2[i])break;
            p=i;
        }
        return p;
    };
    for(int i=1;i<n;i++){
        LL p=check(a[i-1],a[i]);

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