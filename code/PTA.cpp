// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     long long n;
//     scanf("%lld",&n);
//     double ans=10;
//     double x=n;
//     double y=n+1;
//     ans=x/y;
//     printf("%.6lf",ans);
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     scanf("%d",&n);
//     printf("%c%c",n+65-1,n+97-1);

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m;
//     scanf("%d%d",&n,&m);
//     long long s;
//     s=0;
//     for(int i=0;i<m;i++)
//     {
//         s+=n-i;
//     }
//     printf("%lld",s);
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int m;
//     char n;
//     scanf("%c%d",&n,&m);
//     m=m%97;
//     int ans=n+m;
//     if(ans>=97&&ans<=122)
//     {
//         printf("%c",ans);
//     }
//     else if(ans<97)
//     {
//         printf("%c",ans+26);
//     }
//     else if(ans>122)
//     {
//         printf("%c",ans-26);
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// char xx[10005];
// int main()
// {
//     int n;
//     double s=0;
//     int sum=0;
//     int m;
//     gets(xx);
//     int l=strlen(xx);
//     printf("%d\n",l);
//     for(int i=0;i<=l;i++)
//     {
//         if(xx[i]==' ')
//         {
//             continue;
//         }
//         s++;
//         sum+=xx[i]-80;
//         printf("%d",sum);
//     }
//     printf("SUM=%d,AVG=%.2lf",sum,sum/s);
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m;
//     scanf("%d%d",&n,&m);
//     for(int i=n;i<=m;i++)
//     {
//         int x=i;
//         int s=0;
//         for(int j=1;j<x;j++)
//         {
//             if(x%j==0)
//             {
//                 s+=j; 
//             }
//         }
//         if(s==x)
//         {
//             printf("%d ",x);
//         }
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// char xx[100];
// char yy[100];
// int main()
// {
//     int a,b,tot;
//     scanf("%d%d",&a,&b);
//     int flag=0;
//     for(int i=a;i<=b;i++)
//     {
//         int x=i*i;
//         int y=i;
//         int z;
//         tot=0;
//         while(x!=0)
//         {
//             z=x%10;
//             x=x/10;
//             xx[++tot]=z;

//         }
//         tot=0;
//         while(y!=0)
//         {
//             z=y%10;
//             y=y/10;
//             yy[++tot]=z;
//         }
//         int tag=1;
//         for(int i=1;i<=tot;i++)
//         {
//             if(xx[i]!=yy[i])
//             {
//                 tag=0;
//                 break;
//             }
//         }
//         if(tag)
//         {
//             flag=1;
//             printf("%d\n",i);
//         } 
//     }
//     if(flag==0)
//     {
//         printf("None");
//     }
//     return 0;
// }
#include <stdio.h>
#include <string.h>

void FGetStr(char *str, int size, FILE *file);

int main()
{
    FILE *f;
    char a[10], b[10];
    f = fopen("MyStr.txt", "r");
    if (f)
    {
        FGetStr(a, 10, f);
        FGetStr(b, 10, f);
        puts(a);
        puts(b);
        fclose(f);
    }
    return 0;
}
void FGetStr(char *str, int size, FILE *file)
{
    int i=0;
    char c;
    while(c=fgetc(file),c!='\n'&&c!=EOF&&i<size-1)
    {
        str[i]=c;
        ++i;
    }
    if(c!='\n')
    {
        ungetc(c,stdin);
    }
    str[i]='\0';
}