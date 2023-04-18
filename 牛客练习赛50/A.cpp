#include<bits/stdc++.h>
using namespace std;
bool usd[27];
int main()
{
	int n;
	scanf("%d",&n);
	char las='#'; 
	while(n--)
	{
		char t;
		cin>>t;
		if(t!=las&&usd[t-'a'])return !printf("NO\n");
		usd[t-'a']=true;
		las=t;
	}
	printf("YES\n");
	return 0;
}
