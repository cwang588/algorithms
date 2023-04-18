#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("15711.in","r",stdin);
//	freopen("15711.out","w",stdout);
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	int n=s1.length(),m=s2.length();
	for(int i=0;i<min(n,m);++i){
		if(s1[i]>='A'&&s1[i]<='Z')s1[i]+='a'-'A';
		if(s2[i]>='A'&&s2[i]<='Z')s2[i]+='a'-'A';
		if(s1[i]<s2[i])return !printf("<\n");
		if(s1[i]>s2[i])return !printf(">\n");
	}
	if(n==m)printf("=\n");
	else if(n<m)printf("<\n");
	else printf(">\n");
	return 0;
} 
