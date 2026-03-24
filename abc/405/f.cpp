// #include<bits/stdc++.h>
// using namespace std;
// const int N=4e6+5;
// using LL=long long;
// const LL mod=998244353;
// vector<array<int,3>> vec[N];
// int s[N];
// int ans[N];

// int lowbit(int x){
//     return x&-x;
// }
// int n,m;
// void change(int x,int k)//向后修
// {
//     while(x<=N)
//     {
//         s[x]+=k;
//         x+=lowbit(x);
//     }
// }
// int query(int x)//向前查
// {
//     int t=0;
//     while(x)
//     {
//         t+=s[x];
//         x-=lowbit(x);
//     }
//     return t;

// }
// void solve(){
//     cin>>n>>m;
//     int x,y,z;
//     for(int i=1;i<=m;i++){
//         cin>>x>>y;
//         vec[x].push_back({y,0,0});
//     }
//     int q;
//     cin>>q;

//     for(int i=1;i<=q;i++){
//         cin>>x>>y;
//         vec[x].push_back({x,1,i});
//         vec[y].push_back({y,1,i});
//         vec[x].push_back({y,-2,i});
//     }
//     int seg=0;
//     for(int i=1;i<=2*n;i++){
//         if(i&1){
//             for(auto[x,y,z]:vec[i]){
//                 ans[z]+=y*(seg-query(x));
//             }            
//         }
//         else{
//             if(vec[i].size()){
//                 seg+=1;
//             }
            
//             for(auto[x,y,z]:vec[i]){
//                 change(x,1);
//             }
//         }
//     }
//     for(int i=1;i<=q;i++){
//         cout<<ans[i]<<'\n';
//     }
// }
// int main(){
//     solve();
//     return 0;
// }