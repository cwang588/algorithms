#include<bits/stdc++.h>
using namespace std;
string s[100005];
int main()
{
	int n;
	scanf("%d",&n);
	int num=0;
	for(int i=1;i<=n;++i)
		cin>>s[i];
	int now=1;
	for(int i=n;i>=1;--i)
	{
		int nxt;
		if(s[i]=="LIE")nxt=-1;
		else nxt=1;
		now*=nxt;
	}
	if(now==1)printf("TRUTH\n");
	else printf("LIE\n");
	return 0;
}
