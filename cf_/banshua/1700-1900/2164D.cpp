#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
const LL mod=998244353;
void solve(){
    LL n,k;
    cin>>n>>k;
    string s,t;
    cin>>s;
    cin>>t;
    set<pair<LL,LL>> op;
    map<pair<LL,LL>,bool> mp;
    LL p1=n-1,p2=n-1;
    LL ans=0;
    while(p1>=0){
        p2=min(p2,p1);
        while(s[p2]!=t[p1]){
            p2--;
            if(p2<0)break;
        }
        if(p2<0)break;
        if(p1!=p2){
            op.insert(make_pair(-p2,-p1));
            mp[make_pair(-p2,-p1)]=false;
            //printf("{%lld,%lld}",p2,p1);
        }
        
        // op[p2]=p1;
        ans=max(ans,p1-p2);
        p1--;
    }
    if(p1>=0||ans>k){
        cout<<-1<<'\n';
    }else{
        cout<<ans<<'\n';
        for(LL d=1;d<=ans;d++){
            string s1=s;
            for(auto x:op){
                if(mp[x]){
                    continue;
                }
                p2=-x.first;
                p1=-x.second;
                
                if(p2+d==p1){
                    mp[x]=true;
                }
                s1[p2+d]=s1[p2+d-1];
            }
            s=s1;
            cout<<s1<<'\n';            
        }

    }
    
    
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}