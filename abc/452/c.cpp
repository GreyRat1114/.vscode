#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
int c[100][100];
LL n,m;
int ck[20][20];
void solve(){
    cin>>n;
    vector<LL> a(n+1,0),b(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    cin>>m;
    vector<string> s(m+1);
    vector<vector<map<char,LL>>> mp(20,vector<map<char,LL>>(20,map<char,LL>()));
    for(int i=1;i<=m;i++){
        cin>>s[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[i].size()==a[j]){
                mp[a[j]][b[j]][s[i][b[j]-1]]=i;
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(s[i].size()==n){
            int tag=1;
            
            for(int j=0;j<s[i].size();j++){
                //printf("{%lld,%lld}",a[j+1],b[j+1]);
                if(!mp[a[j+1]][b[j+1]].count(s[i][j])){
                    //printf("{%c}",s[i][j]);
                    tag=0;
                }
            }            
            if(tag){
                cout<<"Yes"<<'\n';

            }else{
                cout<<"No"<<'\n';
            }
        }else{
            cout<<"No"<<'\n';
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