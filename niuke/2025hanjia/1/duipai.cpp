#include<bits/stdc++.h>
using namespace std;
int main(){
    
    while(1){
        system("gen.exe > test.in");
        system("g.exe < test.in > a.out");
        system("g1.exe < test.in > b.out");
        if(system("fc a.out b.out > diff.txt")){
            system("pause");
            return 0;
        }
    }
}