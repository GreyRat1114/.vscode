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
    bool find(string &s,LL l){
        LL p=0;
        for(int i=0;i<l;i++){
            LL c=s[i]-'a';
            if(!nex[p][c])return 0;
            p=nex[p][c];
        }
        return exist[p];
    }
};  