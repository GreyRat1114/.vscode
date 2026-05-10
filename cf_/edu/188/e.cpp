#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    string s;
    cin>>s;
    LL n=s.size();
    if(n==1){
        cout<<s<<'\n';
        return;
    }
    vector<LL> cnt(10,0);
    LL sum=0;
    for(int i=0;i<n;i++){
        cnt[s[i]-'0']++;
        sum+=s[i]-'0';
    }
    //printf("{%lld}",sum);
    for(int i=1;i<=sum;i++){
        vector<LL> t=cnt;
        LL x=i;
        string ans="";
        
        while(x>9){
            LL s1=0;
            vector<LL> q;
            while(x){
                LL y=x%10;
                t[y]--;
                q.push_back(y);
                
                s1+=y;
                x=x/10;
            }
            for(int j=q.size()-1;j>=0;j--){
                ans.push_back(q[j]+'0');
            }
            x=s1;
        }
        
        ans.push_back(x+'0');
        t[x]--;
        //printf("{%lld}",i);
        //cout<<ans;
        LL tag=1;
        for(int j=0;j<10;j++){
            if(t[j]<0)tag=0;
        }
        
        string ans2="";
        if(tag){
            LL s2=0;
            for(int j=9;j>=0;j--){
                s2+=t[j]*j;
            }
            if(s2!=i)tag=0;
        }
        if(tag){
            LL s2=0;
            for(int j=9;j>=0;j--){
                for(int k=1;k<=t[j];k++){
                    s2+=j;
                    ans2.push_back(j+'0');
                }
            }
            
        }       
        if(tag){
            cout<<ans2<<ans<<'\n';
            break;
        }
        //printf("{%lld}\n",tag);
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