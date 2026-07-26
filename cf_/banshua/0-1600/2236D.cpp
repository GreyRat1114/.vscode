#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,k;
    cin>>n>>k;
    vector<LL> a(n+1);
    map<LL,LL> mp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    // for(auto it=mp.rbegin();it!=mp.rend();it++){
    //     cout<<it->first<<' '<<it->second<<'\n';
    // }
    for(auto it=mp.rbegin();it!=mp.rend();it++){
        //cout<<it->first<<' '<<it->second<<'\n';
        auto it2=++it;
        it--;


        LL maxv=it->first;
        LL cnt=it->second;
        if(it2==mp.rend()){
            //printf("{%}");
            if(cnt%2==0){
                cout<<"YES"<<'\n';
            }else{
                cout<<"NO"<<'\n';
            }   
            return;
        }        
        LL minv=it2->first;
        
        if(cnt%2==0){
            cout<<"YES"<<"\n";
            return;
        }else if((cnt%2==1)&&(maxv-minv<=k)){
            // printf("??");
            // printf("{%lld,%lld}",maxv,minv);
            cout<<"YES"<<'\n';
            return;
        }else{
            // printf("::");
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