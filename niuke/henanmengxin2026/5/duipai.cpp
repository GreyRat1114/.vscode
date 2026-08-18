#include<bits/stdc++.h>
using namespace std;
int main(){
    
    while(1){
        system("gen.exe > test.in");
        system("f.exe < test.in > a.out");
        system("fduipai.exe < test.in > b.out");
        if(system("fc a.out b.out")){
            system("pause");
            return 0;
        }
    }
}