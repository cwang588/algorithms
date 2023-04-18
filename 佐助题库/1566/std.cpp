#include<bits/stdc++.h>
using namespace std;
void work(){
	int now=rand()%26,t=rand()%2;
	if(t==1)cout<<(char)('a'+now);
	else cout<<(char)('A'+now);
}
int main(){
	freopen("1577.in","r",stdin);
	string s;
	getline(cin,s);
	int n=s.length();
	for(int i=0;i<n-1;++i)cout<<s[i]<<' ';
	cout<<s[n-1]<<"\n";
	return 0;
}
