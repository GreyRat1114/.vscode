// A - Range Flip Find Route
// #include<bits/stdc++.h>
// using namespace std;
// const int N=105;
// int a[N][N];

// void solve(){

//     int h,w;
//     cin>>h>>w;
//     vector<vector<int>> dp(N,vector<int>(N,1e9));
//     string s;
    
//     for(int j=1;j<=h;j++){
//         cin>>s;
//         for(int i=0;i<w;i++){
//             if(s[i]=='#'){
//                 a[j][i+1]=1;
//             }
//             else{
//                 a[j][i+1]=0;
//             }
//         }        
//     }
//     if(a[1][1]==1){
//         dp[1][1]=1;
//     }
//     else{
//         dp[1][1]=0;
//     }
    
//     for(int i=1;i<=h;i++){
//         for(int j=1;j<=w;j++){
//             int up=dp[i-1][j];
//             int lt=dp[i][j-1];
//             int d1=0;
//             int d2=0;
//             if(a[i][j]==1&&a[i-1][j]==0){
//                 d1++;
//             }
//             if(a[i][j]==1&&a[i][j-1]==0){
//                 d2++;
//             }      
//             dp[i][j]=min(dp[i][j],min(up+d1,lt+d2));      
//         }
//     }
//     cout<<dp[h][w]<<'\n';
// }
// int main(){
//     solve();
//     return 0;
// }