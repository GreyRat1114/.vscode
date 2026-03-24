// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=5e3+5;
// LL a[N];
// LL b[N];
// LL s[N];
// LL len[N];
// void solve(){
//     int n;
//     cin>>n;
//     s[0]=0;
//     for(int i=1;i<=n;i++){
//         cin>>a[i];
//         s[i]=s[i-1]+a[i];
//     }
//     double sum=0;
//     for(int i=1;i<=n-1;i++){
//         b[i]=a[i+1]+a[i];
//         len[i]=2;
//         // printf("[%lld]",b[i]);
//         sum+=1.0*b[i]/2;
//     }    
//     // printf("{%lf}",sum);
//     for(int i=3;i<=n;i++){
//         for(int l=1;l+i-1<=n;l++){
//             int r=l+i-1;
//             LL d=s[r]-s[l-1];
//             LL maxn=max(b[l],b[l+1]);
//             // printf("{%d,%d,%lld,%lld,%lld,%lld}",i,l,b[l],b[l+1],len[l],len[l+1]);
//             double x;
//             if(1.0*maxn/len[l]<1.0*d/i){
//                 b[l]=d;
//                 len[l]=i;
//                 // printf("00<%lf>",(1.0*b[l])/(1.0*i));
//                 sum+=(1.0*b[l])/(1.0*i);
//             }
//             else{
//                 b[l]=maxn;
//                 sum+=(1.0*b[l])/(1.0*len[l]);
//                 // printf("<%lf>",(1.0*b[l])/(1.0*len[l]));
//             }
//             // printf("<%lf>",sum);
//         }
//     }
//     LL ans=ceil(sum);
//     cout<<ans<<'\n';
// }
// int main(){
//     solve();
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=5e3+5;
LL a[N];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    LL s=0;
    for(int i=1;i<=n;i++){
        LL pre=0;
        for(int j=i+1;j<=n;j++){
            LL x=(a[j-1]+a[j])/2;

            pre=max(pre,x);
            if(j-2>=i){
                LL y=(a[j-2]+a[j-1]+a[j])/3;
                pre=max(pre,y);
            }            
            // printf("{%lld,%d,%d,%lld}",pre,i,j,s);
            s+=pre;
        }
    }
    cout<<s<<'\n';
}
int main(){
    solve();
    return 0;
}