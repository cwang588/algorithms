#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("15745.in","r",stdin);
//	freopen("15745.out","w",stdout);
	string s;
	getline(cin,s);
	int n=s.length();
	for(int i=0;i<n-2;++i)cout<<(char)(s[i]+s[i+1]);
	cout<<(char)(s[0]+s[n-2]); 
	return 0;
}
