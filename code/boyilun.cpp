// P2197 【模板】Nim 游戏
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e4+5;
// int a[N];

// void solve()
// {
//     int n;
//     cin>>n;
//     int s=0;
//     int x;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>x;
//         s=s^x;

//     }
//     if(s==0)
//     {
//         cout<<"No"<<'\n';
//     }
//     else
//     {
//         cout<<"Yes"<<'\n';
//     }
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
    
//     return 0;
// }


// P1247 取火柴游戏
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e4+5;
// int a[N];

// void solve()
// {
//     int k;
//     cin>>k;
//     int s=0;
//     int x;
//     for(int i=1;i<=k;i++)
//     {
//         cin>>x;
//         a[i]=x;
//         s=s^x;
//     }

//     if(s==0)
//     {
//         cout<<"lose"<<'\n';
//         return;
//     }
//     int y=s;
//     int z=1;
//     int p;
//     while(z<=y)
//     {
//         z=z<<1;
//     }
//     z=z>>1;
//     int d;

//     for(int i=1;i<=k;i++)
//     {
//         if(a[i]&z)
//         {
//             d=a[i]-(a[i]^s);
//             a[i]=a[i]^s;
//             // cout<<a[i]<<'\n';
//             p=i;
//             break;
//         }
//     }
//     cout<<d<<' '<<p<<'\n';
//     for(int i=1;i<=k;i++)
//     {
//         cout<<a[i]<<' ';
//     }
//     cout<<'\n';
// }
// int main()
// {
//     solve();
//     return 0;
// }