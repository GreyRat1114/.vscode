#include<bits/stdc++.h>
using namespace std;
int main(){
    
    while(1){
        system("gen.exe > test.in");
        system("4.exe < test.in > a.out");
        system("4duipai.exe < test.in > b.out");
        if(system("fc a.out b.out")){
            system("pause");
            return 0;
        }
    }
}