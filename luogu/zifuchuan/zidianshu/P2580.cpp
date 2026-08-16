#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=100005;
struct trie{
    vector<vector<int>> nex;
    LL cnt;
    vector<int> exist,vis;
    void init(LL n){
        nex.assign(n+1,vector<int>(30,0));
        exist.assign(n+1,0);
        vis.assign(n+1,0);
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
    LL find(string &s,LL l){
        LL p=0;
        for(int i=0;i<l;i++){
            LL c=s[i]-'a';
            if(!nex[p][c])return 0;
            p=nex[p][c];
        }
        if(exist[p]){
            if(vis[p]){
                return 2;
            }else{
                vis[p]=1;
                return 1;
            }
        }else{
            return 0;
        }
    }
};  
void solve(){
    LL n,m;
    cin>>n;
    trie tr;
    tr.init(8*N);
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        tr.insert(s,s.size());
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        string s;
        cin>>s;
        LL tag=tr.find(s,s.size());
        if(tag==2){
            cout<<"REPEAT"<<'\n';
        }else if(tag==1){
            cout<<"OK"<<'\n';
        }else{
            cout<<"WRONG"<<'\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}