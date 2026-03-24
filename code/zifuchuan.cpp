// #include<bits/stdc++.h>
// using namespace std;
// const int N=3e5+5;
// int a[2*N];
// int n;
// int get_min(int*s)
// {
//     int i=1;
//     int j=2;
//     int k=0;
//     while(i<=n&&j<=n)
//     {
//         for(k=0;k<n&&s[i+k]==s[j+k];k++);
//         s[i+k]>s[j+k]?i=i+k+1:j=j+k+1;
//         if(i==j)
//         {
//             j++;
//         }        
//     }
//     return min(i,j);
// }
// int main()
// {
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&a[i]);
//         a[i+n]=a[i];
//     }
//     int p=get_min(a);
//     for(int i=p;i<=n+p-1;i++)
//     {
//         printf("%d ",a[i]);
//     }
//     return 0;
// }


// 【模板】字符串哈希
// #include<bits/stdc++.h>
// using namespace std;
// const int P=131;
// const int N=1e4+5;
// using ULL=unsigned long long;
// ULL p[N];
// ULL h[N];

// char s[N];
// bool vis[N];

// int n;
// void init()
// {
//     p[0]=1;   
//     for(int i=1;i<=n;i++)
//     {
//         p[i]=p[i-1]*P;
//     }
// }
// ULL get_val(int len)
// {
//     h[0]=0;
//     for(int i=1;i<=len;i++)
//     {
//         h[i]=h[i-1]*P+s[i];
//     }
//     return h[len];
// }
// ULL get(int l,int r)
// {
//     return h[r]-h[l-1]*p[r-l+1];
// }

// bool substr(int l1,int r1,int l2,int r2)
// {
//     return get(l1,r1)==get(l2,r2);

// }
// set<ULL> st;

// int main()
// {
//     scanf("%d",&n);
//     init();
//     for(int i=1;i<=n;i++)
//     {
       
//         getchar();
//         scanf("%s",s+1);
//         int l=1;
//         int r=strlen(s+1);
//         int len=r;
//         // printf("{%d,%d}\n",l,r);
//         // printf("|%lld|\n",get(l,r));
//         st.insert(get_val(len));
//     }
//     printf("%d",st.size());
    
//     return 0;
// }


// 无论怎样神树大人都会删库跑路
// #include<bits/stdc++.h>
// using namespace std;
// using ULL=unsigned long long;
// const int N=1e5+5;
// ULL p[N];
// ULL h[N];
// int s1[N];
// int s2[N];

// int main()
// {
//     int n,t,q;
//     scanf("%d%d%d",&n,&t,&q);
//     for(int i=1;i<=t;i++)
//     {
//         scanf("%d",&s1[i]);
//     }
//     int len,r,l;
//     for(int i=1;i<=n;i++)
//     {
//         scanf("%d",&len);
//         for(int j=1;j<=len;j++)
//         {
//             scanf("%d",&s2[j]);
//         }

//     }
//     int m;
//     scanf("%d",&m);

//     return 0;
// }


// A-B 数对
// #include<bits/stdc++.h>
// using namespace std;
// using ULL=unsigned long long;
// const int N=1e6+5;
// ULL p[N];
// ULL h[N];
// char s1[N];
// char s2[N];
// int ne[N];
// int n,m;
// void get_ne()
// {
//     ne[1]=0;
//     for(int i=2,j=0;i<=n;i++)
//     {
//         while(j&&s2[i]!=s2[j+1])
//         {
//             j=ne[j];
//         }
//         if(s2[i]==s2[j+1])
//         {
//             j++;
//         }
//         ne[i]=j;
//     }
// }
// void get_pos()
// {
//     for(int i=1,j=0;i<=m;i++)
//     {
//         while(j&&s1[i]!=s2[j+1])
//         {
//             j=ne[j];
//         }
//         if(s1[i]==s2[j+1])
//         {
//             j++;
//         }
//         if(j==n)
//         {
//             printf("%d\n",i-n+1);
//         }
//     }

// }

// int main()
// {
//     int t,q;
//     scanf("%s",s1+1);

//     scanf("%s",s2+1);

//     m=strlen(s1+1);
//     n=strlen(s2+1);
//     get_ne();
//     get_pos();
//     for(int i=1;i<=n;i++)
//     {
//         printf("%d ",ne[i]);
//     }
//     // printf("%s",s1+1);
//     // printf("%s",s2+1);
//     return 0;
// }


// P3375 【模板】KMP
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int ne[N];
string s,p;
int n;
void init(){
    ne[0]=-1;
    for(int i=1,j=-1;i<n;i++){
        while(j!=-1&&p[i]!=p[j+1]){
            j=ne[j];
        }
        if(p[i]==p[j+1]){
            j++;
        }
        ne[i]=j;
    }
}
void solve(){
    cin>>s;
    cin>>p;
    n=p.length();
    int m=s.length();
    init();
    for(int i=0,j=-1;i<m;i++){
        while(j!=-1&&s[i]!=p[j+1]){
            j=ne[j];
        }
        if(s[i]==p[j+1]){
            j++;
        }
        if(j==n-1){
            cout<<i-n+2<<'\n';
        }

    }
    for(int i=0;i<n;i++){
        printf("%d ",ne[i]+1);
    } 
}
int main(){
    solve();
    return 0;
}