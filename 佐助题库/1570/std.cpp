#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("15705.in","r",stdin);
	//freopen("15705.out","w",stdout);
	double k;
	string s1,s2;
	cin>>k>>s1>>s2;
	int n=s1.length(),cnt=0;
	for(int i=0;i<n;++i)if(s1[i]==s2[i])++cnt;
	double tmp=(double)cnt/n;
	if(tmp>=k)printf("yes\n");
	else printf("no\n");
	return 0;
}
