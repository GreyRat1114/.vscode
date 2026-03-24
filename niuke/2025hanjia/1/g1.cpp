#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--){
		string l,r;
		cin >> l >> r;
		bool p=0;
		if(r[0]=='1')
			for(int i=1;i<(int)r.size();i++)
				if(r[i]!='0'){
					p=0;
					break;
				}
				else
					p=1;
		if(p&&l.compare(r)){
			for(int i=0;i<(int)r.size()-1;i++)
				cout << 9;
			cout << endl;
		}
		else if(r.size()==1){
			cout << r << endl;
		}
		else if(l.compare(r)==0){
			int i=(int)l.size()-1;
			while(l[i]=='0')i--;
			for(;i>=0;i--)
				cout << l[i];
			cout << endl;
		}
		else{
			if(l.size()<r.size()){
				l.clear();
				l.push_back('1');
				for(int i=1;i<(int)r.size();i++)
					l.push_back('0');
			}
			int i=0;
			bool f=1;
			while(i<(int)l.size()&&l[i]==r[i])i++;
			for(int j=0;j<(int)l.size()-i-1;j++)
				cout << 9;
			for(int j=(int)l.size()-1;j>=i+1;j--)
				if(r[j]!='9')
					f=0;
			for(int j=i;j>=0;j--)
				if(j!=i||f)
					cout << r[j];
				else
					cout << (char)(r[j]-1);
			cout << endl;
		}
	}
}