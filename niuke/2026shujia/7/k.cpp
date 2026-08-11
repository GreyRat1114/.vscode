#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
using i128=__int128_t;
void solve(){
    LL n;
    cin>>n;
    getchar();
    vector<string> a(n+1);
    map<string,vector<string>> mp;
    for(int j=1;j<=n;j++){
        string s;
        getline(cin,s);
        cout<<s<<'\n';
        string t(1,s[0]);
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                t=t+s[i+1];
            }
        }
        mp[t].push_back(s);
        cout<<t<<'\n';
    }
    auto work=[&](vector<string> vs,LL len)->void{
        LL siz=vs.size();
        for(int i=1;i<=len;i++){
            map<string,vector<string>> mp;
            
            for(int j=0;j<siz;j++){

                LL cnt=0;
                string s1="";
                for(int k=0;k<vs[j].size();k++){
                    if(vs[j][k]==' ')cnt++;

                    if(cnt>=i){
                        s1=vs[j].substr(k);
                        mp[s1].push_back(vs[j]);
                    }
                }

            }
            for(auto )
        }
    };
    for(auto cp:mp){
        if(cp.second.size()==1)continue;
        
        for(auto s:cp.second){

        }
    }

}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}