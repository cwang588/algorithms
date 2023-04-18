#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("1572.in","r",stdin);
//	freopen("1572.out","w",stdout);
	string s;
	getline(cin,s);
	int n=s.length();
	for(int i=0;i<n;++i){
		if(s[i]==' '&&s[i+1]==' ')continue;
		cout<<s[i];
	}
	return 0;	
}
