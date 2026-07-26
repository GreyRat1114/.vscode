#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+2);
    map<LL,vector<LL>> mp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]].push_back(i);
    }
    LL len=mp.rbegin()->first;
    LL minl=mp.begin()->first;
    LL minc=mp.begin()->second.size();
    if(minl!=len/2+1){
        cout<<"No"<<'\n';
        return;
    }
    if(len%2==0&&minc!=2){
        cout<<"No"<<'\n';
        return;        
    }else if(len%2==1&&minc!=1){
        cout<<"No"<<'\n';
        return;
    }
    if(mp.size()!=(len-1)/2+1){
        cout<<"No"<<'\n';
        return;        
    }
    vector<pair<LL,LL>> ans;
    auto it=mp.begin();
    LL pre1=it->second.back();
    it->second.pop_back();
    LL pre2=pre1;
    if(it->second.size()==1){
        pre2=it->second.back();
        ans.push_back({pre1,pre2});
        it->second.pop_back();

    }
    vector<LL> pos(n+1,0);
    it++;
    mp.erase(mp.begin());
    for(;it!=mp.end();it++){
        if(it->second.size()<2){
            cout<<"No"<<'\n';
            return;
        }else{
            pos[it->first]=pre1;
            LL nd1=it->second.back();
            it->second.pop_back();
            LL nd2=it->second.back();
            it->second.pop_back();    
            ans.push_back({nd1,pre1});        
            //cout<<nd1<<' '<<pre1<<'\n';
            pre1=nd1;
            ans.push_back({nd2,pre2}); 
            //cout<<nd2<<' '<<pre2<<'\n';
            pre2=nd2;     
        }
    }
    for(auto x:mp){
        LL l=x.first;
        for(auto y:x.second){
            ans.push_back({pos[l],y});        
            //cout<<pos[l]<<' '<<y<<'\n';
        }
    }
    cout<<"Yes"<<'\n';
    for(auto x:ans){
        cout<<x.first<<' '<<x.second<<'\n';
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