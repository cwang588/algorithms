#include<bits/stdc++.h>
using namespace std;
char a[100005];
int pos[100005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,' ',sizeof(a));
		cin>>(a+1);
		int n=strlen(a+1);
		int cnt=0;
		for(int i=1;i<=n;++i)
			if(a[i]=='1')
				pos[++cnt]=i;
		if(cnt%2)
			printf("WIN\n");
		else
			printf("LOSE\n");
	}
	return 0;
} 
