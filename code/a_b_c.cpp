// A - Vacation Validation
// #include<bits/stdc++.h>
// using namespace std;
// const int N=105;
// char s[N];
// int main()
// {
//     int n,l,r;
//     int tag=1;
//     scanf("%d%d%d",&n,&l,&r);
//     getchar();
//     scanf("%s",s+1);
//     for(int i=l;i<=r;i++)
//     {
//         if(s[i]=='x')
//         {
//             tag=0;
//         }
//     }
//     if(tag)
//     {
//         printf("Yes\n");
//     }
//     else
//     {
//         printf("No\n");
//     }
//     return 0;
// }


// B - 1D Akari
// #include<bits/stdc++.h>
// using namespace std;
// const int N=105;
// char s[N];
// char t[N];
// int main()
// {
//     int n,l,r;
//     int tag=0;
//     scanf("%s",s);
//     n=strlen(s);
//     for(int i=0;i<n;i++)
//     {
//         t[i]=s[i];
//     }
//     int p;
//     for(int i=0;i<n;i++)
//     {
//         if(s[i]=='.'&&tag==0)
//         {
//             t[i]='o';
//             tag=1;
//         }
//         if(tag==1&&s[i]=='#')
//         {
//             tag=0;
//         }
//     }
//     printf("%s",t);
//     return 0;
// }


// C - Concat (X-th)
// #include<bits/stdc++.h>
// using namespace std;
// const int N=105;
// char s[N];
// char t[N];
// int main()
// {
//     int n,l,r;
//     int tag=0;
//     scanf("%s",s);
//     n=strlen(s);
//     for(int i=0;i<n;i++)
//     {
//         t[i]=s[i];
//     }
//     int p;
//     for(int i=0;i<n;i++)
//     {
//         if(s[i]=='.'&&tag==0)
//         {
//             t[i]='o';
//             tag=1;
//         }
//         if(tag==1&&s[i]=='#')
//         {
//             tag=0;
//         }
//     }
//     printf("%s",t);
//     return 0;
// }


// D - Match, Mod, Minimize 2
// #include<bits/stdc++.h>
// using namespace std;
// const int N=3e5+5;
// using LL=long long;
// LL a[N];
// LL b[N];
// bool cmp(LL a,LL b)
// {
//     return a>b;
// }
// int main()
// {
//     int n,m;
//     int t;
    
//     scanf("%d",&t);
//     while(t--)
//     {
//         LL s1=0;
//         LL s2=0;
//         scanf("%d%d",&n,&m);
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%lld",&a[i]);
//         }
//         for(int i=1;i<=n;i++)
//         {
//             scanf("%lld",&b[i]);
//         }
//         sort(a+1,a+1+n,cmp);
//         multiset<LL> s;
//         for(int i=1;i<=n;i++)
//         {
//             s.insert(b[i]);
//         }
//         LL ans=0;
//         for(int i=1;i<=n;i++)
//         {
//             int d=m-a[i];
//             auto p=s.lower_bound(d);
//             if(p==s.end())
//             {
//                 --p;
//             }
//             ans+=(a[i]+*p)%m;
//             s.erase(p);
//         }
//         printf("%lld\n",ans);
//     }
//     return 0;
// }


// A - Misdelivery
// #include<bits/stdc++.h>
// using namespace std;
// const int N=105;
// char s[N][N];
// char y[N];

// int main()
// {
//     int n;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         getchar();

//         scanf("%s",s[i]+1);

//     }
//     int x;
//     scanf("%d",&x);
//     getchar();
//     scanf("%s",y+1);
//     int tag=1;
//     int l=sizeof(y+1);
//     for(int i=1;i<=l&&tag;i++)
//     {
//         if(y[i]!=s[x][i])
//         {
//             tag=0;
//         }
//     }
//     if(tag)
//     {
//         printf("Yes\n");
//     }
//     else
//     {
//         printf("No\n");

//     }
//     return 0;
// }


// B - Fibonacci Reversed  
// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=1e6+5;
// LL a[N];

// int main()
// {
//     LL x,y;
//     scanf("%lld%lld",&a[0],&a[1]);
//     for(int i=2;i<=9;i++)
//     {
//         LL z=a[i-2]+a[i-1];
//         LL b;
//         LL ab=0;
//         while(z!=0)
//         {
//             b=z%10;
//             z=z/10;
//             ab=ab*10+b;
//         }
//         a[i]=ab;
        
//     }
//     printf("%lld\n",a[9]);
//     return 0;
// }


// C - Alternated 
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=1e6+5;
char s[N];
queue<int> q1;
queue<int> q2;

int main()
{
    LL n;
    scanf("%lld",&n);
    scanf("%s",s);
    int p=1;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='A')
        {
            q1.push(i);
        }
        else if(s[i]=='B')
        {
            q2.push(i);
        }
    }
    while(1)
    {

    }
    return 0;
}