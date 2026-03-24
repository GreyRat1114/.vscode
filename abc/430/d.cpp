// D - Neighbor Distance
// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e5+5;
// using LL=long long;
// LL x[N];

// void solve(){
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         cin>>x[i];
//     }
//     map<LL,LL> mp;
//     mp[0]=0;
//     LL ans=0;
//     for(int i=1;i<=n;i++){
//         LL dx=ans;
//         mp[x[i]]=0;
//         auto p=mp.find(x[i]);
//         auto p1=prev(p);
//         auto p2=next(p);        
//         LL a=-1;
//         LL b=-1;
//         a=p1->first;
//         if(p2!=mp.end()){
//             b=p2->first;
//         }
//             // printf("{%lld,%lld,%lld,%lld}",a,b,x[i],ans);
//         if(i==1){
//             mp[0]=x[i];
//             dx+=mp[0];
//             mp[x[i]]=x[i];
//             dx+=x[i];
//             cout<<dx<<'\n';
//             ans=dx;
//             continue;
//         }
//         if(a!=-1){
//             if(x[i]-a<mp[a]){
                
//                 dx=dx-mp[a]+x[i]-a;
//                 mp[a]=x[i]-a;
                
//             }
//         }
//         if(b!=-1){
//             if(b-x[i]<mp[b]){
//                 dx=dx-mp[b]+b-x[i];
//                 mp[b]=b-x[i];
//                 // printf("{%lld,%lld}",x[i],dx);
//             }            
//         }
//         if(b==-1){
//             mp[x[i]]=x[i]-a;
//             dx+=x[i]-a;
//             // printf("{%lld,%lld}",x[i],dx);
//         }
//         else{
//             if(x[i]-a<b-x[i]){
//                 mp[x[i]]=x[i]-a;
//                 dx+=x[i]-a;
//                 // printf("{%lld,%lld}",x[i],dx);
//             }
//             else{
//                 mp[x[i]]=b-x[i];
//                 dx+=b-x[i];
//                 // printf("{%lld,%lld}",x[i],dx);
//             }
            
//         }
//         ans=dx;

        
//         cout<<dx<<'\n';
//     }
    
// }
// int main(){
//     solve();
//     return 0;
// }