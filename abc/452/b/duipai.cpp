#include<bits/stdc++.h>
using namespace std;
int main(){
    
    while(1){
        system("gen.exe > test.in");
        system("b_3.exe < test.in > aa.out");
        system("d_baoli.exe < test.in > bb.out");
        if(system("fc aa.out bb.out > diff.txt")){
            system("pause");
            return 0;
        }
        cout<<"Yes"<<'\n';
    }
    
}